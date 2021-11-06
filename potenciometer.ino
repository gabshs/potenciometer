#define POT A0
#define BTN 8
#define POWER 3
#define INPUT1 2
#define INPUT2 7
#define LED_CLOCKWISE 12
#define LED_COUNTER_CLOCKWISE 13

int potentiometer = 0;
int speed = 0;
int btn_state = 0;
   
void setup()  
{  
  //Define os pinos como saida
  Serial.begin(9600);
  pinMode(POT, INPUT);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED_CLOCKWISE, OUTPUT); 
  pinMode(LED_COUNTER_CLOCKWISE, OUTPUT); 
  pinMode(POWER, OUTPUT); 
  pinMode(INPUT1, OUTPUT);  
  pinMode(INPUT2, OUTPUT);  
}  
   
void loop()  
{  
  potentiometer = analogRead (POT);
  speed = map(potentiometer ,0 ,1023, 0, 255);
  btn_state = digitalRead (BTN);
  
  analogWrite(POWER, speed);   
  
  if (btn_state == HIGH){
   	analogWrite(LED_CLOCKWISE, 250);
    analogWrite(LED_COUNTER_CLOCKWISE, 0);
  	digitalWrite(INPUT1, LOW);  
 		digitalWrite(INPUT2, HIGH);  
  
  }

  else{
    analogWrite(LED_COUNTER_CLOCKWISE, 250);
    analogWrite(LED_CLOCKWISE, 0);
 		digitalWrite(INPUT1, HIGH);  
  	digitalWrite(INPUT2, LOW); 
  }
}  