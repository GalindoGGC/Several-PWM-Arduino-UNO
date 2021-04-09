# Several-PWM-Arduino-UNO
Sketch to generate multiple PWMs.
We will use Timers 1 (pins 9 and 10) and Timer 2 (3 and 11). We won’t modify Timer 0 due to we will disrupt important time functions such as delay (), millis (), etc.
In order to generate the PWM we must modify the bits of the corresponding registers of each Timer. The description of the registers appears on the Arduino UNO's uC datasheet, the ATmega48A.
Basically we will reset the value of the registers to 0 and we will set the necessaries bits at 1 for achieve the desired behaviour.
Say that there have been behaviors that I haven’t been able to set up, such as the CTC in Timer 2.
I append the code of the sketch in which a PWM of duty cycle and variable frequency is generated and after a delay (only when starting) another 2 PWMs with variable frequency and pase-shifting are generated. Note that the characteristics of the PWM, frequency, duty cycle, pase-shifting of the PWM are completely configurable. I believe thet code is well mentioned to be able to modify it to your neecessity
