#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/adc.h>

// Blink the LED to show we're on
static tADC *adc[2];
static tBoolean initialize = false;

tBoolean blink_on = true;
tMotor *Servo1;
tMotor *Servo2;
const float b_side = 500f;
const float b_front = 500f;

void initIRSensor(void){
    if (initialize){
        return;
    }
    initialize = true;

adc[0] = InitializeADC(PIN_D0);
adc[1] = InitializeADC(PIN_D1);


}

void IRSensorRead (void){

Printf( "IR values: %1.3f %1.3f/r",
        ADCRead(adc[0]),
        ADCRead(adc[1])
   );
   Printf("\n");
}


void blink(void) {
    SetPin(PIN_F3, blink_on);
   
   blink_on = !blink_on;
}


// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
   CallEvery(blink, 0, 0.5);
    Servo1= InitializeServoMotor(PIN_B3, false);   
    Servo2= InitializeServoMotor(PIN_C4, true);  
    initIRSensor();    
   tTime delay = 0.1;
     while (1) {
        // Runtime code can go here
SetMotor(Servo1, .5f)
SetMotor(Servo2, .5f)
IRSensorRead();

if (adc[0] < b_side){
    SetMotor(Servo1, .5f);
    SetMotor(Servo2, -.5f);
 
   if(adc[1] <= b_front){
    SetMotor(Servo1, .5f);
    SetMotor(Servo2, 0f);
    }
}
else if (adc[0] > b_side){
    SetMotor(Servo1, -.5f);
    SetMotor(Servo2, .5f);

    if(adc[1] <= b_front){
    SetMotor(Servo1, .5f);
    SetMotor(Servo2, 0f);
    {
}
else if (adc[0] = b_side) {
    SetMotor(Servo1, .5f);
    SetMotor(Servo2, .5f);
   
    if(adc[1] <= b_front){
    SetMotor(Servo1, .5f);
    SetMotor(Servo2, 0f);
    }
}        
        Wait(delay);
    }
}
