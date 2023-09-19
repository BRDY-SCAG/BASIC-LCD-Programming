/*
  Showing number 0-9 on a Common Anode 7-segment LED display

  Displays the numbers 0-9 on the display, with one second inbetween.
    A

   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

  This example code is in the public domain.
 */
extern "C"{
  void setup_ports();
  void display_segment();
}

extern byte segment;
extern byte digit;
// Pin 2-8 is connected
//  to the 7 segments of the display.

extern
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

// the setup routine
//  runs once when you press reset:
void setup() {                
  // initialize
//  the digital pins as outputs.
/*
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     

  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT); 

 */
 Serial.begin(9600);
  setup_ports();
}

// the loop routine runs over
 // and over again forever:
void loop() {
 /* digitalWrite(D1, LOW); // POSITION HIGH = 0ff, l0w = 0n
  digitalWrite(D2, HIGH);// EXAMPlE LOW is set to D1, meaning the first position will be where the number appears
  digitalWrite(D3, HIGH);       D2 having low means the second position etc.
  digitalWrite(D4, HIGH); 
  
  digitalWrite(pinA,  HIGH);  SEGMENT :: HIGH = ON, LOW = OFF 
  digitalWrite(pinB, HIGH);  
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF,  HIGH);   
  digitalWrite(pinG, LOW);
*/
  segment = 0;            // AVR CALLS FOR DISPLAY
  digit = 0;
  display_segment();   
  delay(1000);               // wait 1 second (0)
/*
  digitalWrite(pinA,  LOW);   // HIGH lights up the segment LETTER(A,B,C,D, etc.)
  digitalWrite(pinB, HIGH);   //LOW has the light off
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF,  LOW);   
  digitalWrite(pinG, LOW);
*/
 segment = 01;
 digit = 1;
 display_segment(); 
  delay(1000);               // wait for a second
  
 /* digitalWrite(D1, HIGH); // POSITION HIGH = 0ff, l0w = 0n
  digitalWrite(D2, LOW);// EXAMPlE LOW is set to D1, meaning the first position will be where the number appears
  digitalWrite(D3, HIGH);       D2 having low means the second position etc.
  digitalWrite(D4, HIGH); 
  
  digitalWrite(pinA,  HIGH);  SEGMENT :: HIGH = ON, LOW = OFF 
  digitalWrite(pinB, HIGH);  
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF,  LOW);   
  digitalWrite(pinG, LOW);
*/

  //2 
  segment = 02;
  digit = 2;
 display_segment();    
  delay(1000);               // wait for a second

 /* digitalWrite(D1, HIGH); // POSITION HIGH = 0ff, l0w = 0n
  digitalWrite(D2, HIGH);// EXAMPlE LOW is set to D1, meaning the first position will be where the number appears
  digitalWrite(D3, LOW);       D2 having low means the second position etc.
  digitalWrite(D4, HIGH); 
  
  digitalWrite(pinA,  HIGH);  SEGMENT :: HIGH = ON, LOW = OFF 
  digitalWrite(pinB, HIGH);  
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF,  LOW);   
  digitalWrite(pinG, LOW);
*/
//3
  segment = 03;
  digit = 3;
 display_segment();   
  delay(1000);               // wait for a second


  
  //4

  segment = 00;
  digit = 4;
 display_segment();    
  delay(1000);
               // wait for a second
 
  //5
 
  segment = 01;
  digit = 5;
 display_segment();    
  delay(1000);               // wait for a second

  
  //6

 segment = 02;
 digit = 6;
 display_segment();    
  delay(1000);               // wait for a second
 
  //7

 segment = 03;
 digit = 7;
 display_segment();    
  delay(1000);               // wait for a second

  
  //8
 
  segment = 00;
  digit = 8;
 display_segment();
  delay(1000);               // wait for a second

  //9

 segment = 01;
 digit = 9;
 display_segment();
       
  delay(1000);               // wait for a second

}
