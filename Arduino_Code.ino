// df to write values please

#include <Counter.h>
#include <Timer.h>
  
  const int i0 = A0;// ip sensor
  const int i1 = A1;// sort area
  const int i2 = A2;// hopper full
  const int i3 = A3;// ring assembled
  const int i4 = A4;// component detect
  const int i5 = A5;// reject area
  const int i6 = A6;//start button
  const int i7 = A7;// stop button
  const int i8 = A8;// belt peg detect
  const int i9 = A9;// sort solenoid return
  const int i10 = A10;// reject solenoid return

  bool I0; // ip sensor
  bool I1; // sort area
  bool I2; // hopper full
  bool I3; // ring assembled
  bool I4; // component detect
  bool I5; // reject area
  bool I6; //start button
  bool I7; // stop button
  bool I8; // belt peg detect
  bool I9; // sort solenoid return
  bool I10; // reject solenoid return

  const int o0 = 2; // chain motor
  const int o1 = 3;// sort solenoid
  const int o2 = 4;// rotary solenoid
  const int o3 = 5;// reject solenoid
  const int o4 = 6;// belt motor

  bool O0; // chain motor
  bool O1; // sort solenoid
  bool O2; // rotary solenoid
  bool O3; // reject solenoid
  bool O4; // belt motor
  
  bool F0;
  bool F1;
  bool F2;
  
  Count C1; // counter 1
  Time T1; //tmer 1
  Time T2; // tmer2
  Time T3; // timer3
  
void setup(){
  void IO();
}

void loop() {
  Input();  
  C1.CTU(C1.CU, C1.RES, C1.PV=5, C1.CV, C1.DN); // initialize counter with preset 5
  T1.TON(T1.EN, T1.RES, T1.PT=3, T1.BASE = "Seconds", T1.DN, T1.TT, T1.ET); //initialize timer 1 with preset 3
  T2.TON(T2.EN, T2.RES, T2.PT=3, T2.BASE = "Seconds", T2.DN, T2.TT, T2.ET); //initialize timer 2 with preset 3
  T3.TON(T3.EN, T3.RES, T3.PT=0.5, T3.BASE = "Seconds", T3.DN, T3.TT, T3.ET); //initialize timer 3 with preset 0.5

  rung0();
  rung1();
  rung2();
  rung3();
  rung4();
  rung5();
  rung6();
  rung7();
  rung8();
  rung9();
  rung10();
  rung11();
  rung12();
  rung13();  
  
  Output();
}

void rung0(){
   if ((I6||F0) && !I7){
   F0= true;
 }else{
   F0= false;
  }
}

void rung1(){
   if (F0 == true){
   O0= true;
   O1= true;
 }else{
   O0= false;
   O1= false;
  }
}


void rung2(){
   if ((I0||F1) && !T1.DN){
   F1= true;
 }else{
   F1= false;
  }
}

void rung3(){
   if (I0){
    T1.EN= true;
 }else{
   T1.EN= false;
  }
}

void rung4(){
   if (T1.DN){
    T1.RES=true;
 }else{
    T1.RES=false;
  }
}

void rung5(){
   if (!F1 && I1 && !C1.CU){
   O1= true;
 }else{
   O1= false;
  }
}

void rung6(){
   if (O1){
    C1.CU= true;
 }else{
    C1.CU= false;
  }
}

void rung7(){
  if (O2){
    C1.DN= true;
  }else{
    C1.DN= false;
  }
}

void rung8(){
  if (O1){
    F2= true;
  }else{
    F2= false;
  }
}

void rung9(){
  if (O1){
    T2.EN= true;
  }else{
    T2.EN= false;
  }
}

void rung10(){
  if (T2.DN){
    T2.RES= true;
    F2=false;
  }else{
    T2.RES= false;
    F2=true;
  }
}

void rung11(){
  if (!I2){
    T3.EN= true;
  }else{
    T3.EN= false;
  }
}

void rung12(){
  if (T3.DN){
    T3.RES= true;
  }else{
    T3.RES= false;
  }
}

void rung13(){
  if (!F2 && T3.DN && !C1.DN){
    O2= true;
  }else{
    O2= false;
  }
}

void Input(){

// inverting the digital read command is to ensure the correct input logic state because of the synching input of the Arduino Mega

  I0=!digitalRead(i0);
  I1=!digitalRead(i1);
  I2=!digitalRead(i2);
  I3=!digitalRead(i3);
  I4=!digitalRead(i4);
  I5=!digitalRead(i5);
  I6=!digitalRead(i6);
  I7=!digitalRead(i7);
  I8=!digitalRead(i8);
  I9=!digitalRead(i9);
  I10=!digitalRead(i10);
   
}

void Output(){
  digitalWrite (O0,o0);
  digitalWrite (O1,o1);
  digitalWrite (O2,o2);
  digitalWrite (O3,o3);
  digitalWrite (O4,o4);

}

void IO(){
  pinMode(i0, INPUT);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(i4, INPUT);
  pinMode(i5, INPUT);
  pinMode(i6, INPUT);
  pinMode(i7, INPUT);
  pinMode(i8, INPUT);
  pinMode(i9, INPUT);
  pinMode(i10, INPUT);

  pinMode(o0, OUTPUT);
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(o3, OUTPUT);
  pinMode(o4, OUTPUT);

  digitalWrite(o0, false);
  digitalWrite(o1, false);
  digitalWrite(o2, false);
  digitalWrite(o3, false);
  digitalWrite(o4, false);

  F1= false;
  F2= false;

}