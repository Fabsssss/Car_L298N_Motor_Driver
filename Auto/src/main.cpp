#include <Arduino.h>
#include <string>
#include "BluetoothSerial.h"
#include "L298N_Motor_Driver.hpp"


L298N_Motor_Driver md(4,0,2,16,17,5);
BluetoothSerial bt;
std::string msg = "";

void setup() {
    Serial.begin(115200);
    bt.begin("ESP32test"); //Name des ESP32
    Serial.println("Der ESP32 ist bereit. Verbinde dich nun über Bluetooth.");
    md.Fahre_gradeaus();
}

void loop() {
    while (bt.available()) {
        msg += bt.read();
    }
    if(msg != ""){
        Serial.println(msg.c_str());
        if(msg == "0"){
            md.Auto_stop();
        }
        if(msg == "1"){
            md.Fahre_gradeaus();
        }
        if(msg == "2"){
            md.Fahre_rueckwaerts();
        }
        msg = "";
    }

}

