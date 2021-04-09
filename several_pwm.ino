// Timer 2 (8bits): pin 3 and 11 (11 do not work)
const int PMW_boost = 3;
void setup()
{ 
  TCCR2A=0;
  TCCR2B=0;
  TCNT2=0;
  pinMode(PMW_boost, OUTPUT);
} 
void loop() 
{
  float D = 0.25;
  pwm_boost(D);
}

void pwm_boost(float duty)
{
  // Select Mode 7: Fast PWM:
  //     f = f_clk / (N·(1+TOP)) ; TOP is OCR2A
  TCCR2A = _BV(COM2B1) | _BV(WGM21)| _BV(WGM20);
  // TCCR2A = (1<<COM2B1) + (1<<WGM21) + (1<<WGM20); // Set OC2B at bottom, clear OC2B at compare match
  TCCR2B = _BV(CS21)  // set prescale at 8
         | _BV(WGM22);  
  // TCCR2B = (1<<CS21) + (1<<WGM22);
  OCR2A = 249; // set desired frequency selecting OCR2A and prescaler
  OCR2B = duty*OCR2A;  // duty = (OCR2B/OCR2A)
  DDRD = _BV(PD3);
}
