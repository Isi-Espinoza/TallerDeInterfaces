# Proyecto 04 | Sonificación de Datos — Tenis Profesional Chileno

Este repositorio contiene la documentación y el desarrollo completo del proyecto 4 para el **Taller de Interfaces**.

## Descripción del Proyecto

**"Generación de Arcilla"** es una pieza de sonificación que traduce la historia y los hitos del tenis nacional en una composición musical. La base de datos utilizada (`basedatostenis.csv`) reúne información de 29 figuras históricas de la disciplina, representando sus mayores logros deportivos a través de tres variables clave:

* **Mejor Ranking Individual:** Está representada por el **Piano con escala invertida**, generando las notas más agudas cuando un tenista alcanza la cima del circuito mundial.
* **Mejor Ranking en Dobles:** Es interpretada por el **Contrabajo**, dando un registro grave que resalta a las grandes figuras en esta modalidad.
* **Año del Mejor Ranking:** Se representa a través del **Violín**, creando una melodía que marca la evolución cronológica y el relevo generacional de la historia deportiva del país (1937–2025).

## Estructura del Repositorio

* **`basededatos/`** : Contiene el dataset original en formato CSV (`basedatostenis.csv`) con las métricas del tenis profesional chileno.
* **`cancion/`** : Almacena el archivo de audio resultante (`canciontenis.mp3`) exportado desde la sonificación.
* **`intención/`** : Contiene el archivo de texto con el concepto y la justificación metodológica de la obra ("Generación de Arcilla").

## Tecnologías y Recursos

* **Herramientas de Sonificación:** TwoTone para la traducción paramétrica de variables cuantitativas y categóricas a MIDI.
* **Mapeo Instrumental:** Piano, Contrabajo y Violín orientados a la lectura cronológica y de rendimiento deportivo.
* **Formatos y Lenguajes:** Procesamiento de datos estructurados (CSV) y exportación de archivos de audio optimizados (`.mp3`).
