long counter = 0;
long begining_time = 0;
long ending_time = 0;
long time_passed_sec = 0;
long time_reference = 0;
int pin = 2;
int button = 1;
int state = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  button = digitalRead(pin);
  if(button== 0 ) // button is low when pressed , change counter state , and record time beginning time
  {
    state = state > 0 ?0:1; // change the counter state 
    if (state )
    {
      begining_time = millis(); //reset the beginning time when state turned on
      time_reference = 0;       // reset time reference
    }
    delay(500);
  }
  if(state)
  {
    ending_time = millis(); // record the current time and save to ending_time 
    time_passed_sec = (ending_time - begining_time + 999)/1000 - 1;
    if(time_passed_sec > time_reference)  // comparing time reference and time_passed_sec (counting one sec)
    {
        time_reference = time_passed_sec;
        counter++;
        Serial.println(counter);
    }
  }
}
// problem detected:  button dectection without delay (fixed: adding delay after button pressed)
