#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
         
const byte address[6] = "00001";  

//Ultrasonic 1
int echoPin1 = 2;
int trigPin1 = 3;

////Ultrasonic 2
int echoPin2 = 4;
int trigPin2 = 5;

//Ultrasonic 3
int echoPin3 = 6;
int trigPin3 = 7;

//Ultrasonic 4 //Analog pins can be used as digital Pins
int echoPin4 = A0;
int trigPin4 = A1;

long duration1; // variable for the duration of sound wave travel
int distanceCm1; 

long duration2; // variable for the duration of sound wave travel
int distanceCm2; 

long duration3; // variable for the duration of sound wave travel
int distanceCm3; 

long duration4; // variable for the duration of sound wave travel
int distanceCm4; 


void setup() 
{
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); 

  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT);
 
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin3, INPUT);
  
  pinMode(trigPin4, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin4, INPUT);
  
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();  
}

void loop()
{
  //Ultransonic1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distanceCm1 =(duration1 * 0.0343) / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance of Ultrasonic 1: ");
  //Serial.print(distanceCm1);
  //radio.write(&distanceCm1, sizeof(distanceCm1));

  //Ultrasonic2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distanceCm2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.println(" Distance of Ultrasonic 2: ");
  //Serial.print(distanceCm2);

  //Ultrasonic3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distanceCm3 = duration3 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.println("Distance of Ultrasonic 3: ");
  //Serial.print(distanceCm3);
      
         
  //Ultrasonic4
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration4 = pulseIn(echoPin4, HIGH);
  // Calculating the distance
  distanceCm4 = duration4 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.println("Distance of Ultrasonic 4: ");
  //Serial.print(distanceCm4);
      
    
if (distanceCm1 <= 4 && distanceCm2 <= 4 && distanceCm3 <= 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));

    Serial.println(" 1, 2, 3 and 4 is taken");
  }

  else if (distanceCm1 > 4 && distanceCm2 > 4 && distanceCm3 > 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1, 2, 3 and 4 is open");
  }

  else if (distanceCm1 <= 4 && distanceCm2 > 4 && distanceCm3 > 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 is open. 2, 3 and 4 is taken");
  }

  else if (distanceCm1 > 4 && distanceCm2 <= 4 && distanceCm3 > 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 2 is open. 1, 3 and 4 is taken");
  }

  else if (distanceCm1 > 4 && distanceCm2 > 4 && distanceCm3 <= 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 3 is taken. 1, 2 and 4 is open");
  }
  
  else if (distanceCm1 > 4 && distanceCm2 > 4 && distanceCm3 > 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 4 is taken. 1, 2 and 3 is open");
  }

  else if (distanceCm1 <= 4 && distanceCm2 <= 4 && distanceCm3 > 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 and 2 is taken. 3 and 4 is open");
  }

  else if (distanceCm1 <= 4 && distanceCm2 > 4 && distanceCm3 <= 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 and 3 is taken. 2 and 4 is open");
  }

else if (distanceCm1 <= 4 && distanceCm2 > 4 && distanceCm3 > 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 and 4 is taken. 2 and 3 is open");
  }  

  else if (distanceCm1 > 4 && distanceCm2 <= 4 && distanceCm3 <= 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 2 and 3 is taken. 1 and 4 is open");
  } 

  else if (distanceCm1 > 4 && distanceCm2 <= 4 && distanceCm3 > 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 and 3 is open. 2 and 4 is taken");
  }

  else if (distanceCm1 > 4 && distanceCm2 > 4 && distanceCm3 <= 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 3 and 4 is taken. 1 and 2 is open");
  }

  else if (distanceCm1 <= 4 && distanceCm2 <= 4 && distanceCm3 <= 4 && distanceCm4 > 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is open";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 ,2 and 3 is taken. 4 is open");
  }

  else if (distanceCm1 <= 4 && distanceCm2 <= 4 && distanceCm3 > 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is open";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1 ,2 and 4 is taken. 3 is open");
  }

  else if (distanceCm1 <= 4 && distanceCm2 > 4 && distanceCm3 <= 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is taken";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is open";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 1, 3 and 4 is taken. 2 is open");
  }

  else if (distanceCm1 > 4 && distanceCm2 <= 4 && distanceCm3 <= 4 && distanceCm4 <= 4)
  {
    const char text1[] = "Parking spot 1 is open";
    radio.write(&text1, sizeof(text1));
    delay(40);
    const char text2[] = "Parking spot 2 is taken";
    radio.write(&text2, sizeof(text2));
    delay(40);
    const char text3[] = "Parking spot 3 is taken";
    radio.write(&text3, sizeof(text3));
    delay(40);
    const char text4[] = "Parking spot 4 is taken";
    radio.write(&text4, sizeof(text4));
    
    Serial.println(" 2 ,3 and 4 is taken. 1 is open");
  }
}
