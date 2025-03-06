// Hardware: WeMos D1 R2 & mini
// Software: Arduino IDE
// Libraries: Blynk
// About Blynk: https://blynk.io/
// Blynk Documentation: https://docs.blynk.io/
// Blynk Community: https://community.blynk.cc/
// Blynk Twitter: https://twitter.com/blynk_app
// Blynk Facebook: https://www.facebook.com/blynkapp

#define BLYNK_TEMPLATE_ID "XXXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "XXXXXXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXXXXXXXXXXXXXXXX"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Kredensial WiFi Anda
char ssid[] = ""; // Ganti dengan SSID WiFi Anda
char pass[] = ""; // Ganti dengan password WiFi Anda

int LED = D2; // Definisikan pin LED (ganti sesuai kebutuhan)

void setup() {
  // Konsol debug
  Serial.begin(115200);
  pinMode(LED, OUTPUT); // Atur pin LED sebagai output
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // Hubungkan ke Blynk
}

void loop() {
  Blynk.run(); // Jalankan Blynk
}

// Fungsi ini dipanggil setiap kali widget tombol menulis ke pin virtual V1
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Dapatkan nilai dari tombol
  if (pinValue == 1) {
    digitalWrite(LED, HIGH); // Nyalakan LED
  } else {
    digitalWrite(LED, LOW); // Matikan LED
  }
}