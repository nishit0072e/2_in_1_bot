#include<Servo.h>
#include<UARTClass.h>
UARTClass MyBlue(1);  //RX | TX
/* Defining Motor Control Pins */
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

#define LEDPIN 22
#define LEDPIN2 24
#define LEDPIN3 23

char command;  //defining command as global variable which will store commands as app sends

/* Initializing commands */
/******************************Forward****************************/
void Forward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(LEDPIN,LOW);
  digitalWrite(LEDPIN2,HIGH);
  digitalWrite(LEDPIN3,HIGH);
  Serial.println("Forward////");
}
/******************************Backward****************************/
void Backward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(LEDPIN,HIGH);
  digitalWrite(LEDPIN2,LOW);
  digitalWrite(LEDPIN3,HIGH);
  Serial.println("Backward////");
}
/******************************Left****************************/
void Left(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(LEDPIN,HIGH);
  digitalWrite(LEDPIN2,HIGH);
  digitalWrite(LEDPIN3,LOW);
  Serial.println("Left////");
}
/******************************Right****************************/
void Right(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(LEDPIN,HIGH);
  digitalWrite(LEDPIN2,HIGH);
  digitalWrite(LEDPIN3,LOW);
  Serial.println("Right////");
}
/******************************stop****************************/
void Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stop////");
}
void command_instruction(){
  if(MyBlue.available()){
    command = MyBlue.read();
    /* Switch on the car motor according to the command */
    if(command == 'F'){
      Forward();
      Serial.println(command);
    }
    if(command == 'B'){
      Backward();
      Serial.println(command);
    }
    if(command == 'L'){
      Left();
      Serial.println(command);
    }
    if(command == 'R'){
      Right();
      Serial.println(command);
    }
    if(command == 'S'){
      Stop();
      Serial.println(command);
    }
  }
}
void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  pinMode(LEDPIN,OUTPUT);
  
  Serial.begin(115200);
  MyBlue.begin(9600);
  Serial.println("Ready to connect\n Default Password is 1234");
}
void loop(){
  command_instruction();
}
