int s=3;
const int motor1Pin = 10;    
const int motor2Pin = 9;    
const int enablePin1 = 8;
const int motor3Pin = 13;    
const int motor4Pin = 12;    
const int enablePin2 = 11;
const int echoPin=6;
const int trigPin=7;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin1, HIGH);
  digitalWrite(enablePin2, HIGH);
}

void loop() 
{
  analogWrite(enablePin1, 255); // Run in full speed
  analogWrite(enablePin2, 255);   
  digitalWrite(motor1Pin, LOW);   
  digitalWrite(motor2Pin, HIGH);
  digitalWrite(motor3Pin, LOW);   
  digitalWrite(motor4Pin, HIGH);

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

 
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
    Serial.println(distance);
    int error=distance-10;
    
 if(distance>10)
 {
   int v=127+(125*error);
  analogWrite(enablePin1, v); // Run in half speed
  analogWrite(enablePin2, v);
   
  digitalWrite(motor1Pin, LOW);   
  digitalWrite(motor2Pin, HIGH);
  digitalWrite(motor3Pin, LOW);   
  digitalWrite(motor4Pin, HIGH);
 }
 
 
 
 else if(distance<10)
 {
   while(s<=3)
 {
   digitalWrite(motor1Pin, HIGH);   
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, HIGH);   
  digitalWrite(motor4Pin, LOW);
   Serial.println(distance);
  analogWrite(enablePin1, 0); 
  analogWrite(enablePin2, 0); 
  digitalWrite(motor1Pin, LOW);   
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, LOW);   
  digitalWrite(motor4Pin, LOW);
 }
 
 }
 
 else if(distance==10)
 {
  Serial.println(distance);
  analogWrite(enablePin1, 0); 
  analogWrite(enablePin2, 0); 
  digitalWrite(motor1Pin, LOW);   
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, LOW);   
  digitalWrite(motor4Pin, LOW);
  }
  delay(250);
}

