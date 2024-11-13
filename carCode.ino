const int trigPin = 13;
const int echoPin = 12;

const int enAPin = 6;
const int in1Pin = 7;
const int in2Pin = 5;
const int in3Pin = 4;
const int in4Pin = 2;
const int enBPin = 3;

int distance;
long duration;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enBPin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = measureDistance();

  Serial.println("Distance is : "+String(distance));

  if(distance < 50 ){
    Serial.println("Obstacle ");
    moveBackward(10);
    Serial.println("Moving Backward ");
  }else{
    moveForward();
    Serial.println("Moving Forward ");
  }
  delay(500);
}

unsigned int measureDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long period =
  pulseIn(echoPin,HIGH);
  return period * 0.0343 / 2;
}

void moveForward(){
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);

  analogWrite(enAPin, 255);

  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  analogWrite(enBPin, 255); 
  
}

void moveBackward(int cm){
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);

  analogWrite(enAPin, 255);

  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  analogWrite(enBPin, 255);

  int delayTime = cm * 60 ;
  delay(delayTime); 

}
