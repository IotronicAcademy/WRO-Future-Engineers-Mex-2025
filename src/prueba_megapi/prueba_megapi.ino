#include <MeMegaPi.h>

MeMegaPiDCMotor motor(PORT1B);

void setup() {
  Serial.begin(115200);

}

void loop() {
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "PING") {
      Serial.println("si");

      // Mover motor DC
      motor.run(100);
      delay(5000);
      motor.run(0);

    }
  }
}
