/* 
 * File:                botones.h
 * Author:              Valery Ramirez
 * Comments:            Librer�a para la manipulaci�n de los botones, teclado.
 * Revision history:    N/A
 */

#ifndef XC_BOTONES_H
#define	XC_BOTONES_H

#include <xc.h> 
#include <stdio.h>

/*          Definiciones de constantes usadas para el teclado.                */

/*               Prototipos de funciones para manejo del teclado.             */

bool flanco(unsigned char estado);      /* Prototipo de funci�n para detectar
                                         * el flanco del cambio de estado en un
                                         * bit.                               */

char det_Tecla(unsigned char lectura);  /* Prototipo de funci�n para
                                         * asignar el valor de la tecla
                                         * presionada.                         */

#endif	/* XC_BOTONES_H */

