/* 
 * File:                botones.h
 * Author:              Valery Ramirez
 * Comments:            Librería para la manipulación de los botones, teclado.
 * Revision history:    N/A
 */

#ifndef XC_BOTONES_H
#define	XC_BOTONES_H

#include <xc.h> 
#include <stdio.h>

/*          Definiciones de constantes usadas para el teclado.                */

/*               Prototipos de funciones para manejo del teclado.             */

bool flanco(unsigned char estado);      /* Prototipo de función para detectar
                                         * el flanco del cambio de estado en un
                                         * bit.                               */

char det_Tecla(unsigned char lectura);  /* Prototipo de función para
                                         * asignar el valor de la tecla
                                         * presionada.                         */

#endif	/* XC_BOTONES_H */

