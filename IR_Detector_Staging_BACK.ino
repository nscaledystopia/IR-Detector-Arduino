/*** www.arduinopoint.com ***/
/*** Arduino with IR Sensor ***/
int the_inputs[4];
int the_blink[4];
int the_stage[4];
int SensorPin_1 = 2;
int SensorPin_2 = 3;
int SensorPin_3 = 4;
int SensorPin_4 = 5;
int SensorPin_5 = 6;
int SensorPin_6 = 7;
int OutputPin_1 = 10;
int OutputPin_2 = 11;
int OutputPin_3 = 12;


void setup() {
  pinMode(OutputPin_1, OUTPUT);
  pinMode(OutputPin_2, OUTPUT);
  pinMode(OutputPin_3, OUTPUT);
  
  pinMode(SensorPin_1, INPUT);
  pinMode(SensorPin_2, INPUT);
  pinMode(SensorPin_3, INPUT);
  pinMode(SensorPin_4, INPUT);
  pinMode(SensorPin_5, INPUT);
  pinMode(SensorPin_6, INPUT);
  Serial.begin(9600);
}

void loop() {
  //int SensorValue_1 = digitalRead(SensorPin_1);
  //int SensorValue_2 = digitalRead(SensorPin_2);
  
  the_inputs[1] = digitalRead(SensorPin_1);
  the_inputs[2] = digitalRead(SensorPin_2);
  the_inputs[3] = digitalRead(SensorPin_3);
  the_inputs[4] = digitalRead(SensorPin_4);
  the_inputs[5] = digitalRead(SensorPin_5);
  the_inputs[6] = digitalRead(SensorPin_6);
  
  //Serial.print("SensorPin Value: ");
  //Serial.println(SensorValue_1);
  //Serial.print("SensorPin Value 2: ");
  //Serial.println(SensorValue_2);


    if (((the_inputs[1]==HIGH) && (the_inputs[2]==HIGH) && (the_blink[1]==0))) {
      the_stage[1] = 0;
      the_blink[1] = 1;
    }
    if (((the_inputs[3]==HIGH) && (the_inputs[4]==HIGH) && (the_blink[2]==0))  ) {
      the_stage[2] = 0;
      the_blink[2] = 1;
    }
    if (((the_inputs[5]==HIGH) && (the_inputs[6]==HIGH) && (the_blink[3]==0))  ) {
      the_stage[3] = 0;
      the_blink[3] = 1;
    }  

  
    if (((the_inputs[1]==HIGH) && (the_inputs[2]==HIGH) && (the_stage[1]==3))) {
      the_stage[1] = 0;
      the_blink[1] = 0;
    }
    if (((the_inputs[3]==HIGH) && (the_inputs[4]==HIGH) && (the_stage[2]==3))) {
      the_stage[2] = 0;
      the_blink[2] = 0;
    }
    if (((the_inputs[5]==HIGH) && (the_inputs[6]==HIGH) && (the_stage[3]==3))) {
      the_stage[3] = 0;
      the_blink[3] = 0;
    }

    if (((the_inputs[1]==LOW) && (the_inputs[2]==HIGH))) {
      the_stage[1] = 1;
    }
    if (((the_inputs[3]==LOW) && (the_inputs[4]==HIGH))) {
      the_stage[2] = 1;
    }
    if (((the_inputs[5]==LOW) && (the_inputs[6]==HIGH))) {
      the_stage[3] = 1;
    }
  
    if (((the_inputs[1]==LOW) && (the_inputs[2]==LOW))) {
      the_stage[1] = 2;
    }
    if (((the_inputs[3]==LOW) && (the_inputs[4]==LOW))) {
      the_stage[2] = 2;
    }
    if (((the_inputs[5]==LOW) && (the_inputs[6]==LOW))) {
      the_stage[3] = 2;
    }    
    
  
    if (((the_inputs[1]==HIGH) && (the_inputs[2]==LOW))) {
      the_stage[1] = 3;
    }
    if (((the_inputs[3]==HIGH) && (the_inputs[4]==LOW))) {
      the_stage[2] = 3;
    }
    if (((the_inputs[5]==HIGH) && (the_inputs[6]==LOW))) {
      the_stage[3] = 3;
    }
  
 //delay(10);

  if ((the_stage[1]==0) || (the_stage[2]==0) || (the_stage[3]==0)) {
    if ((the_stage[1]==0)) {
      digitalWrite(OutputPin_1, LOW);
    }
    if ((the_stage[2]==0)) {
      digitalWrite(OutputPin_2, LOW);
    }
    if ((the_stage[3]==0)) {
      digitalWrite(OutputPin_3, LOW);
    }
    //delay(100);
  }
  
  
  if ((the_stage[1]==1) || (the_stage[2]==1) || (the_stage[3]==1)) {
    if(the_stage[1]==1) {
      digitalWrite(OutputPin_1, HIGH);
    }
    if(the_stage[2]==1) {
      digitalWrite(OutputPin_2, HIGH);
    }
    if(the_stage[3]==1) {
      digitalWrite(OutputPin_3, HIGH);
    }
    
    delay(150);
    
    if(the_stage[1]==1) {
      digitalWrite(OutputPin_1, LOW);
    }
    if(the_stage[2]==1) {
      digitalWrite(OutputPin_2, LOW);
    }
    if(the_stage[3]==1) {
      digitalWrite(OutputPin_3, LOW);
    }
    delay(200);
  }

  
  if ((the_stage[1]==2) || (the_stage[2]==2) || (the_stage[3]==2)) {
    if(the_stage[1]==2){
      digitalWrite(OutputPin_1, HIGH);
    }
    if(the_stage[2]==2){
      digitalWrite(OutputPin_2, HIGH);
    }
    if(the_stage[3]==2){
      digitalWrite(OutputPin_3, HIGH);
    }
    //delay(100);
  }

  
  if ((the_stage[1]==3) || (the_stage[2]==3) || (the_stage[3]==3)) {
    if (the_stage[1]==3) {
      digitalWrite(OutputPin_1, HIGH);
    }
    if (the_stage[2]==3) {
      digitalWrite(OutputPin_2, HIGH);
    }
    if (the_stage[3]==3) {
      digitalWrite(OutputPin_3, HIGH);
    }
  }

}
