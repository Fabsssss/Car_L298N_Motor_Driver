#include <Arduino.h>
#include <string>
#include "BluetoothSerial.h"
#include "L298N_Motor_Driver.hpp"
#include <vector>
#include <sstream>

L298N_Motor_Driver md(4,0,2,16,17,5);
BluetoothSerial bt;
std::string msg = "";



std::vector<std::string> splitString(const std::string& str) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        result.push_back(token);
    }
    return result;
}

bool stringToBool(const std::string& str) {
    std::istringstream iss(str);
    bool val;
    iss >> std::boolalpha >> val;
    return val;
}


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
        }else{
            std::vector<std::string> vec = splitString(msg);
            if(vec.size() >= 4){
            md.gib_mir_einfach_genau_das_was_du_willst(std::stoi(vec[0]),std::stoi(vec[1]),stringToBool(vec[2]),stringToBool(vec[3]));
            }else{
                Serial.println("irgendwas stimmt da nicht!");
            }
            vec.clear();
        }
        msg = "";
    }

}

