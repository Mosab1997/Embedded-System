const int Led1=6;
const int Led2=7;
const int Led3=8;
const int Led4=9;
const int Led5=10;
const int Led6=11;
const int Led7=12;
const int Led8=13;
void setup()
{
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
}

void loop()
{

  digitalWrite(Led1, HIGH);
  delay(781); // Wait for 750 millisecond(s)
  digitalWrite(Led1, LOW);
  delay(515); // Wait for 350 millisecond(s)
  
  digitalWrite(Led2, HIGH);
  delay(2014); // Wait for 400 millisecond(s)
  digitalWrite(Led2, LOW);
  delay(1348); // Wait for 600 millisecons(s)

  digitalWrite(Led3, HIGH);
  delay(343); // Wait for 400 millisecond(s)
  digitalWrite(Led3, LOW);
  delay(573); // Wait for 600 millisecons(s)

  digitalWrite(Led4, HIGH);
  delay(678); // Wait for 400 millisecond(s)
  digitalWrite(Led4, LOW);
  delay(1839); // Wait for 600 millisecons(s)

  digitalWrite(Led5, HIGH);
  delay(342); // Wait for 750 millisecond(s)
  digitalWrite(Led5, LOW);
  delay(534); // Wait for 350 millisecond(s)
  
  digitalWrite(Led6, HIGH);
  delay(1478); // Wait for 400 millisecond(s)
  digitalWrite(Led6, LOW);
  delay(326); // Wait for 600 millisecons(s)

  digitalWrite(Led7, HIGH);
  delay(1859); // Wait for 400 millisecond(s)
  digitalWrite(Led7, LOW);
  delay(351); // Wait for 600 millisecons(s)

  digitalWrite(Led8, HIGH);
  delay(777); // Wait for 400 millisecond(s)
  digitalWrite(Led8, LOW);
  delay(888); // Wait for 600 millisecons(s)
}
