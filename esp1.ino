#include <WiFi.h>

#include "ESP32FtpServer.h"



const char* apSSID     = "FTH";    // Wifi İsmimiz

const char* apPassword = "admin123";      // Şifremiz



FtpServer ftpSrv;



// SD kart seçim pini

#define SD_CS 5



void setup(void) {

  Serial.begin(115200);



  // ESP 32 Erişim Yetkileri

  WiFi.softAP(apSSID, apPassword);

  Serial.println("Erişim noktası açıldı");

  Serial.print("AP IP adres: ");

  Serial.println(WiFi.softAPIP());



  pinMode(19, INPUT_PULLUP);




  if (SD.begin(SD_CS)) {

    Serial.println("SD karta bağlandı!");

    // Ftp Server için kullanıcı adı ve şifre

    ftpSrv.begin("esp32", "esp32");

  } else {

    Serial.println("SD karta bağlanamadı!");

  }

}



void loop(void) {

  ftpSrv.handleFTP();

}