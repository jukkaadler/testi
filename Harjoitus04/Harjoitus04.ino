#define LED 12
#define PAINIKE1 4
#define PAINIKE2 5

#define LEDON LOW
#define LEDOFF HIGH
#define BUTTONPRESSED LOW

#define FILTER 20


int but2OldState;
int but1OldState;
int ledState;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PAINIKE1, INPUT_PULLUP);
  pinMode(PAINIKE2, INPUT_PULLUP);
  Serial.begin(9600);
  but2OldState = digitalRead(PAINIKE2);
  but1OldState = digitalRead(PAINIKE1);
}

void painike2() {
  int butNewState = digitalRead(PAINIKE2);
  if(butNewState != but2OldState){
    if(butNewState == BUTTONPRESSED){
      Serial.println("painike2 lähettää sarjaporttiin yhden tekstin joka painalluksella.");
    }
    delay(FILTER);
  }
  but2OldState=butNewState;
}

void painike1() {
  int butNewState = digitalRead(PAINIKE1);
  if(butNewState != but1OldState){
    if(butNewState == BUTTONPRESSED){
      //sysäri
     if(ledState==LEDOFF){
      ledState=LEDON;      
     }else{
      ledState=LEDOFF;
     }
     digitalWrite(LED, ledState);
    }
    delay(FILTER);
  }
  but1OldState=butNewState;
}

void loop(){
  painike2();
  painike1();
}

