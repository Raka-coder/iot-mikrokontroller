# Smart Light dengan Sinric Pro

[![Sinric Pro](https://img.shields.io/badge/Sinric%20Pro-ESP8266%2FESP32-blue)](https://sinric.pro/)

## Deskripsi

Proyek ini menggunakan Board ESP8266/ESP32 untuk melakukan kontrol LED dan melakukan sinkronisasi dengan Google Home/Assistant menggunakan Sinric Pro. Dengan proyek ini, Anda dapat menghidupkan dan mematikan LED menggunakan perintah suara melalui Google Assistant.

## Fitur

- Kontrol LED menggunakan Sinric Pro, Google Home/Assistant.
- Sinkronisasi dengan Google Home/Assistant.
- Kontrol melalui Google Assistant dengan perintah suara.
- Status LED dapat diperbarui secara real-time.

## Hardware

- Board ESP8266/ESP32 (misalnya NodeMCU atau Wemos D1 Mini)
- LED
- Breadboard (opsional)
- Kabel Jumper

## Software

- Arduino IDE
- Library Sinric Pro

## Cara Menggunakan

1. **Instalasi Arduino IDE dan Library Sinric Pro**:
   - Unduh dan instal Arduino IDE dari [sini](https://www.arduino.cc/en/software).
   - Buka Arduino IDE, pergi ke **Sketch** > **Include Library** > **Manage Libraries**.
   - Cari "Sinric Pro" dan instal library yang sesuai.

2. **Buat Akun Sinric Pro**:
   - Kunjungi [Sinric Pro](https://sinric.pro/) dan buat akun.
   - Buat perangkat baru dan catat `APP_KEY`, `APP_SECRET`, dan `DEVICE_ID`.

3. **Hubungkan Board ESP8266/ESP32**:
   - Hubungkan Board ESP8266/ESP32 ke komputer menggunakan kabel USB.

4. **Konfigurasi Kode**:
   - Buka Arduino IDE dan pilih Board ESP8266/ESP32 yang sesuai.
   - Ganti `APP_KEY`, `APP_SECRET`, dan `DEVICE_ID` di kode dengan informasi yang Anda dapatkan dari Sinric Pro.
   - Ganti `SSID` dan `PASS` dengan informasi jaringan Wi-Fi Anda.

5. **Upload Kode**:
   - Upload kode program ke Board dengan menekan tombol **Upload** di Arduino IDE.

6. **Tambahkan Perangkat di Google Home/Assistant**:
   - Buka aplikasi Google Home/Assistant di perangkat Anda.
   - Tambahkan perangkat Sinric Pro dengan mengikuti petunjuk di aplikasi.

7. **Kontrol LED**:
   - Gunakan aplikasi Google Home/Assistant untuk mengontrol LED dengan perintah suara seperti "Hidupkan lampu" atau "Matikan lampu".

## Modifikasi Kode

Berikut adalah bagian penting dari kode yang mengontrol LED:

```cpp
#define LED_PIN 5 // D1 (GPIO5) sesuaikan dengan pin yang Anda gunakan

// Inisialisasi pin LED
void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(LED_PIN, OUTPUT); // Set pin LED sebagai output
  setupWiFi();
  setupSinricPro();
}

// Update status LED berdasarkan power state
bool onPowerState(const String &deviceId, bool &state) {
  Serial.printf("[Device: %s]: Powerstate changed to %s\r\n", deviceId.c_str(), state ? "on" : "off");
  globalPowerState = state;
  
  // Menghidupkan atau mematikan LED
  digitalWrite(LED_PIN, state ? HIGH : LOW); // Jika state true, hidupkan LED, jika false, matikan LED
  
  return true; // request handled properly
}