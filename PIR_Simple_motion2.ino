int relayPin = A0; //Pin to relay module
const int MOTION_PIN = A1; //Pin to PIR Motion Sensor 
const int LED_PIN = 1; //Built in LED on blackboard

void setup() {
  Serial.begin(115200);
  pinMode(MOTION_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(relayPin, OUTPUT); //Pin connected to Relay as OUTPUT
  digitalWrite(relayPin, LOW); //Set pin to LOW to turn relay OFF
  Serial.print("PIR MOTION SENSING");
}

void loop() {
  int proximity = digitalRead(MOTION_PIN); //declare proximity with PIR Motion sensor
  Serial.println(proximity);

  while (proximity == 0)
   { 
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(relayPin, HIGH);
    proximity = digitalRead(MOTION_PIN);
    delay(10000);
   }
    digitalWrite(LED_PIN, LOW);
    digitalWrite(relayPin, LOW);
    Serial.println("Relay is OFF");
   
//  if (proximity == 0)
//  {
//    digitalWrite(LED_PIN, HIGH);
//    Serial.println("Motion detected");
//    digitalWrite(relayPin, HIGH);
//    Serial.println("Relay is on");
//    delay(10);
//  }
//  else
//  {
//    digitalWrite(LED_PIN, LOW);
//    digitalWrite(relayPin, LOW);
//    Serial.println("Relay is OFF");
//    delay(10);
//  }
}
