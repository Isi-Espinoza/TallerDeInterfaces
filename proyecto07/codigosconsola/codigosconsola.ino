#include <Adafruit_NeoPixel.h>

// ==========================================
// 1. CONFIGURACIÓN DE PINES Y HARDWARE
// ==========================================
#define PIN_NEOPIXEL 12  
#define PIN_ARCADE   10  
#define PIN_RESET    8   
#define NUMPIXELS 16    

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

const int pinFader = A0;    
const int pinPot1  = A2;    
const int pinPot2  = A4;    

uint16_t baseHue = 0;            
int estadoOn = 0;                
int estadoOnAnterior = 0;        
bool modoAnimacionReset = false; 

int valFaderFiltrado = 0;
int valPot1Filtrado = 0;
int valPot2Filtrado = 0;

unsigned long ultimoDebounceArcade = 0;
unsigned long ultimoDebounceReset = 0;
int ultimoEstadoArcade = HIGH;
int ultimoEstadoReset = HIGH;

unsigned long ultimoTiempoSerial = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_ARCADE, INPUT_PULLUP);
  pinMode(PIN_RESET, INPUT_PULLUP);
  
  pixels.begin();
  pixels.show();
  
  valFaderFiltrado = 1023 - constrain(analogRead(pinFader), 0, 1023);
  valPot1Filtrado  = analogRead(pinPot1);
  valPot2Filtrado  = analogRead(pinPot2);
}

