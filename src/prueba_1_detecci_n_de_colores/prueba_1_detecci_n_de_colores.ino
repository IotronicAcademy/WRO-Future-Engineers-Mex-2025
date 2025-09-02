// CODIGO PARA MEGAPI - v9.0 CONTROL DE SERVO/MOTOR + MeRGBLineFollower
#include <Arduino.h>
#include <Wire.h>
#include <MeMegaPi.h>
#include <MeRGBLineFollower.h>

// --- Definiciones de hardware ---
MeMegaPiDCMotor motor(PORT1A);
Servo direccion;
const int SERVO_PIN = 62;
MeRGBLineFollower lineFollower(PORT_9, 0x09);

const int ANGULO_CENTRO = 80;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Inicializar line follower
  lineFollower.begin();
  lineFollower.setKp(0.3);
  
  // Inicializar servo
  direccion.attach(SERVO_PIN);
  direccion.write(ANGULO_CENTRO);

  // Motor detenido al inicio
  motor.run(0);
  
  Serial.println("MegaPi v9.0 listo: Servo, Motor y MeRGBLineFollower activos.");
}

void loop() {
  // --- Leer line follower ---
  lineFollower.loop();
  int state  = lineFollower.getPositionState();
  int offset = lineFollower.getPositionOffset();

  // --- Enviar datos al serial para Raspberry Pi ---
  Serial.print("State: "); Serial.print(state);
  Serial.print(" | Offset: "); Serial.println(offset);

  // --- Ejecutar comandos recibidos de la Pi ---
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando.startsWith("s:")) {          // Servo
      int angulo = comando.substring(2).toInt();
      direccion.write(angulo);
    } 
    else if (comando == "p") {               // Parar motor
      motor.run(0);
    } 
    else if (comando.startsWith("d:")) {     // Avanzar motor
      int velocidad = comando.substring(2).toInt();
      if (velocidad > 255) velocidad = 255;
      if (velocidad < 0) velocidad = 0;
      motor.run(velocidad);
    } 
    else if (comando.startsWith("r:")) {     // Retroceder motor
      int velocidad = comando.substring(2).toInt();
      if (velocidad > 255) velocidad = 255;
      if (velocidad < 0) velocidad = 0;
      motor.run(-velocidad);
    }
  }

  delay(10); // Pequeño delay para no saturar serial
}
