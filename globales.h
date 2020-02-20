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

unsigned char tTecla;                   /* Variable para contar la cantidad de
                                         * veces que se realizará el filtraje
                                         * antirebote cuando se detecta la
                                         * presión de una tecla.              */

static volatile unsigned char estado;   /* variable que conserva el estado de
                                         * la suma del filtro antirebote.     */

typedef union                           /* Variable tipo estructura para      */
{                                       /* marcar eventos de interrupciones en*/
    unsigned int banderas;              /* marcar eventos de interrupciones en*/
    struct                              /* las interrupciones.                */
    {                                   
        unsigned int restantes:14;
        unsigned int flanco:1;
        unsigned int tecla:1;           /* Bandera para indicar el uso de la 
                                         * interrupción por notificación de
                                         * cambio en un pin.                  */
    };
} SENALES;

#endif	/* XC_GLOBALES_H */

