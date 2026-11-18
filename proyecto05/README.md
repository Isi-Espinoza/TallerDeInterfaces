# Proyecto 05 | Huellas Sonoras: Sonificación de Imágenes y Plataforma Interactiva

Este repositorio contiene la documentación y el desarrollo completo del proyecto 5 para el **Taller de Interfaces**.

## Descripción del Proyecto

El proyecto **"Huellas Sonoras"** es una aplicación web interactiva de sonificación de imágenes que transforma los datos visuales de cualquier fotografía o pintura en música sintetizada en tiempo real. A través de una interfaz minimalista con estética neón, el usuario explora una imagen oscurecida utilizando una "linterna focal" controlada por el cursor. A medida que el foco ilumina distintas áreas del lienzo, el motor de audio analiza los píxeles y traduce sus propiedades visuales en sonido:

* **Luminancia a Frecuencia (Notas):** El nivel de brillo determina la altura musical; las zonas oscuras o en sombra emiten notas graves, mientras que los puntos claros y luminosos generan notas agudas.
* **Saturación a Timbre (Textura):** La intensidad del color controla los filtros de audio, logrando que los tonos vivos suenen brillantes y resonantes, y los colores apagados produzcan texturas más suaves.
* **Síntesis en Tiempo Real:** Impulsado por la *Web Audio API*, permite interpretar las imágenes utilizando distintos timbres instrumentales (Piano Acústico, Marimba Cálida y Pad Ambiental).
* **Registro y Exportación:** El sistema permite grabar el recorrido del usuario sobre la obra, reproducir la secuencia de luz y sonido, y exportar la composición resultante directamente como un archivo de audio en formato `.wav`.

En esencia, el proyecto convierte la exploración visual en una experiencia sinestésica, permitiendo que cada obra de arte y cada trazo del usuario generen una firma acústica única e irrepetible.

* **Justificación Pedagógica:**

El proyecto promueve el desarrollo de la percepción sinestésica y la traducción intermodal, conectando la expresión visual con el diseño sonoro computacional. A través de la exploración activa con una interfaz lumínica, el estudiante comprende de manera práctica cómo los algoritmos de programación en la web pueden interpretar variables estéticas (luminancia y saturación) y convertirlas en parámetros musicales en tiempo real, vinculando la informática con la creación artística interactiva.

## Estructura del Repositorio

* **`websonificacion/`** : Contiene la interfaz web principal (`index.html`) y el archivo de imagen de soporte (`fondo.jpeg`) optimizados para la experiencia interactiva.
* **`registresonificacion/`** : Almacena el archivo de audio resultante en formato WAV (`huella_sonora_...wav`) obtenido a partir del proceso de registro de la sonificación visual.

## Tecnologías y Recursos

* **Motor de Audio y Lógica:** JavaScript, HTML5 y *Web Audio API* para el procesamiento y síntesis sonora en tiempo real.
* **Estrategia de Mapeo Visual:** Traducción paramétrica basada en luminancia (frecuencia) y saturación (timbre).
* **Formatos y Soportes:** Archivos de imagen estática (`.jpeg`) y registros de audio exportados en alta calidad (`.wav`).
