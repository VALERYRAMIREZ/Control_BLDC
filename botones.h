/* 
 * File:                botones.h
 * Author:              Valery Ramirez
 * Comments:            Librer�a para la manipulaci�n de los botones, teclado.
 * Revision history:    N/A
 */

#ifndef XC_BOTONES_H
#define	XC_BOTONES_H

#include <xc.h> 
#include <stdbool.h>

/*          Definiciones de constantes usadas para el teclado.                */

/*               Prototipos de funciones para manejo del teclado.             */

unsigned char Anti_R(uint8_t estado, bool pin);/* Prototipo de funci�n
                                         * para realizar un filtro pasa bajo
                                         * exponencial con el fin de realizar
                                         * un antirebote en un pin espec�fico.*/

unsigned int flanco(bool bitAnt, bool bit);/* Prototipo de funci�n para detectar
                                         * el flanco del cambio de estado en un
                                         * bit.                               */

char det_Tecla(uint8_t lectura);  /* Prototipo de funci�n para
                                         * asignar el valor de la tecla
                                         * presionada.                         */

#endif	/* XC_BOTONES_H */

