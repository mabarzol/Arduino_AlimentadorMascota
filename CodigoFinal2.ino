#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
//entradas
const int onoff = 23;
const int m1 = 25;
const int m2 = 27;
const int bluet = 29;
const int ok = 31;
const int sensor = 33;
const int mas = 42;
const int men = 44;

//salidas
const int ledPeq = 35;
const int ledMed = 37;
const int ledGra = 39;
//variables
String  dato;
int estado = 0;         
int anterior = 0;
int presiona1 = 0;
int presiona2 = 0;
int presiona3 = 0;
int presiona4 = 0;
int presiona5 = 0;
int x = 0;
int y = 0;
int z = 0;
int o = 0;
int p = 0;
int q = 0;
int r = 0;
int tiempo =0;
int porcion =2;
int hora =0;
int minuto=0;
int milisegundo;
int prueba = -1;


char bpres1 = ' ';
char bpres2 = ' ';
char bpres3 = ' ';
char bpres4 = ' ';
char bpres5 = ' ';
char estC = ' ';
char antC = ' ';
int pre1 = 0;
int pre2 = 0;
int pre3 = 0;
int pre4 = 0;
int pre5 = 0;

int bx = 0;
int by = 0;
int bo = 0;
int bp = 0;
int bq = 0;
int br = 0;
int bz = 0;
int bk = 0;
int bg = 0;
int b7 = 0;
int b8 = 0;
int b9 = 0;
int b10 = 0;
int b11 = 0;
int b12 = 0;
int cn=0;
int smg4=-1;
//unsigned long go, goA=0, retardo=2000;
void setup(){
   Serial.begin(9600);
   lcd.begin(16,2); 
   pinMode(onoff, INPUT);
   pinMode(m1, INPUT);
   pinMode(m2, INPUT);
   pinMode(bluet, INPUT);
   pinMode(ok, INPUT);
   pinMode(sensor, INPUT);
   pinMode(ledPeq, OUTPUT);
   pinMode(ledMed, OUTPUT);
   pinMode(ledGra, OUTPUT);
   pinMode(mas, OUTPUT);
   pinMode(men, OUTPUT);
} 


