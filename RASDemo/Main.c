#include "RASDemo.h"
#include <RASLib/inc/motor.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>

tBoolean led_on;
tBoolean external;
tBoolen motor
void blink(void) {
    SetPin(PIN_F1, led_on);
    SetPin(PIN_F2, led_on);
    SetPin(PIN_B6, 
    SetPin(PIN_B3, external);
    SetPin(PIN_B3, !external);

    external = !external;


    led_on = !led_on;
}

int main(void) {  
    char ch;

    CallEvery(blink, 0, 4.1f);

    while (1) {
        Printf("\nRAS Demo for Robotathon 2013\n"
               "  0=UART Demo\n"
	       "  1=Motor Demo\n"
               "  2=Servo Demo\n"
	       "  3=I2C Line Sensor Demo\n"
               "  4=IR Sensor Demo\n"
	       "  5=Encoders Demo\n"
               "  6=GPIO Demo\n"
	       "  7=GPIO Line Sensor Demo\n"
               "  8=Sonar Demo\n"
               ">> ");
        
        // Read input from user
        ch = Getc();
        Printf("\n");

        switch(ch) {
            case '0':
                Printf("\nUART Demo\n");
                uartDemo();                 
                break;
            case '1':
                Printf("\nMotor Demo\n");
                initMotors();
                motorDemo(); 
                break;
            case '2':
                Printf("\nServo Demo\n");
                initServo();
                servoDemo();     
                break;
            case '3':
                Printf("\nLine Sensor Demo\n");
                initI2CLineSensor();          
                i2cLineSensorDemo();    
                break;
            case '4':                            
                Printf("\nIR Sensor Demo\n");
                initIRSensor();
                IRSensorDemo();     
                break;
            case '5':
                Printf("\nEncoders Demo\n");
                initEncoders();
                encoderDemo();
                break;
            case '6':
                Printf("\nGPIO Demo\n");
                gpioDemo();
                break;
            case '7':
                Printf("\nGPIO Line Sensor Demo\n");
                initGPIOLineSensor();
                gpioLineSensorDemo();
                break;
            case '8':
                Printf("\nSonar Demo\n");
                initSonar();
                sonarDemo();
                break;
        }
    }
}
