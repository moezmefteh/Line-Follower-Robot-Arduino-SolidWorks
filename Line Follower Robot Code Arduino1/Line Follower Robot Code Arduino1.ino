
int   in1 = 2  ;// moteur droite sens1
int   in2 = 4  ;// moteur droite sens2
int   in3 = 6  ;// moteur gauche sens1
int  in4 = 7 ;// moteur gauche sens2
int ena=3 ;
int enb=5 ;
int  sensor1 = A3  ; // sensor noir/blanc 1(*...)
int sensor2 = A2  ; // sensor noir/blanc 2(.*..)
int sensor3 = A1  ; // sensor noir/blanc 3(..*.)
int sensor4 = A0 ; // sensor noir/blanc 4(...*)
int sensor5 = A4 ;




int  s1, s2, s3, s4,s5, N = 0 ,v ;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600) ;
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
 

  pinMode(in1, OUTPUT) ;
  pinMode(in2, OUTPUT) ;
  pinMode(in3, OUTPUT) ;
  pinMode(in4, OUTPUT) ;

  
}
void loop() {
  // put your main code here, to run repeatedly:
//avanti() ;
 suiveur();

  /*A = digitalRead(a) + digitalRead(b) * 10 + digitalRead(c) * 100 + digitalRead(d) * 1000;
    Serial.println(A);*/
}
void arriere(void)
{ analogWrite(in1, 0) ;
  analogWrite(in2, 120) ;
  analogWrite(in3, 0) ;
  analogWrite(in4, 120) ;

}
void avant(void)
{ analogWrite(in1, 80) ;
  analogWrite(in2, 0) ;
  analogWrite(in3, 80) ;
  analogWrite(in4, 0) ;

}

void avanti(void)
{ digitalWrite(in1,1) ;
  digitalWrite(in2, 0) ;
  digitalWrite(in3,1) ;
  digitalWrite(in4, 0) ;
analogWrite(ena, 200) ;
  analogWrite(enb, 200) ;
}
void droite(void)
{ analogWrite(in1, 0) ;
  analogWrite(in2, 140) ;
  analogWrite(in3, 140) ;
  analogWrite(in4, 0) ;
}
void droitec(void)
  { analogWrite(in1, 0) ;
  analogWrite(in2, 120) ;
  analogWrite(in3, 120) ;
  analogWrite(in4, 0) ;
 
  }
void gauche(void)
{ analogWrite(in1, 140) ;
  analogWrite(in2, 0) ;
  analogWrite(in3, 0) ;
  analogWrite(in4, 140) ;

}
void gauchec(void)
  {analogWrite(in1,120) ;
  analogWrite(in2, 0) ;
  analogWrite(in3, 0) ;
  analogWrite(in4, 120) ;

  }
void pause(void)
{ digitalWrite(in1, 0) ;
  digitalWrite(in2, 0) ;
  digitalWrite(in3, 0) ;
  digitalWrite(in4, 0) ;
}
void capteurs(void)
{s1 = digitalRead(sensor1) ;
s2 = digitalRead(sensor2) ;
s3 = digitalRead(sensor3) ;
s4 = digitalRead(sensor4) ;
s5 = digitalRead(sensor5) ;
s1=!s1;
s2=!s2;
s3=!s3;
s4=!s4;
s5=!s5;
 /* s1 = analogRead(sensor1) ;
  s2 = analogRead(sensor2) ;
  s3 = analogRead(sensor3) ;
  s4 = analogRead(sensor4) ;
  if(s1>175) s1=1 ;
  else s1=0 ;
  if(s2>175) s2=1 ;
  else s2=0 ;
  if(s3>175) s3=1 ;
  else s3=0 ;
  if(s4>175) s4=1 ;
  else s4=0 ;*/
 Serial.print("   ");
 Serial.print(s1) ;
 Serial.print("   ");
 Serial.print(s2) ;
 Serial.print("   ");
 Serial.print("   ");
 Serial.print(s5) ;
 Serial.print("   ");
 Serial.print("   ");
 Serial.print(s3) ;
 Serial.print("   ");
 Serial.print(s4) ;
 Serial.println("   ");
}
void reculer(void)
{ digitalWrite(in1, 0) ;
  digitalWrite(in2, 1) ;
  digitalWrite(in3, 0) ;
  digitalWrite(in4, 1) ;
}
void suiveur(void)
{

  capteurs() ;
//if((s1==1)&&(s4==1))
//{pause() ;
//delay(5000) ;
//while((s1==1)||(s4==1))
//{
//  avant() ;
//  capteurs() ;
//}
//}
if(s5==1)
{avanti() ;
if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0)) N=3 ;
else if((s1==1)&&(s4==0)) N=2 ;
else if((s1==0)&&(s4==1)) N=1 ;

}
else {
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0))
  {

    if (N == 1) {
      droite();
      //50821049 ridha
    }
    else if (N == 2) {
      gauche();
    }
    else if (N == 3) {
avant() ; 
    }
  }

  else if (((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0)) )
  {
    avant();
    N = 3;
  }
  else if ((s1 == 1) && (s2 == 1) && (s3 == 1 ) && (s4 == 1))
{
   
  
    avant() ;
  
}
  else if ( ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1))||((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1)))
  {
    droite();
  N=1 ;  
  }
  else if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0))
droitec() ;
  else if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1))
  {
  N=1;
droite() ;
  }
  else if ( ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0))||((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0)))
  {
    gauche();
    N=2 ;
  }
  else if((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0))
gauchec() ;
  else if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0))
  {N=2 ;
gauche() ;
  }
}}
