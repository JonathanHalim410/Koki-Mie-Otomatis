/*Created By:
 * Amos Jireh Hartono
 * Jonathan Halim
 */

#include <Servo.h>

int piezoPin=5;
int servoPin=6;
int pinA=7;
int pinB=8;
int pwm=9;
int pushbutton1=11;
int pushbutton2=12;
int potensio=0;
Servo servo;
int angle = 0;
int simpan_data=0;
int val=0;
int val1=0;

void setup()
{
  pinMode(piezoPin,OUTPUT);
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(servoPin,OUTPUT);
  pinMode(pushbutton1,INPUT);
  pinMode(pushbutton2,INPUT);
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(angle);
}

void loop()
{
  val= digitalRead(pushbutton1);// pushbutton rebus 10 detik
  if (val == HIGH){
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,LOW);
    simpan_data=analogRead(potensio);
    analogWrite(pwm,simpan_data);
    delay(10000);// waktu turun
    digitalWrite(pinA,LOW);
    delay(10000);//waktu rebus
    digitalWrite(pinB,HIGH);
    delay(10000);//waktu naik
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
    digitalWrite(piezoPin,HIGH);
    delay(2000);
    servo.write(135);
    delay(5000);
    servo.write(0);
    delay(3000);
    digitalWrite(piezoPin,LOW);
    delay(1000);}
  
  val1= digitalRead(pushbutton2);// pushbutton rebus 15 detik
  if (val1 == HIGH){
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,LOW);
    simpan_data=analogRead(potensio);
    analogWrite(pwm,simpan_data);
    delay(10000);// waktu turun
    digitalWrite(pinA,LOW);
    delay(15000);//waktu rebus
    digitalWrite(pinB,HIGH);
    delay(10000);//waktu naik
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
    digitalWrite(piezoPin,HIGH);
    delay(2000);
    servo.write(135);
    delay(5000);
    servo.write(0);
    delay(3000);
    digitalWrite(piezoPin,LOW);
    delay(1000);}
}
