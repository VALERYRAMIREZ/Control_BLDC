/* 
 * File:                globales.h
 * Author:              Valery Ramirez
 * Comments:            Archivo creado para manejar las definiciones de 
 *                      variables globales a usar en el sistema.
 * Revision history:    N/A
 */
 
#ifndef XC_GLOBALES_H
#define	XC_GLOBALES_H

#include <xc.h>  

/*              Variables globales a usar en el sistema.                      */

extern unsigned char teclado;           /* Variable global donde se almacena el
                                         * estado del teclado.                */
extern unsigned char tecladoAnt;        /* Variable global donde se almacena el
                                         * estado anterior del teclado.       */

extern uint8_t tTecla;                  /* Variable para contar la cantidad de
                                         * veces que se realizar� el filtraje
                                         * antirebote cuando se detecta la
                                         * presi�n de una tecla.              */

extern uint8_t selMenu;                 /* Variable para almacenar el men� a 
                                         * seleccionar.                       */                 

//static volatile uint8_t estado;         /* variable que conserva el estado de
//                                         * la suma del filtro antirebote.     */

typedef union                           /* Variable tipo estructura para      */
{                                       /* marcar eventos de interrupciones en*/
    unsigned int banderas;              /* marcar eventos de interrupciones en*/
    struct                              /* las interrupciones.                */
    {                                   
        unsigned int restantes:12;
        unsigned int nInterfaz:2;
        unsigned int flanco:1;
        unsigned int tecla:1;           /* Bandera para indicar el uso de la 
                                         * interrupci�n por notificaci�n de
                                         * cambio en un pin.                  */
    };
} SENALES;

typedef struct                          /* Estructura para almacenar la fecha */
{                                       /* y hora del dispositivo. La         */
    uint8_t ano[5];                       /* estructura est� pensada para */
    uint8_t mes[3];
    uint8_t dia[3];
    uint8_t hora[3];
    uint8_t minuto[3];
    uint8_t segundo[3];
} tiempo;

typedef struct
{
    uint16_t P[4];
    uint16_t I[4];
    uint16_t D[4];
} motor;

/*     Definici�n de funciones para el manejo de los datos introducidos en    */
/*                      la configuraci�n del sietema.                         */

char* Alma_RTC(uint8_t numParam,uint8_t dato);/* Prototipo de funci�n para el
                                             * almacenamiento de los datos en
                                             * las estructuras
                                             * correspondientes.              */
#endif	/* XC_GLOBALES_H */

