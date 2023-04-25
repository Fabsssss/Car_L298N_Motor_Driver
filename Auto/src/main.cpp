#include <Arduino.h>

#include "L298N_Motor_Driver.hpp"

void setup() {
L298N_Motor_Driver md(5,17,16,4,0,2);
md.Fahre_gradeaus();
}

void loop() {

}