void loop() {
  // Invertimos la lectura física del fader (soldado al revés) para que 0 sea abajo y 1023 arriba
  int lecturaFaderRaw = 1023 - constrain(analogRead(pinFader), 0, 1023);
  int lecturaPot1Raw  = constrain(analogRead(pinPot1), 0, 1023);
  int lecturaPot2Raw  = constrain(analogRead(pinPot2), 0, 1023);

  if (abs(lecturaFaderRaw - valFaderFiltrado) > 2) valFaderFiltrado = lecturaFaderRaw;
  if (abs(lecturaPot1Raw - valPot1Filtrado) > 2)   valPot1Filtrado   = lecturaPot1Raw;
  if (abs(lecturaPot2Raw - valPot2Filtrado) > 2)   valPot2Filtrado   = lecturaPot2Raw;

  // Botón Arcade (ON / OFF)
  int lecturaArcade = digitalRead(PIN_ARCADE);
  if (lecturaArcade == LOW && ultimoEstadoArcade == HIGH && (millis() - ultimoDebounceArcade > 250)) {
    estadoOn = (estadoOn == 1) ? 0 : 1;
    modoAnimacionReset = false;
    ultimoDebounceArcade = millis();
  }
  ultimoEstadoArcade = lecturaArcade;

  // Botón Reset
  int lecturaReset = digitalRead(PIN_RESET);
  if (lecturaReset == LOW && ultimoEstadoReset == HIGH && (millis() - ultimoDebounceReset > 250)) {
    modoAnimacionReset = !modoAnimacionReset;
    ultimoDebounceReset = millis();
  }
  ultimoEstadoReset = lecturaReset;

  // Comandos Seriales (Voz)
  if (Serial.available() > 0) {
    char comando = Serial.read();
    modoAnimacionReset = false; 
    
    if      (comando == 'R') { baseHue = 0;     estadoOn = 1; } 
    else if (comando == 'O') { baseHue = 4000;   estadoOn = 1; } 
    else if (comando == 'Y') { baseHue = 10922;  estadoOn = 1; } 
    else if (comando == 'V') { baseHue = 21845;  estadoOn = 1; } 
    else if (comando == 'C') { baseHue = 32768;  estadoOn = 1; } 
    else if (comando == 'A') { baseHue = 43690;  estadoOn = 1; } 
    else if (comando == 'M') { baseHue = 54600;  estadoOn = 1; } 
    else if (comando == '0') { estadoOn = 0; } 
  }

  // Animación de encendido
  if (estadoOn == 1 && estadoOnAnterior == 0) {
    int brilloBoot = map(valPot2Filtrado, 0, 1023, 30, 200);
    int inicioArriba = (NUMPIXELS / 4) + 2; 
    
    for (int paso = 0; paso <= NUMPIXELS; paso++) {
      int i = (inicioArriba + paso) % NUMPIXELS;
      pixels.clear();
      
      uint16_t hueBoot = (paso * 65535L) / NUMPIXELS;
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(hueBoot, 255, brilloBoot))); 
      
      int estela = (i - 1 + NUMPIXELS) % NUMPIXELS;
      uint16_t hueEstela = ((paso - 1) * 65535L) / NUMPIXELS;
      pixels.setPixelColor(estela, pixels.gamma32(pixels.ColorHSV(hueEstela, 255, brilloBoot / 4)));
      
      pixels.show();
      delay(30);
    }
  }
  estadoOnAnterior = estadoOn;

  // Cálculo de color y parpadeo
  int brilloVal = map(valPot2Filtrado, 0, 1023, 20, 255);
  uint8_t saturacionTono = map(valPot1Filtrado, 0, 1023, 40, 255);

  uint32_t colorBaseRgb = pixels.gamma32(pixels.ColorHSV(baseHue, saturacionTono, brilloVal));

  byte rBase = (colorBaseRgb >> 16) & 0xFF;
  byte gBase = (colorBaseRgb >> 8) & 0xFF;
  byte bBase = colorBaseRgb & 0xFF;

  float factorBlink = 1.0;
  if (!modoAnimacionReset) {
    int faderSeguro = constrain(valFaderFiltrado, 0, 650); 
    
    // Normalización directa: 0 = Fader abajo (Estático) | 650 = Fader arriba (Parpadeo Máximo)
    float normFader = (float)faderSeguro / 650.0; 
    
    float velocidadPulso = map(faderSeguro, 0, 650, 10, 32);
    float onda = (sin(millis() / (15.0 / (velocidadPulso / 10.0))) + 1.0) / 2.0; 
    
    float profundidadEfecto = normFader * 0.40; 
    factorBlink = 1.0 - (profundidadEfecto * (1.0 - onda));
  }

  int rFinal = (int)(rBase * factorBlink);
  int gFinal = (int)(gBase * factorBlink);
  int bFinal = (int)(bBase * factorBlink);

  if (rBase == 0 && gBase > 0) gFinal = max(gFinal, 15);
  if (bBase > 0 && rBase > 0)  bFinal = max(bFinal, 15);

  // Actualización Física de los NeoPixels
  if (estadoOn == 0) {
    for(int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  } else if (modoAnimacionReset) {
    long hueWeb = (millis() / 1) & 65535;
    uint32_t colorUnicoFisico = pixels.gamma32(pixels.ColorHSV(hueWeb, 255, brilloVal));
    
    for(int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, colorUnicoFisico);
    }
  } else {
    for(int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(rFinal, gFinal, bFinal));
    }
  }
  pixels.show();

  // ==========================================
  // 7. TELEMETRÍA SERIAL (8 VALORES)
  // ==========================================
  if (millis() - ultimoTiempoSerial >= 50) {
    ultimoTiempoSerial = millis();

    int rWeb = rFinal;
    int gWeb = gFinal;
    int bWeb = bFinal;

    if (modoAnimacionReset) {
      long hueWeb = (millis() / 1) & 65535;
      uint32_t colorWebRgb = pixels.gamma32(pixels.ColorHSV(hueWeb, 255, brilloVal));
      rWeb = (colorWebRgb >> 16) & 0xFF;
      gWeb = (colorWebRgb >> 8) & 0xFF;
      bWeb = colorWebRgb & 0xFF;
    }

    Serial.print("[");
    Serial.print(valFaderFiltrado); Serial.print(",");
    Serial.print(valPot1Filtrado);  Serial.print(",");
    Serial.print(valPot2Filtrado);  Serial.print(",");
    Serial.print(estadoOn);         Serial.print(",");
    Serial.print(estadoOn == 0 ? 0 : rWeb); Serial.print(",");
    Serial.print(estadoOn == 0 ? 0 : gWeb); Serial.print(",");
    Serial.print(estadoOn == 0 ? 0 : bWeb); Serial.print(",");
    Serial.print(modoAnimacionReset ? 1 : 0); 
    Serial.println("]");
  }
}