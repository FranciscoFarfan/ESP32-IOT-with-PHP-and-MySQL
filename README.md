# ESP32-IOT-with-PHP-and-MySQL

**Abandonado (Concepto)** | **Sin uso de IA** | **Personal**

## Descripción

Un proyecto conceptual diseñado como un "sistema operativo" o plataforma de gestión dinámica para microcontroladores ESP32 utilizando el entorno de Arduino. El propósito principal del proyecto era establecer una conexión entre el ESP32 y una aplicación web backend en PHP para controlar el hardware remotamente. A diferencia del flujo de trabajo tradicional en IoT, donde la lógica se programa en el dispositivo, este proyecto permitía que la funcionalidad completa (gestión de sensores, actuadores, mediciones y reglas) se estableciera y modificara desde la página web. De esta manera, el ESP32 contaba con un firmware genérico precargado y no era necesario volver a escribir, compilar o flashear código constantemente ante cada cambio de requerimientos. El proyecto se detuvo (abandonado) al concluir que actualmente existen soluciones de orquestación más robustas orientadas a contenedores (como Docker) que resuelven problemas similares a mayor escala.

## Características

### Funcionalidades

- **Configuración Dinámica de Hardware:** Asignación y cambio del comportamiento de los pines del ESP32 de forma remota sin tener que reflashear el microcontrolador.
- **Comunicación Bidireccional HTTP:** Envío de telemetría y recepción de instrucciones a través de peticiones `POST` a un servidor.
- **Gestión Centralizada IoT:** Control de sensores y actuadores directamente desde una interfaz y backend web.
- **Persistencia de Datos:** Almacenamiento y registro del estado de los dispositivos y mediciones a lo largo del tiempo.

### Tecnologías usadas

- **C++ / Arduino IDE:** Para la programación del firmware genérico que corre en el ESP32.
- **PHP:** Para el procesamiento del lado del servidor (recepción de datos `Receptor.php` y envío de comandos).
- **MySQL:** Como base de datos relacional para guardar la configuración de los pines y las lecturas de los sensores.
- **ESP32:** Como hardware principal e interfaz física (actuadores/sensores).

### Innovaciones

- **Abstracción del Firmware:** Trasladar la lógica de negocio y las decisiones del dispositivo físico (Edge) hacia el servidor (Nube/On-Premise), flexibilizando las pruebas y el desarrollo.
- **Despliegue Rápido (Plug & Play web):** Reducción de tiempos de desarrollo al evitar el ciclo de "modificar código - compilar - conectar cable - flashear" para cada ajuste en los proyectos.
