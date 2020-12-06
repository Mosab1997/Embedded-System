int ledPin = 3;      // LED connected to digital pin 9
int analogPin = A0;   // potentiometer connected to analog pin 3
int val1 = 0;         // variable to store the read value
//multimeter
int analogInput = A1;
float Vout = 0.00;
float Vin = 0.00;
float R1 = 100000.00; // resistance of R1 (100K) 
float R2 = 10000.00; // resistance of R2 (10K) 
int val = 0;



void setup() {
  pinMode(ledPin, OUTPUT);  // sets the pin as output
  // Multimeter
   pinMode(analogInput, INPUT); //assigning the input port
   Serial.begin(9600); //BaudRate
}

void loop() {
  val1 = analogRead(analogPin);  // read the input pin
  analogWrite(ledPin, val1 / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  
  //Multimeter
  val = analogRead(analogInput);//reads the analog input
   Vout = (val * 5.00) / 1024.00; // formula for calculating voltage out i.e. V+, here 5.00
   Vin = Vout / (R2/(R1+R2)); // formula for calculating voltage in i.e. GND
   if (Vin<0.09)//condition 
   {
     Vin=0.00;//statement to quash undesired reading !
  } 
Serial.print("\t Voltage of the given source = ");
Serial.println(Vin);
delay(1000); //for maintaining the speed of the output in serial moniter
  
}
