#include <Servo.h>

Servo s1, s2;

void setup() {
  s1.attach(9);
  s2.attach(8); // pino de sinal do servo
}

void loop() {
  for (int angulo = 0; angulo <= 75; angulo++) {
    s2.write(angulo);
    delay(15);
  }

  delay(1000);

  // Volta de 180° até 0°
  for (int angulo = 75; angulo >= 0; angulo--) {
    s2.write(angulo);
    delay(15);
  }

  
  for (int angulo = 50; angulo <= 100; angulo++) {
    s1.write(angulo);
    delay(15);
  }

  delay(1000);


  // Vai de 0° até 180°
  for (int angulo = 100; angulo >= 50; angulo--) {
    s1.write(angulo);
    delay(15);
  }
  // Volta de 180° até 0°
 
}