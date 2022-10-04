#include<Servo.h>
Servo myservo01;
Servo myservo02;
const int trigPin = 2; // Trigger Pin
const int echoPin = 4; // Echo Pin
long duration, cm;
int dis(){
  
     pinMode(trigPin, OUTPUT);
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     pinMode(echoPin, INPUT);
     duration = pulseIn(echoPin, HIGH);
     cm = duration / 29 / 2;
     return cm; //  define and calculate distance
}

void setup() {
   myservo02.attach(12);
   myservo01.attach(9);
   Serial.begin(9600); 
   pinMode(5,INPUT_PULLUP);
   pinMode(6,INPUT_PULLUP);
}

void loop() {
  int move1 = 1600;
  int move2 = 1470;
  int stp = 1500;
  int left = 1600;
  int right = 1400; 


  int val1 = digitalRead(5);
  int val2 = digitalRead(6);

  dis();

  Serial.println(val1);
  Serial.println(val2);

if (val1==0&val2==0){
  
  myservo01.writeMicroseconds(move1);
  myservo02.writeMicroseconds(move2);  
  Serial.println("move");
  delay(10);
}
if (val1==1&val2==0){
 
  
  myservo01.writeMicroseconds(1450);
  myservo02.writeMicroseconds(right);
  Serial.println("right");
  delay(10);
  
}
if (val2==1&val1==0){
  
  myservo01.writeMicroseconds(left);
  myservo02.writeMicroseconds(1550);
  Serial.println("left");
  delay(10);
}
if (val1==1&val2==1){
  myservo01.writeMicroseconds(left);
  myservo02.writeMicroseconds(1550);
  delay(10);
}
if (cm<=10){
    
    myservo01.writeMicroseconds(1700);
    myservo02.writeMicroseconds(1700);
    delay(600);
    myservo01.writeMicroseconds(1600);
    myservo02.writeMicroseconds(1470);
    delay(1500);
    myservo01.writeMicroseconds(1300);
    myservo02.writeMicroseconds(1300);
    delay(600);
    myservo01.writeMicroseconds(1600);
    myservo02.writeMicroseconds(1450);
    delay(3300);
    myservo01.writeMicroseconds(1300);
    myservo02.writeMicroseconds(1300);
    delay(600);
    
   
   }



}
