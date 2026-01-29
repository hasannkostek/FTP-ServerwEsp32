**NOT:** Bu proje Kablosuz Ağlar dersi için grup ödevi olarak geliştirilmiştir. Benim katkım sistem entegrasyonu ve test süreçleri üzerinedir.

# 📂 FTP Server with ESP32 (Bu proje Dr. Öğr. Üyesi Hasan SERDAR hocamızın "Kablosuz Ağlar" dersi için yapılmıştır.)

Bu proje, **ESP32** mikrodenetleyicisini bağımsız bir **FTP Sunucusu** ve **WiFi Erişim Noktası (AP)** olarak kullanmanızı sağlar. ESP32, kendi WiFi ağını oluşturur ve bağlanan cihazların (bilgisayar, telefon vb.) ESP32 üzerindeki SD karta dosya yüklemesine veya var olan dosyaları indirmesine olanak tanır.

## 🚀 Özellikler

* **SoftAP Modu:** ESP32 kendi WiFi ağını yayar (Modem gerektirmez).
* **FTP Protokolü:** FileZilla, WinSCP veya Windows Dosya Gezgini ile tam uyumlu.
* **SD Kart Desteği:** Dosyalar SD kart üzerinde saklanır.
* **Tak & Çalıştır:** Enerji verildiği anda sunucu aktif olur.

## 🛠️ Donanım Gereksinimleri

* ESP32 Geliştirme Kartı (ESP32 DevKit V1 vb.)
* Micro SD Kart Modülü
* Micro SD Kart (FAT32 formatlı)
* Jumper Kablolar

## 🔌 Pin Bağlantıları

Kod içerisinde **Chip Select (CS)** pini `GPIO 5` olarak ayarlanmıştır. Standart SPI bağlantısı şu şekildedir:

| SD Kart Modülü | ESP32 Pin |
| :--- | :--- |
| **CS** | **GPIO 5** |
| SCK | GPIO 18 |
| MISO | GPIO 19 |
| MOSI | GPIO 23 |
| VCC | 5V / 3.3V |
| GND | GND |

> **Not:** Kod içerisinde MISO hattı için `INPUT_PULLUP` (Pin 19) tanımlaması yapılmıştır, bu sayede okuma hatalarının önüne geçilmesi hedeflenmiştir.

## ⚙️ Kurulum ve Kullanım

1.  Bu repodaki kodu Arduino IDE ile açın.
2.  Gerekli kütüphanelerin yüklü olduğundan emin olun:
    * `WiFi.h` (ESP32 Core ile gelir)
    * `SD.h` (ESP32 Core ile gelir)
    * `ESP32FtpServer.h` (Kütüphane yöneticisinden veya GitHub'dan eklenmelidir)
3.  Kodu ESP32 kartınıza yükleyin.

### Bağlantı Bilgileri

Cihaz çalıştıktan sonra aşağıdaki bilgilerle bağlanabilirsiniz:

**1. WiFi Ağına Bağlanın:**
* **SSID (Ağ Adı):** `FTH`
* **Şifre:** `admin123`

**2. FTP İstemcisi ile Bağlanın:**
Bilgisayarınızdan (FileZilla vb.) veya telefonunuzdan şu bilgilerle giriş yapın:
* **Sunucu (Host):** `192.168.4.1` (Varsayılan ESP32 AP IP adresi)
* **Kullanıcı Adı:** `esp32`
* **Şifre:** `esp32`
* **Port:** `21`

## 📸 Ekran Görüntüleri & Seri Port Çıktısı

Seri monitör (Baud: 115200) üzerinden bağlantı durumunu takip edebilirsiniz:

```text
Erişim noktası açıldı
AP IP adres: 192.168.4.1
SD karta bağlandı!
```
**NOT:** Bu proje Kablosuz Ağlar dersi için grup ödevi olarak geliştirilmiştir. Benim katkım sistem entegrasyonu ve test süreçleri üzerinedir.
