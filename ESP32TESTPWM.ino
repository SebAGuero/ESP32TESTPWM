#include <BluetoothSerial.h>

BluetoothSerial BT;

const int pwmPin = 2;
const int pwmChannel = 0;
int pwmFreq = 1000;         // Frecuencia en Hz
int pwmResolution = 8;      // Resolución en bits
int pwmDuty = 128;          // 50% por defecto (de 0 a 255)
bool waveOn = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando...");

  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(pwmPin, pwmChannel);
  ledcWrite(pwmChannel, 0); // Señal apagada

  if (!BT.begin("ESP32_PWM")) 
  {
    Serial.println("Error iniciando Bluetooth");
  } else {
    Serial.println("Bluetooth iniciado. Nombre: ESP32_TEST");
  }
}

void loop() {
  if (BT.available()) {
    String cmd = BT.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();

    Serial.print("Comando recibido: ");
    Serial.println(cmd);

    if (cmd == "ON") {
      waveOn = true;
      ledcWrite(pwmChannel, pwmDuty);
      Serial.println("PWM ACTIVADO");
    } 
    else if (cmd == "OFF") {
      waveOn = false;
      ledcWrite(pwmChannel, 0);
      Serial.println("PWM DESACTIVADO");
    } 
    else if (cmd.startsWith("FREQ=")) {
      int newFreq = cmd.substring(5).toInt();
      if (newFreq >= 1 && newFreq <= 40000) {
        pwmFreq = newFreq;
        ledcSetup(pwmChannel, pwmFreq, pwmResolution);
        if (waveOn) ledcWrite(pwmChannel, pwmDuty);
        Serial.print("Frecuencia actualizada: ");
        Serial.println(pwmFreq);
      } else {
        Serial.println("⚠️ Frecuencia fuera de rango (1-40000 Hz)");
      }
    } 
    else if (cmd.startsWith("DUTY=")) {
      int dutyPercent = cmd.substring(5).toInt();
      if (dutyPercent >= 0 && dutyPercent <= 100) {
        pwmDuty = map(dutyPercent, 0, 100, 0, 255);
        if (waveOn) ledcWrite(pwmChannel, pwmDuty);
        Serial.print("Duty cycle actualizado: ");
        Serial.print(dutyPercent);
        Serial.println("%");
      } else {
        Serial.println("⚠️ Duty fuera de rango (0-100%)");
      }
    } 
    else {
      Serial.println("Comando no reconocido");
    }
  }

  // Mostrar estado actual cada 2 segundos
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 2000) {
    lastPrint = millis();
    Serial.print("Estado: ");
    Serial.print(waveOn ? "ON" : "OFF");
    Serial.print(" | Frecuencia: ");
    Serial.print(pwmFreq);
    Serial.print(" Hz | Duty: ");
    Serial.print(map(pwmDuty, 0, 255, 0, 100));
    Serial.println(" %");
  }
}

