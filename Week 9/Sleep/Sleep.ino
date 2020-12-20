void setup() {
  // put your setup code here, to run once:
char *adcsra =(char *)0x7A;
char *acsr =(char *)0x50;
*adcsra= 0;
*acsr=1 << 7;
Sleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void Sleep(){
  char *smcr= (char *)0x53;

  *smcr=5;
  asm("sleep");
  
  
}
