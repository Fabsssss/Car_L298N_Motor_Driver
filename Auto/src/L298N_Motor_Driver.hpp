#include <Arduino.h>
class L298N_Motor_Driver
{
private:
int motor1pin1 = 0;
int motor1pin2 = 0;
int enablemotor1pin = 0;

int motor2pin1 = 0;
int motor2pin2 = 0;
int enablemotor2pin = 0;

const int freq = 30000;
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int resolution = 8;

int motor_initalsiert = 0;

public:
    L298N_Motor_Driver(int motor1pin1,int motor1pin2,int enablemotor1pin);
    L298N_Motor_Driver(int motor1pin1,int motor1pin2,int enablemotor1pin, int motor2pin1,int motor2pin2, int enablemotor2pin);
    void Fahre_gradeaus();
    void Fahre_gradeaus(int geschwindigkeit);
    void Fahre_rueckwaerts();
    void Fahre_rueckwaerts(int geschwindigkeit);
    void Rechts_abbiegen();
    void Rechts_abbiegen(int geschwindigkeit);
    void Links_abbiegen();
    void Links_abbiegen(int geschwindigkeit);
    void Auto_drehen_rechts();
    void Auto_drehen_rechts(int geschwindigkeit);
    void Auto_drehen_links();
    void Auto_drehen_links(int geschwindigkeit);
    void Auto_stop();
};
