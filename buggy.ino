//buggy project
//5,6,7,8 pins control movement
//5 high 6 low make right motor move
//7 low 8 high make left motor move


long duration;
int distance; 
int count;

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
}
void forward()
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  }
void stops()
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
void left_turn()
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
void right_turn()
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  }

/*void start_now()
 {*/
  

  
void loop() {

  digitalWrite(13,LOW);
  delayMicroseconds(50);
  digitalWrite(13,HIGH);
  delayMicroseconds(10);
  digitalWrite(13,LOW);
  duration = pulseIn(12,HIGH);
  distance = duration * 0.034 / 2;
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");

  if (distance<=15)
  {
    stops();
  }

  else
  {
  if (digitalRead(A0)==HIGH && digitalRead(A1)==HIGH)
  {
    forward();
  }
  else if (digitalRead(A0)==LOW && digitalRead(A1)==HIGH)
  {
    right_turn();
  }
  else if(digitalRead(A0)==HIGH && digitalRead(A1)==LOW)
  {
    left_turn();
  }
  else
  stops();
  }
 
  
  /*char data = 0;
  if(Serial.available()>0)
  {
    data = Serial.read();
    Serial.println("Data Received is : ");
    Serial.write(data);
    if (data=='f')
    {
      forward();
      start_now();
    }
    else if (data=='s')
    {
      stops();
    }
  }  
*/
 
 if (digitalRead(4)==HIGH)
 {
  int d = pulseIn(4,HIGH);
  if(d>500 and d<1500)
  {
    count++;
    Serial.println(d);
    Serial.println("Gantry:Crossed");
    Serial.println(count);
    stops();
    delay(5000);
    forward();
    //delay(5000);
  }
 }

}



//for ultrasonic sensor
//trig pin low for 50us and high for 10us then low 40kHz frequency use delaymicrosecond function, pin 13,output
//echo use pulsein function measure high state pulsewidth, pin 12 ,input
//for xbee 
//802.15.4 protocol
//radio frequency 2.4GHz ,check specifications
//coordinator,router,end-devices used for communication
//XCTU software used
//XBEE is connected to serial communication pins
