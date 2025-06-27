#include <Servo.h>
#include <MeMegaPi.h>

MeMegaPiDCMotor motor(PORT1B);
Servo sg90;

void setup() {

  // Mover motor DC
  motor.run(100);
  delay(5000);
  motor.run(0);

  
  sg90.attach(62);  // A7 = D61

    sg90.write(0);    // Ir a 0 grados
  delay(1000);

  sg90.write(90);   // Ir a 90 grados
  delay(1000);

  sg90.write(180);  // Ir a 180 grados
  delay(1000);

  
}

void loop() {
  

}
