const int button = 6;     // the number of the pushbutton pin
const int led1 =  2;      // the number of the LED pin
const int links1 = 8;
const int rechts1 = 9;
const int links2 = 10;
const int rechts2 = 11;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int statusled = 13;

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
uint32_t timer1 = 0;
long randNumber;
// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup()
{
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button, INPUT);
  pinMode(statusled, OUTPUT);
  //pinMode(button, INPUT_PULLUP); // set the internal pull up resistor, unpressed button is HIGH
  pinMode(links1, OUTPUT);
  pinMode(rechts1, OUTPUT);
  pinMode(links2, OUTPUT);
  pinMode(rechts2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Booted");
  randomSeed(analogRead(0));
}

void loop()
{
  reading = digitalRead(button);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  
  if (reading == HIGH && previous == LOW && millis() - time > debounce) 
  {
    if (state == HIGH)
    {
      doLinks();
      randNumber = random(1, 3);
      Serial.println(randNumber);
      switch (randNumber) {
        case 1:
          // statements
          doStop();
        break;
        case 2:
          // statements
          doRechts();
        break;
          case 3:
          doLinks();
        default:
        // statements
            Serial.println("Random's not hot");
}
      state = LOW;
    }
    else
    {
      state = HIGH;
      doLinks();
      delay(1000);
      time = millis();    
    }
  }

  //digitalWrite(led1, state);

  previous = reading;
}
  void doStop(){
    Serial.println("State Stop Entered");
    digitalWrite(led4, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(links1, LOW);
    digitalWrite(rechts1, LOW);
    digitalWrite(links2, LOW);
    digitalWrite(rechts2, LOW);
  }
void doLinks(){
    // turn LED on: doe random
    Serial.println("State Links Entered");
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(links1, HIGH);
    digitalWrite(rechts1, HIGH);
    digitalWrite(links2, HIGH);
    digitalWrite(rechts2, HIGH);
    digitalWrite(led2, HIGH);
}
void doRechts(){
// turn LED off: doe normaal
  Serial.println("State Rechts Entered");
  digitalWrite(led1, HIGH);
  digitalWrite(links1, HIGH);
  digitalWrite(rechts1, HIGH);
  digitalWrite(links2, HIGH);
  digitalWrite(rechts2, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
