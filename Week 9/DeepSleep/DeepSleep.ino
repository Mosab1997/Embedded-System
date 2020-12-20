void setup() {
  // put your setup code here, to run once:
char *adcsra =(char *)0x7A;
char *acsr =(char *)0x50;
*adcsra= 0;
*acsr=1 << 7;
DeepSleep();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void DeepSleep(){
  char *smcr= (char *)0x53;
  volatile char *mcucr= (char *) 0x55;

  *smcr=5;
  *mcucr = 0b01100000;
  *mcucr = 0b01000000;
  asm("sleep");
  
  
}
