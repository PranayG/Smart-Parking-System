#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

int US1 = 2;
int US2 = 3;
int US3 = 4;
int US4 = 5;

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.startListening();              //This sets the module as receiver
  pinMode(US1, OUTPUT);
  pinMode(US2, OUTPUT);
  pinMode(US3, OUTPUT);
  pinMode(US4, OUTPUT);
}

void loop()
{
  if (radio.available())              //Looking for the data.
 {

  int test[4];
  char text[32] = "";                 //Saving the incoming data
  radio.read(&text, sizeof(text));    //Reading the data 
  int spot = text[13]; 
  int status = text[18];
  //Serial.println(spot);
  //Serial.println(text[18]);
  if(spot == 49){
    //Serial.println(text[13]);
    if(status == 111){
      test[0] = 1;
    } 
    else if(status == 116){
      test[0] = 0;
    }
  }
  else if(spot == 50){
    //Serial.println(text[13]);
    if(status == 111){
      test[1] = 1;
    } 
    else if(status == 116){
      test[1] = 0;
    }
  }
  else if(spot == 51){
    //Serial.println(text[13]);
    if(status == 111){
      test[2] = 1;
    } 
    else if(status == 116){
      test[2] = 0;
    }
  }
  else if(spot == 52){
    //Serial.println(text[13]);
    if(status == 111){
      test[3] = 1;
    } 
    else if(status == 116){
      test[3] = 0;
    }
  }
  //Serial.println(text);

  Serial.println(test[0]);
  Serial.println(test[1]);
  Serial.println(test[2]);
  Serial.println(test[3]);
  Serial.println("End");

    if(test[0] == 1 && test[1] == 0 && test[2] == 0 && test[3] == 0){
      Serial.println("PARKING 1 IS OPEN");
      digitalWrite(US1, HIGH);
      digitalWrite(US2, LOW);
      digitalWrite(US3, LOW);
      digitalWrite(US4, LOW);
    }

    else if(test[0] == 0 && test[1] == 1 && test[2] == 0 && test[3] == 0){
      Serial.println("PARKING 2 IS OPEN");
      digitalWrite(US1, LOW);
      digitalWrite(US2, HIGH);
      digitalWrite(US3, LOW);
      digitalWrite(US4, LOW);
    }

    else if(test[0] == 0 && test[1] == 0 && test[2] == 1 && test[3] == 0){
      Serial.println("PARKING 3 IS OPEN");
      digitalWrite(US1, LOW);
      digitalWrite(US2, LOW);
      digitalWrite(US3, HIGH);
      digitalWrite(US4, LOW);
    }

    else if(test[0] == 0 && test[1] == 0 && test[2] == 0 && test[3] == 1){
      Serial.println("PARKING 4 IS OPEN");
      digitalWrite(US1, LOW);
      digitalWrite(US2, LOW);
      digitalWrite(US3, LOW);
      digitalWrite(US4, HIGH);
    }
  // for (byte i = 0; i < 2; i = i + 1) {
  //   Serial.println(test[i]);
  // }
    else {
      Serial.println("Nill");
      digitalWrite(US1, LOW);
      digitalWrite(US2, LOW);
      digitalWrite(US3, LOW);
      digitalWrite(US4, LOW);
    }       
}
}