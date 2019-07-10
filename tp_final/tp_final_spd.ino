#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int lcd_key=0;
int key=0;
int flagInicio=0;
int d3=-1;
int d5=-1;
int d6=-1;
int d7=-1;
int p1=0;
int p2=0;
int p4=0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
#define D3 11
#define D5 A3
#define D6 A4
#define D7 A5
#define P1 13
#define P2 12
#define P4 10
#define ON 0
#define OFF 1
int desplazamiento=0;



void setup()
{
  	pinMode(P1,OUTPUT);
  	pinMode(P2,OUTPUT);
  	pinMode(D3,OUTPUT);
  	pinMode(P4,OUTPUT);
	pinMode(D5,OUTPUT);
	pinMode(D6,OUTPUT);
  	pinMode(D7,OUTPUT);
  
  	digitalWrite(P1,OFF);
  	digitalWrite(P2,OFF);
  	digitalWrite(D3,OFF);
  	digitalWrite(P4,OFF);
  	digitalWrite(D5,OFF);
  	digitalWrite(D6,OFF);
  	digitalWrite(D7,OFF);
  
  	Serial.begin(9600);
    lcd.begin(16, 2);              // Inicializar el LCD
 	lcd.setCursor(0,0);
 	lcd.print("HAMMING");   	  // Titulo;
  	lcd.setCursor(0,1);
  	lcd.print("Inicio->SELECT"); 
}

void loop()
{
     iniciar_programa();
  
  	 Serial.write("D3: ");
     Serial.print(d3);
  	 Serial.write(" D5: ");
     Serial.print(d5);
  	 Serial.write(" D6: ");
     Serial.print(d6);
  	 Serial.write(" D7: ");
     Serial.println(d7);
  
  	 Serial.write("Desplazamiento:");
  	 Serial.println(desplazamiento);
  
  	 Serial.write("Flag Inicio:");
  	 Serial.println(flagInicio);
  
  	 Serial.write("Tecla presionada:");
  	 Serial.println(lcd_key);
  	 Serial.println(analogRead(A0));
  	 Serial.write("***********************************");
  	 Serial.write("\n");
  	 do
     {
     	lcd_key=leer_botones();
     }while(lcd_key==5);
  	 leer_desplazamiento();
  	 leer_d3();
  	 leer_d5();
  	 leer_d6();
  	 leer_d7();
  	 analizar_datos(d3,d5,d6,d7);
  
  	 lcd_key=leer_botones();
     if(flagInicio==2 && lcd_key==4)
     {
    	restart();
     }
}

int leer_botones(){

	int key = analogRead(A0);
  	if(key > 900)
  		return btnNONE; 
  	
  	if(key > 620)
      	return btnSELECT; 
  	
  	if(key > 400)
      	return btnLEFT; 
   	
  	if(key > 250)
      	return btnDOWN; 
   	
  	if(key> 70)
      	return btnUP; 
  	
  	return btnRIGHT; 	  
}

void iniciar_programa (void)
{
	int retorno=-1;
  	if(lcd_key==4 && flagInicio==0)
    {
      	lcd.clear();
    	lcd.setCursor(0,0);
      	lcd.print("INICIANDO...");
      	delay(1500);
      	lcd.setCursor(1,1);
 		lcd.print("*"); 
        lcd.setCursor(2,1);
 		lcd.print("*"); 
  		lcd.setCursor(3,1);
 		lcd.print("*"); 
  		lcd.setCursor(4,1);
 		lcd.print("*");
        flagInicio=1;
      	delay(750);
      	leer_d3();
    }
	
}

void leer_desplazamiento(void)
{
	int retorno=0;
  	if(lcd_key==0 && flagInicio==1 && desplazamiento<3)
    {
    	desplazamiento++;
      	retorno=1;
    }
  	if(lcd_key==3 && flagInicio==1 && desplazamiento>0)
    {
	 	desplazamiento--;
      	retorno=1;        
    }
}

int leer_d3(void)
{
  	int retorno=0;
    if(desplazamiento==0 && flagInicio==1)
    {
    	lcd.setCursor(0,0);
      	lcd.print("Selecionado D3");
        if(lcd_key==1)
       		{
       
       			lcd.setCursor(1,1);
 				lcd.print("1");
       			d3=1;
      			retorno=1;
        
       		}
		else if (lcd_key==2)
       		{
       			lcd.setCursor(1,1);
 				lcd.print("0");
         		d3=0;
      			retorno=1;
        	}
	}
  return retorno;
}

