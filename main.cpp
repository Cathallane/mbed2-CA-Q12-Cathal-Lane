#include "mbed.h"

// Define pins for the LEDs
PwmOut red(p21);
PwmOut green(p22);
PwmOut blue(p23);

// Defineing accelerometer pins
AnalogIn x_axis(p15);
AnalogIn y_axis(p16);
AnalogIn z_axis(p17);

int main() {
    while(1) {
        // Read the analog values from the accelerometer and map them to PWM values
        float x = x_axis.read();
        float y = y_axis.read();
        float z = z_axis.read();
        float max_value = 0.3;
        float duty_red = max_value * x;
        float duty_green = max_value * y;
        float duty_blue = max_value * z;

        // set values
        red.write(duty_red);
        green.write(duty_green);
        blue.write(duty_blue);

        wait(0.1);
    }
}