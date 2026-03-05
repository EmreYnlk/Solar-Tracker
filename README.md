# Arduino Güneş Takip Sistemi (Solar Tracker)

Bu proje, iki adet LDR (Işık Bağımlı Direnç) sensörü ve bir servo motor kullanarak güneş ışığının veya ortamdaki en parlak ışık kaynağının yönünü otomatik olarak takip eden sistemin kaynak kodudur.

## Özellikler

* **Otomatik Yönlendirme:** Sağ ve sol LDR'ler arasındaki ışık şiddeti farkını hesaplayarak paneli/motoru ışığın en yoğun olduğu yöne çevirir.
* **Histerezis (Tolerans) Kontrolü:** Ufak ışık değişimlerinde motorun sürekli titremesini (kararsızlık durumunu) önlemek için bir eşik değeri (`tolerans`) kullanır.
* **Mekanik Sınırlar:** Servo motorun fiziksel olarak zorlanmasını engellemek için yazılımsal olarak minimum (20°) ve maksimum (150°) hareket sınırları (`sinirMin`, `sinirMax`) belirlenmiştir.

## Donanım Gereksinimleri

* 1x Arduino Uno (veya Nano/Mega)
* 1x Servo Motor (Örn: SG90 veya MG996R)
* 2x LDR (Işık Sensörü)
* 2x 10kΩ Direnç (LDR'ler için pull-down direnci olarak)
* Breadboard ve Jumper Kablolar



## Pin Bağlantıları

| Bileşen / Pin | Arduino Bağlantısı |
| :--- | :--- |
| **Servo Motor Sinyal** | Dijital Pin `9` |
| **Sağ LDR (Doğu)** | Analog Pin `A0` |
| **Sol LDR (Batı)** | Analog Pin `A1` |

*(Not: LDR'lerin bir bacağı 5V'a, diğer bacağı ise hem Analog okuma pinine hem de 10kΩ direnç üzerinden GND'ye bağlanmalıdır.)*

## Kurulum ve Kullanım

1. Bu depoyu bilgisayarınıza klonlayın veya `.ino` uzantılı dosyayı indirin.
2. Kod dosyasını **Arduino IDE** ile açın. (Kodun kullandığı `<Servo.h>` kütüphanesi Arduino IDE ile dahili olarak gelir, ekstra yükleme gerektirmez.)
3. Devre bağlantılarınızı yukarıdaki tabloya göre tamamlayın.
4. Arduino'nuzu bilgisayara bağlayın, doğru portu ve kartı seçip kodu yükleyin.
5. Hata ayıklama veya kalibrasyon için **Seri Port Ekranını** (`9600 baud` hızında) açarak sağ ve sol sensör değerlerini canlı olarak izleyebilirsiniz.

## Kalibrasyon ve İnce Ayar

Kullanacağınız ortamın ışık şiddetine göre kod içindeki şu değişkenleri optimize edebilirsiniz:

* `tolerans = 15;`: Motor gereksiz yere çok fazla hareket ediyor veya titriyorsa bu değeri yükseltin. Çok geç tepki veriyorsa düşürün.
* `hareketHizi = 50;`: Her bir derecelik adım atıldığında motorun bekleme süresidir (milisaniye cinsinden). Hareketin akıcılığını ayarlamak için değiştirebilirsiniz.
