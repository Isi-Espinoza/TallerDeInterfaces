# Proyecto 08 | Módulo 01 — Planeta Orbital (Interacción Natural y Visión por Computadora)

Este repositorio contiene la documentación y el desarrollo del Módulo 01 para el **Taller de Interfaces**.

## Descripción del Proyecto

"Planeta Orbital" es un prototipo interactivo en tiempo real para la web en el que el movimiento corporal y gestual de la mano controla un sistema planetario compuesto por un planeta central, tres anillos orbitales y partículas de polvo orbital, con alternativa de **Modo Ratón**.

* **Mecánica de interacción:** El usuario inclina el sistema planetario en el espacio 3D moviendo la mano o el cursor, y utiliza el dedo índice como puntero para activar modos o capas mediante pellizco o pausa sobre el elemento (*dwell click*), además de pellizcar sobre controles deslizantes para ajustar parámetros en tiempo real.
* **Funcionamiento y controles:** Permite regular *Velocidad Anillos*, *Separación Orbital*, *Inclinación Base* y *Zoom Imagen Planeta*, alternar la capa *Polvo Orbital* y cambiar entre los modos *Armonía*, *Contragiro*, *Pulso* e *Impulso*, visualizando la telemetría del gesto y los 21 puntos de la mano.
* **Propósito y justificación:** Explorar una interfaz natural de usuario (NUI) basada en visión por computadora en el navegador que facilite la manipulación directa y fluida de una escena 3D sin depender exclusivamente de controles tradicionales.

## Instrucciones de Uso

1. **Abrir el prototipo:** Accede a la aplicación web desplegada o abre la interfaz contenida en `webinteractiva/` en un navegador moderno.
2. **Seleccionar modo de control:** En el modal inicial, elige **Iniciar Cámara** (otorgando permisos de cámara web para el seguimiento con MediaPipe Hands) o selecciona **Modo Ratón** si prefieres operar con el cursor.
3. **Manipular la escena 3D:** Mueve la mano frente a la cámara (o desplaza el ratón) para inclinar el sistema planetario en el espacio 3D.
4. **Interactuar con la interfaz:** Apunta con el dedo índice (o cursor) sobre botones o controles y activa mediante **pellizco**, **pausa sobre el elemento (*dwell click*)** o clic; para los sliders, pellizca y desliza para modificar *Velocidad Anillos*, *Separación Orbital*, *Inclinación Base* y *Zoom Imagen Planeta*, alternar *Polvo Orbital* o cambiar entre los modos *Armonía*, *Contragiro*, *Pulso* e *Impulso*.

## Estructura del Repositorio

* `webinteractiva/` : Contiene la aplicación web interactiva (`index.html`), su interfaz HUD, el modal de permisos/modo de control y la lógica de escena 3D y gestos.
* `registrovideo/` : Carpeta que almacena el registro audiovisual de demostración (`registrovideomodulo1.mp4`) en formato horizontal 16:9, mostrando el funcionamiento del prototipo y la interacción en tiempo real.

## Tecnologías y Recursos

* **Visión por Computadora e Interacción:** MediaPipe Hands para la detección y seguimiento en tiempo real de los 21 landmarks de la mano desde la cámara web, con respaldo de interacción por ratón.
* **Gráficos 3D y Entorno Web:** HTML5, CSS3, JavaScript y Three.js para el renderizado del planeta, los tres anillos, las partículas y la telemetría visual en el navegador.
* **Registro Audiovisual y Despliegue:** Edición de video en Clipchamp (exportación en 16:9 / MP4) y publicación en repositorio Git (con despliegue web verificado en navegador).
