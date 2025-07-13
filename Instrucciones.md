 INSTRUCCIONES DE FUNCIONAMIENTO
 1. Conexión del hardware
El pin GPIO 2 (D2) del ESP32 genera la señal PWM.

Podés medirlo con un osciloscopio para observar la onda.

Asegurate de usar un cable USB de datos y que tu ESP32 esté correctamente alimentado.

2. Conexión Bluetooth
Al encenderse el ESP32, se anuncia como dispositivo Bluetooth llamado:

ESP32_PWM
Usá una app como Serial Bluetooth Terminal (Android) o cualquier terminal Bluetooth para conectarte desde tu celular o PC.

Una vez conectado, podés enviarle comandos por Bluetooth.

 3. Comandos disponibles
Escribí los siguientes comandos por Bluetooth (uno por línea, terminados en Enter):

Comando	Acción
ON	Activa la señal PWM con la frecuencia y duty actuales
OFF	Desactiva la señal PWM (duty = 0)
FREQ=XXXX	Cambia la frecuencia del PWM. Ej: FREQ=1000 (Hz)
DUTY=XX	Cambia el duty cycle (%). Ej: DUTY=50 (de 0 a 100%)
