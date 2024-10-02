#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led1(LED_PIN, LED_ACT);
LED led2(LED_PIN_2, LED_ACT);

void btnPush();
void btnHold();
void btnDoubleClick();

OneButton button(BTN_PIN, !BTN_ACT);

bool isLed1Active = true;

void setup()
{
    led1.off();
    led2.off();
    button.attachClick(btnPush);          
    button.attachDoubleClick(btnDoubleClick);  
    button.attachLongPressStart(btnHold);
}

void loop()
{
    led1.loop();
    led2.loop(); 
    button.tick(); 
}


void btnPush()
{
    if (isLed1Active) {
        led1.flip();
    } else {
        led2.flip(); 
    }
}

void btnHold()
{
    if (isLed1Active) {
        led1.blink(200); 
    } else {
        led2.blink(200); 
    }
}

void btnDoubleClick()
{
    if (isLed1Active) {
        led1.off();
        led2.on();
        isLed1Active = false;
    } else {
        led2.off();
        led1.on();
        isLed1Active = true;
    }
}