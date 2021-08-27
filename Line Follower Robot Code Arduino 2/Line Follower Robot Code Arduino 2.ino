
int   in1 = 2  ;// moteur droite sens1
int   in2 = 3  ;// moteur droite sens2
int   in3 = 4  ;// moteur gauche sens1
int   in4 = 5 ;// moteur gauche sens2
int ena=9 ;
int enb=10 ;
int sensor1 = A4  ; // sensor noir/blanc 1(*...)
int sensor2 = A3  ; // sensor noir/blanc 2(.*..)
int sensor3 = A1  ; // sensor noir/blanc 3(..*.)
int sensor4 = A0  ; // sensor noir/blanc 4(...*)
int sensor5 = A2  ;

int  s1, s2, s3, s4,s5,x,y;


void setup() {
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
  pinMode(ena, OUTPUT) ;
  pinMode(enb, OUTPUT) ;

  
}
void loop() {

  capteurs() ;

if ((s5==1)&(s1==0)&(s2==0)&(s3=0)&(s4=0)){
  avance(180,180);
  Serial.println("avant");
}
else if((s5==1)&(s1==0)&(s2==1)&(s3=0)&(s4=0)){
  avance(180,100);
  Serial.println("gauche1");
}
     else if((s5==0)&(s1==1)&(s2==1)&(s3=0)&(s4=0)){
      avance(180,0);
      Serial.println("gauche2");
     }
          else if((s5==0)&(s1==1)&(s2==0)&(s3=0)&(s4=0)){
            gauche(180,100);
            Serial.println("gauche3");
          }
               else if((s5==1)&(s1==0)&(s2==0)&(s3=1)&(s4=0)){
                 avance(100,180);
                 Serial.println("droite1");
               }
                    else if((s5==0)&(s1==0)&(s2==0)&(s3=1)&(s4=1)){
                      avance(0,180);
                      Serial.println("droite2");
                    }
                         else if((s5==0)&(s1==0)&(s2==0)&(s3=0)&(s4=1)){
                          droite(100,180);
                          Serial.println("droite3");
                         }
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
 Serial.print("   ");
 Serial.print(s4) ;
 Serial.print("   ");
 Serial.print(s3) ;
 Serial.print("   ");
 Serial.print("   ");
 Serial.print(s5) ;
 Serial.print("   ");
 Serial.print("   ");
 Serial.print(s2) ;
 Serial.print("   ");
 Serial.print(s1) ;
 Serial.print("   ");
 Serial.println("   ");

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
  else s4=0 ;
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
 */
}
void droite(int x,int y){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(ena,x);
analogWrite(enb,y);
}
void gauche(int x,int y){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ena,x);
analogWrite(enb,y);
}

void avance(int x,int y){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ena,x);
analogWrite(enb,y);
}
