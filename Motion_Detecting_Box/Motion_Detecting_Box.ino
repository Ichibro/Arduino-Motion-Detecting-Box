#include <Servo.h>
Servo Xservo;
int const trigPin = 6;
int const echoPin = 5;
int Xpin=A0;
int Ypin=A1;
int XSpin=10;
int Spin=2;
int Xval;
int Yval;
int Sval;
int dt=200;
int WVx;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(XSpin,OUTPUT);
pinMode(Xpin,INPUT);
pinMode(Ypin,INPUT);
pinMode(Spin,INPUT);
Xservo.attach(XSpin);
digitalWrite(Spin,HIGH);

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
}

void loop() {

int duration, distance;
digitalWrite(trigPin, HIGH); 
delay(1);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance <= 50 && distance >= 0) {
  Xservo.write(10);
    delay(1000);
} else {
  
  Xservo.write(80);
}

delay(60);
Serial.print("X Value = ");
Serial.print(Xval);
Serial.print(" Y Value = ");
Serial.print(Yval);
Serial.print(" Switch State is ");
Serial.println(Sval);
}
