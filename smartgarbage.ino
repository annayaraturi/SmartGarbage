['#include<Servo.h>                //Adding the Servo library
#include <SoftwareSerial.h>        // including the library for the software serial
#define DEBUG true
SoftwareSerial esp8266(3,4);
 
Servo myservo;            //Define an object named MyServo
const int eko=6;        
const int trig=5;        
const int ek=10;        
const int tri=9; 
int distance;
int time2;
int time1;
int dod;
void setup() {
  myservo.attach(11);           //We introduced the ninth pin arduino to the servo motor
  pinMode(trig,OUTPUT);        
  pinMode(eko,INPUT);          
   pinMode(tri,OUTPUT);        
  pinMode(ek,INPUT); 
  Serial.begin(115200);         // Setting the baudrate at 9600
  esp8266.begin(115200);        // Set the baudrate according to you esp's baudrate
 
}
 
void loop() {
  myservo.write(0);       
  Serial.begin(9600);     
    digitalWrite(tri, LOW);         
  delayMicroseconds(10);
  digitalWrite(tri, HIGH);       
  delayMicroseconds(20);
     time2 = pulseIn(ek, HIGH);
   
  digitalWrite(trig, LOW);         
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);       
  delayMicroseconds(20);
  digitalWrite(trig, LOW);         
  time1= pulseIn(eko, HIGH);      
distance= (time1/29.1)/2;  
dod=(time2/29.1)/2;
if(distance<=5){
    myservo.write(70);
    delay(1000);
 }
  
   
  if(distance>5)
  {
distance=20;
Serial.print("  distance is greater than 20  so it wont open  /n");
Serial.println(distance);
delay(1000);
}
if(dod<5)
{
  dod=5;
  Serial.print(" DUSTBIN IS FULL 100% /n");
  Serial.print(" Alert!!truck to be loaded today  /n");
  
  Serial.println(dod);
delay(200);}
else if(dod>13)
{
  
  Serial.print(" almost enough space /n");
Serial.println(dod);
delay(1000);}
else if(dod>9)
{
  Serial.print(" dustbin is 50% Full /n");
  Serial.print(" still enough space /n");
Serial.println(dod);
delay(200);}
else if(dod>6)
{
  Serial.print(" dustbin is 80% Full /n ");
  Serial.print(" alert!!two days to clear dustbins /n");
Serial.println(dod);
delay(1000);
}
}

 
/*if(esp8266.available())         // This command will that check if the esp is sending a message 
  {    
    if(esp8266.find("+IPD,"))
    {
     delay(1000);
     int connectionId = esp8266.read()-48; /* We are subtracting 48 from the output because the read() function returns 
                                            the ASCII decimal value and the first decimal number which is 0 starts at 48
                                            String webpage = "<h1>IOT Garbage Monitoring System</h1>";
       webpage += "<p><h2>";     
    
if(sure<=5){
    
        webpage+= " Trash can is Full";
        }
        else{
          webpage+= " Trash can is Empty";
          }
       webpage += "</h2></p></body>";  
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
 
    delay(500);  */ 
  
 
 
    //}
  //}

 
/*String sendData(String command, const int timeout, boolean debug)
{
    String response = "";   
    esp8266.print(command); 
    long int time = millis();
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        char c = esp8266.read(); 
        response+=c;
      }  
    }
    if(debug)
    {
      Serial.print(response);
    }
    return response;
}*/
