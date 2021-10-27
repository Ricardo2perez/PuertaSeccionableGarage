//Config.h
// button set to use (analog input, digital input)
#define BUTTONS_ANALOG
//#define BUTTONS_DIGITAL

// milliseconds after a button is considered as pressed
#define BUTTON_MIN_PRESSED 30

// milliseconds after a button is considered as long pressed
#define BUTTON_LONG_PRESSED 1000

// put to false to add movements to the program after its execution
#define PROGRAM_RESET_ALWAYS true

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY false

// memory capacity for program movements
#define MOVE_LIMIT 100

// milliseconds for the "pause" movement
#define PAUSE_MOVE_MILLIS 1000

// milliseconds delay before starting to move
#define DELAY_BEFORE_GO 500

// milliseconds to pause after every movement
#define AFTER_MOVEMENT_PAUSE 0




// ensure this library description is only included once
#ifndef Config_h
#define Config_h
// Entradas
#define MODRF   2 // Modulo de Radiofecuencia del Mando a Distancia
#define PULCL   4 // Pulsador de Clear para resetear 
#define PULRF   5 // Pulsador de Memorización mando a Distancia
#define PULOC   6 // Pulsador de Abrir/Cerrar (Open/Close)
#define SOBRESF A0 // Señal de sobreesfuerzo motor
#define FOTOELE A1 // Celula Fotoelectrica 


// Salidas
#define LEDSTAD 3 // Led de estado automatismo
#define CORTES  7 // Luz de cortesia
#define K2      8 // Motor Dirección Abrir
#define K1      9 // Motor Dirección Cerrar

//Auxiliares
#define TIME_OUT 20000  // Tiempo máximo para abrir o Cerrar
#define TIME_OVER_LOAD 2   // Tiempo sobresfuerzo al abrir o al cerrar
#define BOUNCE_O_C 25 // Tiempo antirrebote Pulsador Abrir/Cerrar
#define BOUNCE_MANDO_DISTANCIA 25 //Tiempo antirrebote modulo Mando a Distancia
#define BOUNCE_FOTOELE 25  // Tiempo antirrebote celula Fotoelectrica
#define ADDRESS 0  //Posicion de memoria desde la que empiezan a guardar datos
#define POS_MINEXP 0 // Posicion de memoria para guardar datos
#define POS_SECONEXP 1 // Posicion de memoria para guardar datos
#define POS_USABLE 5 // Posicion de memoria para verificar si los datos no estan corrompidos  



#endif  // Config_h

//EOF
