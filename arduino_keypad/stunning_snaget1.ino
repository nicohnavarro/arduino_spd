#include <Keypad.h> //Incluimos la Libreria Keypad de Arduino
#include <LiquidCrystal.h> //Inlcuimos la Libreria LiquidCrystal de Arduino
const byte Filas =4; //Numero de Filas
const byte Columnas =4; //Numero de Columnas

byte Pins_Filas []={9,8,7,6}; //Pines Arduino de Filas
byte Pins_Columnas []={5,4,3,2}; //Pines Arduino de Columnas

char Teclas [Filas][Columnas]=
	{
  		{'1','2','3','A'},
  		{'4','5','6','B'},
  		{'7','8','9','C'},
  		{'*','0','#','D'}
  	};

Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Columnas, Filas, Columnas);

void setup()
	{
  		//LiquidCrystal (rs, enable, d4, d5, d6, d7);
  		LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); //Definimos el Lcd.
  		lcd.begin(16, 2);
  		lcd.setCursor(2, 2);
  		lcd.print("Hola Mundo!!");
  		Serial.begin(9600);
	}

void loop()
	{
  		char pulsacion=Teclado1.getKey();
  		if (pulsacion !=0) 				//Si el valor es 0 es que no se
          Serial.println(pulsacion);	//se ha pulsado ninguna tecla
  	}