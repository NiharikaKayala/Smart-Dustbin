#include <Servo.h>

int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(6);
  myServo.write(0);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance <= 15 && distance > 0)
  {
    myServo.write(90);
    delay(3000);
    myServo.write(0);
  }

  delay(200);
}