void loop(){

   pulso(onoff,1, estado, anterior, presiona1);
   bluAct(pre1);
   if(pre1==4){
     presiona1 = 1;
     pre1=0;
     dato="";
   }
   if (presiona1 == 1 ){
     lcd.clear();
     digitalWrite(mas, LOW);
     digitalWrite(men, LOW);
     do{  
         pulso(onoff,1, estado, anterior, presiona1);
         bluAct(pre1);
         if(pre1==4){
             presiona1 = 0;
             pre1=0;
             dato="";
         }
         
         presiona2 = 0;
         presiona3 = 0;
         presiona4 = 0;
         presiona5 = 0;
         prueba=-1;
         pre2 = 0;
         pre3 = 0;
         pre4 = 0;
         pre5 = 0;
         if(tiempo!=0){
             tiempo = convMS(hora,minuto);
         }else{
             tiempo = 60000;
         }
         if(porcion==2){
             milisegundo=300;
             digitalWrite(ledPeq, HIGH);
             digitalWrite(ledMed, LOW);
             digitalWrite(ledGra, LOW);  
         }else if(porcion==3){
             milisegundo=1000;
             digitalWrite(ledPeq, LOW);
             digitalWrite(ledMed, HIGH);
             digitalWrite(ledGra, LOW);
         }else if(porcion==4){
             milisegundo=3000;
             digitalWrite(ledPeq, LOW);
             digitalWrite(ledMed, LOW);
             digitalWrite(ledGra, HIGH); 
         }
         lcd.setCursor(0, 0);
         lcd.print("OK. Dar Comida  .");
         lcd.setCursor(0, 1);
         lcd.print("M1.Auto-M2. Conf");
         x=digitalRead(m1);
         y=digitalRead(m2);
         o=digitalRead(ok);
         bluAct(bx);
         if (bx==1){
           x=HIGH;
         }
         
         
         while(x==HIGH){
            pulso(m1,2,estado, anterior, presiona2);
            if(bx==1)
              presiona2=2;
            if(presiona2 == 2){ ////presiona M1(entra a modo de temporizador)
            lcd.clear();
            pre2=0;
            dato="";
            do{
                
                lcd.setCursor(0, 0);
                lcd.print("MODO");
                lcd.setCursor(0, 1);
                lcd.print("TEMPORIZADO");
                do{
                    pulso(m1,2,estado, anterior, presiona2);
                    if(presiona2==0){
                         smg4=1;
                         break;
                     }
                     bluAct(pre2);                 
                     if(pre2==1){
                        presiona2=0;
                        dato="";
                        smg4=1;
                        break;
                      }
                     
                     cn++;
                }while(cn<200);
                cn=0;
                if(smg4==1){
                    smg4=-1;
                    break;
                }
                //tiempo=tiempo/1000;
                  delayLargo(tiempo);
                  lcd.clear();
                  lcd.setCursor(0, 1);
                  delay(1000);
                  lcd.print("Dando Comida");
                  abrirCerrar(milisegundo, mas, men);
                  lcd.clear();
                  
                
            }while(presiona2==2);

            if (presiona2==0){
              bx=0;
              break;
            }
            }
         }
         
          
          
         bluAct(by);
         if (by==2){
           y=HIGH;
           dato="";
         }  
         while(y==HIGH){
            pulso(m2,3,estado, anterior, presiona3);
             if (by==2){
               presiona3 = 3;
               by=0;
               dato="";
             }  
             bq=0;
             bp=0;
            if(presiona3 == 3){ ////presiona M2 (entra a modo de configuracion)
                lcd.clear();
                delay(10);
                y=digitalRead(m2);
               if (by==0){
                   y=LOW;
               }  
                
                while(y==LOW){
                    pulso(ok,4,estado, anterior, presiona4);
                    bluAct(b10);
                    if (b10==3){
                         presiona4=4;
                         dato="";
                         b10=0;
                     }  
                    lcd.setCursor(0, 0);
                    lcd.print("M1. Porcion        ");
                    lcd.setCursor(0, 1);
                    lcd.print("M2.Tiempo Ok.Sal   ");
                    p=digitalRead(m1);
                    q=digitalRead(m2);
                     bluAct(bp);
                     if (bp==1){
                         p=HIGH;
                         dato="";
                     }
                    
                    while(p==HIGH){    //presiona m1 (escoje la opcion de porcion pequeño mediano o grande)
                        pulso(m1,2,estado, anterior, presiona2);
                         if (bp==1){
                             presiona2=2;
                             bp=0;
                         }  
                        if(presiona2==2){//revisar
                            lcd.clear();
                            presiona2==0;
                            x=digitalRead(m1);
                            delay(10);
                            bluAct(bx);
                            if (bx==1){
                               x=LOW;
                               dato="";
                               bx=0;
                            }
                          
                            
                            while(x==LOW){
                                lcd.setCursor(0, 0);
                                lcd.print("M1.Peq M2.Medi");
                                lcd.setCursor(0, 1);
                                lcd.print("Ok.Grande");
                                p=digitalRead(m1);
                                q=digitalRead(m2);
                                r=digitalRead(ok);
                                if(prueba!=-1){
                                    break;
                                }
                               
                                bluAct(bp);
                                if (bp==1){
                                   p=HIGH;
                                   dato="";
                                }  
                                while(p==HIGH){
                                      pulso(m1,2,estado, anterior, presiona2);
                                      if (bp==1){
                                         presiona2=2;
                                         presiona4=4;
                                         bp=0;
                                         
                                      }  
                                      if(presiona2==2){
                                            porcion=2;
                                            prueba=1;
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            lcd.print("INGRESO EXITOSO!");
                                            delay(800);
                                            lcd.clear();
                                            break;
                                       }
                                }
                                
                                bluAct(bq);
                                if (bq==2){
                                   q=HIGH;
                                   dato="";
                                }  
                                while(q==HIGH){
                                      pulso(m2,3,estado, anterior, presiona3);
                                     if (bq==2){
                                         presiona3=3;
                                         presiona4=4;
                                         bq=0;
                                         
                                      }  
                                      if(presiona3==3){
                                            porcion=3;
                                            prueba=1;
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            lcd.print("INGRESO EXITOSO!");
                                            delay(800);
                                            lcd.clear();
                                            break;
                                      }
                                }
                                bluAct(br);
                                if (br==3){
                                   r=HIGH;
                                   dato="";
                                }  
                                while(r==HIGH){
                                      pulso(ok,4,estado, anterior, presiona4);
                                     if (br==3){
                                         presiona4=4;
                                         br=0;
                                      }  
                                      if(presiona4==4){
                                            porcion=4;
                                            prueba=1;
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            lcd.print("INGRESO EXITOSO!");
                                            delay(800);
                                            lcd.clear();
                                            break;
                                       }
                                }
                              
                            }
                            x=digitalRead(m1);
                            bluAct(bx);
                            if (bx==1){
                                x=LOW;
                                dato="";
                                bx=0;
                            }  
                            y=digitalRead(m2);
                            bluAct(by);
                            if (by==2){
                                y=LOW;
                                dato="";
                                by=0;
                            }  
                            z=digitalRead(ok);
                            bluAct(bz);
                            if (bz==3){
                                z=LOW;
                                dato="";
                                bz=0;
                            }  
                            if(x==LOW || y==LOW|| z==LOW ){
                                break;
                            }              
                        }
                    }  
                    bluAct(bq);
                    if (bq==2){
                        q=HIGH;
                        delay(100);
                        dato="";
                    }  
                    while(q==HIGH){//escoje la opcion de tiempo que va a dejar funcionando el equipo
                        
                        pulso(m2,3,estado, anterior, presiona3);
                        if (bq==2){
                             presiona3=3;
                             bq=0;
                        }  
                        if(presiona3==3){
                            lcd.clear();
                            presiona3=0;
                            pre3=0;
                            x=digitalRead(m1);
                            dato="";
                           
                            while(x==LOW){

                                lcd.setCursor(0, 0);
                                lcd.print("M1.HORA: ");
                                lcd.setCursor(0, 1);
                                lcd.print("M2.MIN: ");
                                lcd.setCursor(13, 1);
                                lcd.print("OK.Sal: ");
                                p=digitalRead(m1);
                                q=digitalRead(m2);
                                r=digitalRead(ok);
                                bluAct(bp);
                                bluAct(bq);
                                if (bp==1){
                                    p=HIGH;q=LOW;
                                    dato="";
                                }else if(bq==2){
                                    q=HIGH;p=LOW;
                                    dato="";
                                }
                                while((p==HIGH && q==LOW)){
                                    
                                    q=digitalRead(m2);
                                    bluAct(bq);
                                    if (bq==2){
                                        q=HIGH;
                                        dato="";
                                    }
                                    
                                    
                                    
                                    r=digitalRead(ok);
                                    bluAct(br);
                                    if (br==3){
                                        r=HIGH;
                                        dato="";
                                        br=0;
                                    }  
                                    
                                     pulso(m1,2,estado, anterior, presiona2);
                                     bluAct(b7);
                                     if (b7==1){
                                       presiona2=2;
                                       dato="";
                                       b7=0;
                                     }  
                                    if(presiona2==2){
                                        presiona2=0;
                                        pre2=0;
                                        hora++;
                                        if (hora>=24){
                                            hora=0;
                                            lcd.setCursor(9, 0);
                                            lcd.print("    ");
                                        }
                                        lcd.setCursor(9, 0);
                                        lcd.print(hora);
                                    }
                                    
                                    if(r==HIGH){
                                        prueba=1;
                                        break;
                                    }
                                    
                                    
                                    
                                }
                               
                                while((p==LOW && q==HIGH)){
                                    p=digitalRead(m1);
                                    bluAct(bp);
                                    if (bp==1){
                                        p=HIGH;
                                        dato="";
                                    }
                                    
                                    
                                    r=digitalRead(ok);
                                    bluAct(br);
                                    if (br==3){
                                        r=HIGH;
                                        dato="";
                                        br=0;
                                    }  
                                   
                                    pulso(m2,3,estado, anterior, presiona3);
                                    bluAct(b8);
                                     if (b8==2){
                                       presiona3=3;
                                       dato="";
                                       b8=0;
                                     }  
                                    if(presiona3==3){
                                        presiona3=0;
                                        pre3=0;
                                        minuto++;
                                        if(minuto>=60){
                                            minuto=0;
                                            lcd.setCursor(9, 1);
                                            lcd.print("    ");
                                        }
                                        lcd.setCursor(9, 1);
                                        lcd.print(minuto);
                                    }
                                   
                                    if(r==HIGH ){
                                        prueba=1;
                                        break;
                                    }
                                    
                                 
                                 
                                }
                               if(prueba==1){
                                 break;
                               }
                            }
                            y=digitalRead(m2);
                            bluAct(by);
                           if (by==2){
                              y=LOW;
                              dato="";
                              by=0;
                           }  
                            if(y==LOW){
                               lcd.clear();
                               lcd.setCursor(0, 0);
                               lcd.print("INGRESO EXITOSO!");
                               delay(200);
                               presiona4=4;
                               break;
                            }
                        }
                    }
                    if(presiona4==4){
                        break;
                    }
                 
               }
              
            }
        }
        bluAct(bo);
        if(bo==3)
          o=HIGH;
        while(o==HIGH){
            pulso(ok,4,estado, anterior, presiona4);
            if(bo==3)
              presiona4=4;
            if(presiona4 == 4){ ////presiona OK (empieza el proceso de dar la comida)
                lcd.clear();
                lcd.setCursor(0, 1);
                lcd.print("Dando Comida");
                abrirCerrar(milisegundo, mas, men);
                delay(10);
                bo=0;
                dato="";
                break;
            }
             
       } 
     }while(presiona1==1);
   }else{
       lcd.clear();
       do{
          pulso(onoff,1,estado,anterior,presiona1);
          bluAct(pre1);
          if(pre1==4){
             presiona1 = 1;
             pre1=0;
             dato="";
           }
          lcd.setCursor(0, 0);
          lcd.print("APAGADO");
          digitalWrite(ledPeq, LOW);
          digitalWrite(ledMed, LOW);
          digitalWrite(ledGra, LOW);
       }while(presiona1==0 );
   }
} 


