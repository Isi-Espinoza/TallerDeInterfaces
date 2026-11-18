# Proyecto 07 | Consola y Sintetizador Interactivo

Este repositorio contiene la documentación y el desarrollo completo del proyecto 7 para el **Taller de Interfaces**.

## Descripción del Proyecto

El proyecto **"Consola - V02"** es un sistema interactivo físico y digital controlado por voz. Integra una interfaz tangible que combina controles modulares (como botones arcade, un fader deslizante y potenciómetros) con un control dinámico guiado por voz a través de la *Web Speech API*.

Permite la lectura bidireccional mediante *Web Serial API* para modular la intensidad, los colores y las animaciones de un anillo de LEDs NeoPixel, logrando una sincronización fluida en tiempo real entre la consola física y un tablero digital.

## Estructura del Repositorio

* **`códigosconsola/`** : Archivos de código fuente utilizados para la programación de la consola (`códigosconsola.ino`).
* **`interfazweb/`** : Archivos de la plataforma digital (`index.html`, estilos y lógica de comunicación serial/voz).
* **`modelado3d/`** : Piezas y carcasas diseñadas para la estructura física de la consola.
* **`fotos/`** : Registro fotográfico y esquemas de conexión del prototipo ensamblado.

## Tecnologías y Recursos

* **Hardware y Microcontroladores:** Placa Arduino, anillo de LEDs NeoPixel, botones arcade, fader deslizante y potenciómetros.
* **Desarrollo Web y APIs:** HTML5, CSS3, JavaScript, *Web Serial API* (comunicación bidireccional con Arduino) y *Web Speech API* (reconocimiento de comandos de voz desde el micrófono del PC).
* **Modelado y Fabricación:** Diseño de piezas estructurales en 3D para el ensamblaje físico de los controles.
