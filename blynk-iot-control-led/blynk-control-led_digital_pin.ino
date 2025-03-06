// Hardware: WeMos D1 R2 & mini
// Software: Arduino IDE
// Libraries: Blynk
// About Blynk: https://blynk.io/
// Blynk Documentation: https://docs.blynk.io/
// Blynk Community: https://community.blynk.cc/
// Blynk Twitter: https://twitter.com/blynk_app
// Blynk Facebook: https://www.facebook.com/blynkapp

#define BLYNK_TEMPLATE_ID "TMPL69laJw2kT"
#define BLYNK_TEMPLATE_NAME "Smart Light"
#define BLYNK_AUTH_TOKEN "C-5msVetprCVnDCKPog19cOXJvqVXB3o"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "rakaadesti_2.4G";  // Enter your Wifi Username
char pass[] = "Tasik12345";  // Enter your Wifi password

int ledpin = D2;

void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  Blynk.run(); 
}