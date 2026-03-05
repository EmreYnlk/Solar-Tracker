#include <Servo.h>

// Servo nesnesini oluşturuyoruz
Servo panelServo;

// Pin Tanımlamaları
const int servoPin = 9;   // Servo motorun bağlı olduğu dijital pin
const int ldrSag = A0;    // Sağ (Doğu) taraftaki LDR
const int ldrSol = A1;    // Sol (Batı) taraftaki LDR

// --- Değişkenler ---
int servoKonum = 90;      // Başlangıç konumu (Orta nokta)
const int sinirMin = 20;  // Mekanik sınır (Batı)
const int sinirMax = 150; // Mekanik sınır (Doğu)
const int tolerans = 15;  // Histerezis eşik değeri
const int hareketHizi = 50; // Servo bekleme süresi (ms)
const int donguHizi = 15;   // Döngü yenileme hızı (ms)

void setup() {
  // Servo motor başlatma ayarları
  panelServo.attach(servoPin);
  panelServo.write(servoKonum); // Motoru başlangıç konumuna al

  // Seri haberleşmeyi başlat (Test ve kalibrasyon için)
  Serial.begin(9600);
  delay(500);
}

void loop() {
  // 1. Sensör Verilerini Oku
  int sagDeger = analogRead(ldrSag);
  int solDeger = analogRead(ldrSol);

  // Değerleri Seri Port Ekranına Yazdır (Hata ayıklama)
  Serial.print("Sag LDR: ");
  Serial.print(sagDeger);
  Serial.print(" | Sol LDR: ");
  Serial.println(solDeger);

  // 2. Farkı Hesapla
  int fark = sagDeger - solDeger;

  // 3. Eşik Değeri Kontrolü (Histerezis)
  if (abs(fark) > tolerans) {

    // Işığın yoğun olduğu yöne göre pozisyon belirle
    if (fark > 0) {
      servoKonum = servoKonum - 1; // Doğuya git
    } else {
      servoKonum = servoKonum + 1; // Batıya git
    }

    // 4. Mekanik Sınırları Koru (Constraint)
    servoKonum = constrain(servoKonum, sinirMin, sinirMax);

    // Yeni konumu motora uygula
    panelServo.write(servoKonum);

    // Motorun oturması için bekle
    delay(hareketHizi);
  }

  delay(donguHizi);
}
