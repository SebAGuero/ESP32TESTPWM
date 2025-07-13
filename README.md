#Control de Señal PWM por Bluetooth con ESP32#

Este proyecto implementa un sistema de generación de señal PWM controlado vía Bluetooth utilizando un ESP32. Está orientado a aplicaciones didácticas, de prototipado rápido o control de actuadores simples, donde se requiere modificar la frecuencia y el ciclo de trabajo (duty cycle) de una señal en tiempo real.

Funcionalidad principal
Permite activar y desactivar una señal PWM en el pin GPIO 2.

Control total mediante comandos enviados por Bluetooth desde una app serial (como Serial Bluetooth Terminal en Android).

Modificación en tiempo real de:

Frecuencia PWM (1 Hz a 40 kHz).

Duty cycle (0 a 100%).

Comandos Bluetooth disponibles
Comando	Descripción
ON	Activa la señal PWM en el pin 2
OFF	Desactiva la señal PWM
FREQ=XXXX	Cambia la frecuencia (ej. FREQ=1000)
DUTY=YY	Cambia el duty cycle en % (ej. DUTY=50)

La frecuencia permitida va de 1 a 40.000 Hz.
El duty cycle permitido va de 0% a 100%.

Requisitos
- Placa ESP32
- IDE de Arduino con soporte para ESP32 (board manager)
- Biblioteca BluetoothSerial
- App Bluetooth Serial (como Serial Bluetooth Terminal)

Configuración por defecto
Pin de salida PWM: GPIO 2

Canal PWM: 0
Frecuencia inicial: 1000 Hz
Resolución PWM: 8 bits (0 a 255)
Duty cycle inicial: 50%

Aplicaciones posibles
- Generación de señales PWM para controlar LEDs, motores, drivers externos, etc.
- Uso en laboratorios de electrónica para enseñar principios de modulación por ancho de pulso.
- Interfaces simples para sistemas embebidos controlados remotamente.