//FUNCIONES HECHAS
void pulso(int boton, int orden, int &estado, int &anterior, int &sal){
   estado = digitalRead(boton);
   if ((estado == LOW) && (anterior == HIGH)){
    sal = orden - sal;
  }
  anterior = estado;
  delay(20);
}

void bluAct(int &sal){
  
   while (Serial.available()) { 
    delay(10);
     if (Serial.available() > 0) {
      char c = Serial.read();                //Cuando se recibe un dato, se guarda como carácter
      dato += c;                             //Cadena de caracteres formada por la suma de los datos recibidos 
     }
  }
  
  if (dato.length() > 0) {
      if(dato=="a"){
          sal=1;
          //
          return;
      }
      if(dato=="b"){
          sal=2;
          //dato="";
          return;
      }
      if(dato=="c"){
          sal=3;
          //dato="";
          return;
      }
      if(dato=="d"){
          sal=4;
          //
          return;
          
      }
     
      
            
 }
  
}

void abrirCerrar(int tempo, int mas, int men){
          
          lcd.setCursor(0, 0);
          lcd.print("Abriendo");
          digitalWrite(mas, HIGH);
          digitalWrite(men, LOW);
          delay(1000);
          digitalWrite(mas, LOW);
          digitalWrite(men, LOW);
          lcd.setCursor(0, 0);
          lcd.print("Llenando");
          delay(tempo);
          lcd.setCursor(0, 0);
          lcd.print("Cerrando");
          digitalWrite(mas, LOW);
          digitalWrite(men, HIGH);
          delay(1000);
          digitalWrite(mas, LOW);
          digitalWrite(men, LOW);
}

int convMS(int &hora,int &minuto){
	int a,b,c;
        a=(hora*3600);
        b=(minuto*60);
        c=(a+b);
        return c;
}

void delayLargo(int &veces){
int cnt=0;	
        do{
          delay(1000);
          cnt++;
        }while(cnt<=veces);
        return;
}
