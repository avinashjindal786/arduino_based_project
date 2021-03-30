int trigPin=13; //Sensor Trip pin connected to Arduino pin 13
int echoPin=11;  //Sensor Echo pin connected to Arduino pin 11
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=343; //Speed of sound 

void setup() 
{
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
 Serial.println("CLEARDATA");//clear excel sheet
 Serial.println("LABEL,current time,Distance in cm");//label for ms-excel
}
void loop()
{
  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is in microceconds
  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 
  targetDistance= speedOfSound * pingTime;//distance=speed*time
  targetDistance=targetDistance/2;//waves is traveling twice
  targetDistance=targetDistance*100;//convet m to cm
  Serial.print("DATA,TIME,");
  Serial.println(targetDistance );
  delay(1000);
}
