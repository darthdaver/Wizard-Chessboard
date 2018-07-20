#include "mbed.h"

#define STEPS 130

DigitalOut EN(D8);
DigitalOut X_DIR(D5);
DigitalOut Y_DIR(D6);
DigitalOut X_STP(D2);
DigitalOut Y_STP(D3);

DigitalOut POWER_CNC(PC_8);
DigitalOut POWER_MAGNET(PB_12);

InterruptIn btn_up(PC_4);
InterruptIn btn_down(PB_13);
InterruptIn btn_right(PB_14);
InterruptIn btn_left(PB_15);

void step (bool dir, DigitalOut dirPin, DigitalOut stepperPin, int steps)
{
    dirPin = dir;
    wait_ms(50);
    for (int i = 0; i < steps; i++) {
        stepperPin = true;
        wait_us(800);
        stepperPin = false;
        wait_us(800);
    }
}

void right()
{
    POWER_CNC = true;
    POWER_MAGNET = true;
    wait(0.6);
    step(true, X_DIR, X_STP, STEPS);
    POWER_MAGNET = false;
    POWER_CNC = false;
}

void left()
{
    POWER_CNC = true;
    POWER_MAGNET = true;
    wait(0.6);
    step(false, X_DIR, X_STP, STEPS);
    POWER_MAGNET = false;
    POWER_CNC = false;
}

void up()
{
    POWER_CNC = true;
    POWER_MAGNET = true;
    wait(0.6);
    step(false, Y_DIR, Y_STP, STEPS);
    POWER_MAGNET = false;
    POWER_CNC = false;
}

void down()
{
    POWER_CNC = true;
    POWER_MAGNET = true;
    wait(0.6);
    step(true, Y_DIR, Y_STP, STEPS);
    POWER_MAGNET = false;
    POWER_CNC = false;
}

int main() {

    EN = false;
    POWER_MAGNET = false;
    POWER_CNC = false;
    
    btn_up.mode(PullUp);
    btn_up.fall(&up);
    
    btn_down.mode(PullUp);
    btn_down.fall(&down);
    
    btn_right.mode(PullUp);
    btn_right.fall(&right);
    
    btn_left.mode(PullUp);
    btn_left.fall(&left);
}