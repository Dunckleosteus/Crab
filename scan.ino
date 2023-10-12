#include <Servo.h>
#include <Servo.h>

Servo s1; 
Servo s2;
const int trigger = 8;
const int echo = 7;

void setup() {
  Serial.begin(9600);
  s1.attach(10);
  s2.attach(9);
}

void loop() {
  long duration;
  int width = 90;
  int height = 90; 
  int step = 5;
  int measures = width*height;
  for (int i=0; i<=measures; i+=step){
    Serial.print(i%width);
    Serial.print(";");
    Serial.print(i/width);
    Serial.print(";");
    Serial.print(distance(echo, trigger));
    Serial.println();
    if (i%width == 0){
      s1.write(i/width);
      s2.write(i%width);
      delay(500);
    }else{
      s2.write(i%width);
      delay(100);
    }
  }
  return 0;
}

long distance (int echo, int trigger){
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  pinMode(echo, INPUT);
  int duration = pulseIn(echo, HIGH);
  return duration / 29 / 2;
}