int leer_d5(void)
{
	int retorno=0;
  	if(desplazamiento==1 && flagInicio==1)
    {
    	lcd.setCursor(0,0);
      	lcd.print("Selecionado D5");
    	if(lcd_key==1)
       	{
       		
       		lcd.setCursor(2,1);
 			lcd.print("1");
       		d5=1;
      		retorno=1;   
       	}
        else if(lcd_key==2)
        {
       		lcd.setCursor(2,1);
 			lcd.print("0");
         	d5=0;
         	retorno=1;
        }
    }
  return retorno;
}

int leer_d6(void)
{	
  	int retorno=0;
  	if(desplazamiento==2 && flagInicio==1)
    {
    	lcd.setCursor(0,0);
      	lcd.print("Selecionado D6");
      
      	if(lcd_key==1)
       	{
       		lcd.setCursor(3,1);
 			lcd.print("1");
       		d6=1;
      		retorno=1;
       	}
       
       else if(lcd_key==2)
       {  		
       		lcd.setCursor(3,1);
 			lcd.print("0");
         	d6=0;
         	retorno=1;
       }
    }
  return retorno;
}
  
int leer_d7(void)
{
	int retorno=0;
  	if(desplazamiento==3)
    {
    	lcd.setCursor(0,0);
      	lcd.print("Selecionado D7");
      	if(lcd_key==1)
       	{	
       		lcd.setCursor(4,1);
 			lcd.print("1");
       		d7=1;
      		retorno=1;
       	}
       else if(lcd_key==2)
       {	
       		lcd.setCursor(4,1);
 			lcd.print("0");
         	d7=0;
         	retorno=1;
       }
    }
  return retorno;
}

void analizar_datos (int d3,int d5,int d6,int d7)
{
  	if(lcd_key==4 && flagInicio==1 && d3!=-1 && d5!=-1 && d6!=-1 && d7!=-1)
  	{
      	flagInicio=2;
      	lcd.setCursor(0,0);
      	lcd.print("ANALIZANDO DATOS");
      	delay(2000);
      	lcd.clear();
      	delay(250);
      	lcd.setCursor(0,0);
      	lcd.print("Observe los Leds");
     
      	if(d3==1)
        {
        	digitalWrite(D3,ON);
        }
      	if(d5==1)
        {
        	digitalWrite(D5,ON);
        }
       	if(d6==1)
        {
        	digitalWrite(D6,ON);
        }
      	if(d7==1)
        {
        	digitalWrite(D7,ON);
        }
      	
      	delay(3000);
      	calcular_hamming(d3,d5,d6,d7);
      	lcd.clear();
      	delay(500);
      	lcd.setCursor(0,0);
      	lcd.print("Hamming");
      	lcd.setCursor(0,1);
      	lcd.print("Calculado");
      	delay(4000);
      	lcd.setCursor(0,1);
      	lcd.print("Restart->SELECT");
    }
}

void calcular_hamming(int d3,int d5, int d6, int d7)
{
	//P1
  	if((d3==1 && d5==0 && d7==0) ||
       (d3==0 && d5==0 && d7==1) ||
       (d3==1 && d5==1 && d7==1) ||
       (d3==0 && d5==1 && d7==0))
    {
    	p1=1;
      	digitalWrite(P1,ON);
    }
  
  	//P2
  	if((d3==1 && d6==0 && d7==0) ||
       (d3==0 && d6==0 && d7==1) ||
       (d3==1 && d6==1 && d7==1) ||
       (d3==0 && d6==1 && d7==0))
    {
    	p2=1;
      	digitalWrite(P2,ON);
    }
  
  	//P4
  	if((d5==1 && d6==0 && d7==0) ||
       (d5==0 && d6==0 && d7==1) ||
       (d5==1 && d6==1 && d7==1) ||
       (d5==0 && d6==1 && d7==0))
    {
    	p4=1;
      	digitalWrite(P4,ON);
    }
  	 Serial.write("P1: ");
     Serial.print(p1);
  	 Serial.write(" P2: ");
     Serial.print(p2);
  	 Serial.write(" P4: ");
     Serial.println(p4);
}


void restart (void)
{
	if(flagInicio==2 && lcd_key==4)
    {
    	flagInicio=0;
      	desplazamiento=0;
      	d3=-1;
      	d5=-1;
       	d6=-1;
      	d7=-1;
      	lcd.clear();
      	digitalWrite(P1,OFF);
  		digitalWrite(P2,OFF);
  		digitalWrite(D3,OFF);
  		digitalWrite(P4,OFF);
  		digitalWrite(D5,OFF);
  		digitalWrite(D6,OFF);
  		digitalWrite(D7,OFF);
    }
}