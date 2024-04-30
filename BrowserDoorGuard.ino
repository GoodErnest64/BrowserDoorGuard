//Made By Goodernest64
const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;
const unsigned int BAUD_RATE = 9600;
const unsigned int MIN_DIST = 25; //cm
const unsigned String MSG = "<Your Message Of Choice>"; //put whatever message you like

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);
}

void loop()  {
  //Calculating Distance...
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,  HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  int distance= duration/29/2;
  if(duration==0)
  {
    Serial.println("Warning: no pulse from sensor");
  }  
  else
  {
    if(distance <= MIN_DIST) //If a Person Is Passing
    {
      Serial.print(MSG);
    }
  }
  delay(100); 
}