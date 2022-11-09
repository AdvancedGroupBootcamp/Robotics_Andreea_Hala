// Motor A
 
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B
 
int enB = 3;
int in3 = 5;
int in4 = 4;

unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
int t1=0;
void setup()
 
{
 
  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
}
 

 
void loop(){
 
currentMillis = millis();  

if (t1==0){
  //turn on motors 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(enB, 200);
  analogWrite(enA, 200);
  }

//turn after 3500 ms
if (currentMillis - previousMillis >= 3500){
  previousMillis = currentMillis;
  t1=1;

  //turn motors in opposet directions for 500 ms to turn 
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }

  //change t1 value to stop turning after 500 ms
if (currentMillis - previousMillis >= 500 & t1==1){
    previousMillis = currentMillis;
    t1=0;
    }

}
