# Proyecto 04 | Sonificación de Datos — Tenis Profesional Chileno

Este repositorio contiene la documentación y el desarrollo completo del proyecto 4 para el **Taller de Interfaces**.

## Descripción del Proyecto

El proyecto **"Generación de Arcilla"** es una pieza de sonificación que traduce la historia y los hitos del tenis nacional en una composición musical. La base de datos utilizada (`basedatostenis.csv`) reúne información de 29 figuras históricas de la disciplina, representando sus mayores logros deportivos a través de tres variables clave.

## Matriz y Tabla de Mapeo de Datos

| Variable <br> (`basedatostenis.csv`) | Instrumento / <br> Parámetro Musical | Justificación |
| :--- | :--- | :--- |
| **Mejor Ranking Individual** | **Piano** / Escala invertida | Las notas más agudas se generan cuando el tenista alcanza la cima (puestos más altos) del circuito mundial. |
| **Mejor Ranking en Dobles** | **Contrabajo** / Registro grave | Proporciona una base sólida y un registro grave distintivo para destacar a las figuras en esta modalidad. |
| **Año del Mejor Ranking** | **Violín** / Línea melódica | Guía el recorrido cronológico de los datos a través del tiempo (1937–2025), marcando la evolución y el relevo generacional. |

## Estructura del Repositorio

* **`basededatos/`** : Contiene el dataset original en formato CSV (`basedatostenis.csv`) con las métricas del tenis profesional chileno.
* **`cancion/`** : Almacena el archivo de audio resultante (`canciontenis.mp3`) exportado desde la sonificación.
* **`intención/`** : Contiene el registro escrito con el concepto y la justificación metodológica de la obra ("Generación de Arcilla").

## Tecnologías y Recursos

* **Herramientas de Sonificación:** TwoTone para la traducción paramétrica de variables cuantitativas y categóricas a MIDI.
* **Mapeo Instrumental:** Piano, Contrabajo y Violín orientados a la lectura analítica y cronológica del deporte.
* **Formatos y Lenguajes:** Procesamiento de datos estructurados (CSV) y exportación de archivos de audio optimizados (`.mp3`).
