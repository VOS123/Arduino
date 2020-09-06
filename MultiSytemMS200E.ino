//Stear Multisystem 

//Left turn
int LEDL1 = 13 ;
int LEDL2 = 12 ;
int LEDL3 = 11 ;

// Right turn
int LEDR1 = 10 ;
int LEDR2 = 9 ;
int LEDR3 = 8 ;

int SPEAKER1 = 2; 

int MIN_FREQ =  50 ;

void setup() {
  
  //Left turn
  pinMode( LEDL1, OUTPUT); 
  pinMode( LEDL2, OUTPUT); 
  pinMode( LEDL2, OUTPUT); 

  // Right turn
  pinMode( LEDR1, OUTPUT); 
  pinMode( LEDR2, OUTPUT); 
  pinMode( LEDR3, OUTPUT); 
  Serial.begin (9600 ); 
}

void loop() {

   int Pot1 =  analogRead(A0) ;
   int Pot2 =  analogRead(A1) ;
   int GasBreak =  analogRead(A2) ;
   int StearingWheel =  analogRead(A3) ;
   
   //Rocket (Pot1); 
   //Car (Pot1);
   //Turn(Pot2) ; 
   Drive(GasBreak,StearingWheel);
   
   
   digitalWrite(LEDL1, LOW);    
   digitalWrite(LEDL2, LOW);    
   digitalWrite(LEDL3, LOW);    
   digitalWrite(LEDR1, LOW);    
   digitalWrite(LEDR2, LOW);    
   digitalWrite(LEDR3, LOW);    
          
   //Serial.println("Potmeter 1:" + String(analogRead(A0)) );
   //Serial.println("Potmeter Step 1 to 10 :" + String( round(analogRead(A0)/ 200)  ) );

   delay ( 1000 ); 
} 


void Drive(int GasBreak,int StearingWheel) {
  // -----------GasBreak------------------------------------- 
  // Neutral    full gas  full break    full gas + full break 
  // 640-656    306-310   740-755       637 - 639 
  
  // ------StearingWheel----------- 
  // Neutral    left turn  right turn 
  // 665-668    453-458    774-778
  // 
  Serial.println("GasBreak: " + String(GasBreak)  );
  Serial.println("StearingWheel: " + String(StearingWheel)  );
}

void Car (int Pot) {
  // 6 SPEED 
 int PITCH ;

  switch ( round(Pot  / ( 1024 / 6 ))) {
    case 0:
    case 1:
      PITCH = MIN_FREQ + Pot / 3  ;
      //Serial.println("1e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 10) ;     
      break; 
    case 2:
      PITCH = MIN_FREQ + Pot / 2.5 ;
      //Serial.println("2e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 9.5) ;     
      break; 
    case 3:
      PITCH = MIN_FREQ + Pot  / 3 ;
      //Serial.println("3e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 9.0) ;     
      break; 
    case 4:
      PITCH = MIN_FREQ + Pot / 3  ;
      //Serial.println("4e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 7.5 ) ;     
      break; 
    case 5:
      PITCH = MIN_FREQ + Pot / 3;
      //Serial.println("5e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 7) ;     
      break; 
    case 6:
      PITCH = MIN_FREQ + Pot / 3;
      //Serial.println("6e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 6.5 ) ;     
      break; 
    case 7:
      PITCH = MIN_FREQ + Pot / 3 ;
      //Serial.println("7e versnelling, pot: " + String(Pot)  + " PITCH: "  + String(PITCH));
      tone( SPEAKER1, PITCH , 6) ;     
      break; 
  }
}

void Rocket (int Pot) {
    tone( SPEAKER1, MIN_FREQ + 10 + Pot, 100) ;     
    delay(10);
    tone( SPEAKER1, MIN_FREQ + 70 + Pot, 30) ;
    delay(10);
    tone( SPEAKER1, MIN_FREQ + 90 + Pot, 20) ;
    delay(10);
}


void Turn(int Pot){
  switch ( round(Pot/ 200) ) {
     case 1:    
       digitalWrite(LEDL1, HIGH);
       tone( SPEAKER1, MIN_FREQ  + Pot / 20 , 1) ;     
       delay(1);
       tone( SPEAKER1, MIN_FREQ + 5 + Pot / 20 , 1) ;
       delay(1); 
       break;
     case 2:
       digitalWrite(LEDL1, HIGH);
       digitalWrite(LEDL2, HIGH);
       tone( SPEAKER1, MIN_FREQ  + 20 + Pot / 4 , 50) ;     
       delay(20);
       tone( SPEAKER1, MIN_FREQ + 25 + Pot / 4 , 50) ;
       delay(20); 
       break;
     case 3:    
     case 4:    
       digitalWrite(LEDL2, LOW);       
       digitalWrite(LEDL3, HIGH);
       tone( SPEAKER1, MIN_FREQ  + 20 + Pot / 3 , 40) ;     
       delay(20);
       tone( SPEAKER1, MIN_FREQ + 25 + Pot / 3 , 40) ;
       delay(20); 
       break;
     case 5:    
       digitalWrite(LEDL3, HIGH);
       tone( SPEAKER1, MIN_FREQ  + 20 + Pot / 2 , 30) ;     
       delay(20);
       tone( SPEAKER1, MIN_FREQ + 25 + Pot / 2 , 30) ;
       delay(20); 
       break;
   }
}
