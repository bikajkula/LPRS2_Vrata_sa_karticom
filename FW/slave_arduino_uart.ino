//Receiver (Rx) Arduino Board Code


#define LED_ON    HIGH
#define LED_OFF   LOW 

char ch;               //Initialized variable to store receive


// Arduino digital pins that control red, green and blue colors:
const int LED_R = 2;
const int LED_G = 3;
const int LED_B = 4;
const int buzzer = 9; //buzzer to arduino pin 9
 
void setup()
{
   pinMode(buzzer, OUTPUT);
   pinMode(LED_R, OUTPUT);
   pinMode(LED_G, OUTPUT);
   pinMode(LED_B, OUTPUT);
   Serial.begin(9600);
}
void loop()
{
 
   if(Serial.available())
   {
       ch = Serial.read();  //Read the serial data
       Serial.println(ch);       //Print data on Serial Monitor
       if(ch == '1'){
          Serial.println("Authorized access");
          analogWrite(LED_R,   0);
          analogWrite(LED_G, 255);
          analogWrite(LED_B,  0);
          tone(buzzer,5*659,2000);
          delay(250);
          tone(buzzer,5*659,2000);
          delay(500);
          tone(buzzer,5*698,2000);
          delay(500);
          noTone(buzzer);
        }
       else{
        Serial.println("DENIED");
        analogWrite(LED_R,   255);
        analogWrite(LED_G, 0);
        analogWrite(LED_B,  0);
        tone(buzzer,262,250);
        delay(500);
        tone(buzzer,196,250);
        delay(500);
        tone(buzzer,196,250);
        delay(500);
        noTone(buzzer);
       }
      analogWrite(LED_R,   255);
      analogWrite(LED_G, 255);
      analogWrite(LED_B,  255);
      delay(1000);  
   }
}

