/*
  HydroTrinket
  A hydroponics controller using the Adafruit Trinket.
  
  01/10/2015, Pete and Katie Marchetto
  This code is beerware: if you use it and meet either or both of us, you owe us a beer. Otherwise, simply follow cc-by 2.0.
*/

int Valve = 1;  //Control the valve relay from pin 1.
int Pump = 2;  //Control the pump relay from pin 2.

int PumpIn=100;  //Amount of time to fill the tray in seconds.
int WetDwell=3600;  //Amount of time to allow the hydroponics fluid to dwell in the tray in seconds.
int ValveOut=100;  //Amount of time to drain the tray into the bucket in seconds.
int DryDwell=3600;  //Amount of time to allow the plants to sit without hydroponics fluid in seconds.

void setup() {
  pinMode(Valve, OUTPUT);  //Set the valve relay pin as an output.
  pinMode(Pump, OUTPUT);  //Set the pump relay pin as an output.
  digitalWrite(Pump, HIGH);  //Drive the pump pin high, as the relay is active low.
  digitalWrite(Valve, HIGH);  //Drive the valve pin high, as the relay is active low.
}

void loop() {
  digitalWrite(Pump, LOW);  //Turn on the pump relay.
  delay(PumpIn*1000);  //Leave the pump relay on for PumpIn*1000 msec.
  digitalWrite(Pump, HIGH);  //Turn off the pump relay.
  delay(WetDwell*1000);  //Leave the pump relay off for WetDwell*1000 msec.
  digitalWrite(Valve, LOW);  //Turn on the valve relay.
  delay(ValveOut*1000);  //Leave the valve relay on for ValveOut*1000 msec.
  digitalWrite(Valve, HIGH);  //Turn off the valve relay.
  delay(DryDwell*1000);  //Leave the valve relay off for DryDwell*1000 msec.
}
