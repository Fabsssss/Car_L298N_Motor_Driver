#include <Arduino.h>
#include "L298N_Motor_Driver.hpp"
    /**
     * Diese Funktion ist dafür wenn man nur eine seites des Motors benutzen will
     * 
     * @param motor1pin1 Für input 1 
     * @param motor1pin2 Für input 2 
     * @param enablemotor1pin Pin an dem der enable 1 angeschlossen ist  
     */
    L298N_Motor_Driver::L298N_Motor_Driver(int motor1pin1,int motor1pin2,int enablemotor1pin){
        this->motor1pin1 = motor1pin1;
        this->motor1pin2 = motor1pin2;
        this->enablemotor1pin = enablemotor1pin;
        pinMode(motor1pin1, OUTPUT);
        pinMode(motor1pin2, OUTPUT);
        pinMode(enablemotor1pin, OUTPUT);
        ledcSetup(pwmChannel1, freq, resolution);
        ledcAttachPin(enablemotor1pin, pwmChannel1);
        motor_initalsiert = 1;
    }

    L298N_Motor_Driver::L298N_Motor_Driver(int motor1pin1,int motor1pin2,int enablemotor1pin, int motor2pin1,int motor2pin2, int enablemotor2pin){
        this->motor1pin1 = motor1pin1;
        this->motor1pin2 = motor1pin2;
        this->enablemotor1pin = enablemotor1pin;
        this->motor2pin1 = motor2pin1;
        this->motor2pin2 = motor2pin2;
        this->enablemotor2pin = enablemotor2pin;
        pinMode(motor1pin1, OUTPUT);
        pinMode(motor1pin2, OUTPUT);
        pinMode(enablemotor1pin, OUTPUT);
        pinMode(motor2pin1, OUTPUT);
        pinMode(motor2pin2, OUTPUT);
        pinMode(enablemotor2pin, OUTPUT);
        ledcSetup(pwmChannel1, freq, resolution);
        ledcSetup(pwmChannel2, freq, resolution);
        ledcAttachPin(enablemotor1pin, pwmChannel1);
        ledcAttachPin(enablemotor2pin, pwmChannel2);
        motor_initalsiert = 2;
    }

    

    //Geschwindigkeit zwischen 1 und 100 Wählen
    void L298N_Motor_Driver::Fahre_gradeaus(int geschwindigkeit){
        if(motor_initalsiert == 1){
            ledcWrite(pwmChannel1, geschwindigkeit);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, geschwindigkeit);
            ledcWrite(pwmChannel2, geschwindigkeit);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, HIGH); 
        }
        Serial.println("Moving Forward");
    }

    void L298N_Motor_Driver::Fahre_gradeaus(){
        if(motor_initalsiert == 1){
            ledcWrite(pwmChannel1, 255);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 255);
            ledcWrite(pwmChannel2, 255);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, HIGH); 
        }
        Serial.println("Moving Forward");
    }
    


    void L298N_Motor_Driver::Fahre_rueckwaerts(){
        if(motor_initalsiert == 1){
            ledcWrite(pwmChannel1, 255);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor1pin1, HIGH); 
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 255);
            ledcWrite(pwmChannel2, 255);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor1pin1, HIGH); 
            digitalWrite(motor2pin2, LOW);
            digitalWrite(motor2pin1, HIGH); 
        }
        Serial.println("Moving Backward");
    }

    //Geschwindigkeit zwischen 1 und 100 Wählen
    void L298N_Motor_Driver::Fahre_rueckwaerts(int geschwindigkeit){
        if(motor_initalsiert == 1){
            ledcWrite(pwmChannel1, geschwindigkeit);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor1pin1, HIGH); 
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, geschwindigkeit);
            ledcWrite(pwmChannel2, geschwindigkeit);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor1pin1, HIGH); 
            digitalWrite(motor2pin2, LOW);
            digitalWrite(motor2pin1, HIGH); 
        }
        Serial.println("Moving Backward");
    }




    void L298N_Motor_Driver::Auto_drehen_links(){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 255);
            ledcWrite(pwmChannel2, 255);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor1pin1, HIGH); 
            digitalWrite(motor2pin2, HIGH);
            digitalWrite(motor2pin1, LOW); 
        } 
    }

    //Geschwindigkeit zwischen 1 und 100 Wählen
    void L298N_Motor_Driver::Auto_drehen_links(int geschwindigkeit){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, geschwindigkeit);
            ledcWrite(pwmChannel2, geschwindigkeit);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor1pin1, HIGH); 
            digitalWrite(motor2pin2, HIGH);
            digitalWrite(motor2pin1, LOW); 
        }   
    }

    
    void L298N_Motor_Driver::Auto_drehen_rechts(){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 255);
            ledcWrite(pwmChannel2, 255);
            digitalWrite(motor1pin2, HIGH);
            digitalWrite(motor1pin1, LOW); 
            digitalWrite(motor2pin2, LOW);
            digitalWrite(motor2pin1, HIGH); 
        } 
    }

    //Geschwindigkeit zwischen 1 und 100 Wählen
    void L298N_Motor_Driver::Auto_drehen_rechts(int geschwindigkeit){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, geschwindigkeit);
            ledcWrite(pwmChannel2, geschwindigkeit);
            digitalWrite(motor1pin2, HIGH);
            digitalWrite(motor1pin1, LOW); 
            digitalWrite(motor2pin2, LOW);
            digitalWrite(motor2pin1, HIGH); 
        }   
    }



    void L298N_Motor_Driver::Rechts_abbiegen(int geschwindigkeit){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 255);
            ledcWrite(pwmChannel2, geschwindigkeit);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, HIGH); 
        }  
    }
    void L298N_Motor_Driver::Rechts_abbiegen(){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 255);
            ledcWrite(pwmChannel2, 175);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, HIGH); 
        }  
    }
    void L298N_Motor_Driver::Links_abbiegen(int geschwindigkeit){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, geschwindigkeit);
            ledcWrite(pwmChannel2, 255);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, HIGH); 
        }  
    }
    void L298N_Motor_Driver::Links_abbiegen(){
        if(motor_initalsiert == 1){
            Serial.println("Es müssen 2 Motor initalsisiert werden");
        }
        if(motor_initalsiert == 2){
            ledcWrite(pwmChannel1, 175);
            ledcWrite(pwmChannel2, 255);
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH); 
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, HIGH); 
        }  
    }

    void L298N_Motor_Driver::Auto_stop(){
            ledcWrite(pwmChannel1, 0);
            ledcWrite(pwmChannel2, 0);
    }


