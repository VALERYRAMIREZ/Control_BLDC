/* 
 * File:                globales.c   
 * Author:              Valery Ramirez
 * Comments:            N/A
 * Revision history:    N/A
 */

#include "globales.h"


/*             Declaraci�n de variables y estructuras de datos a usar.        */

tiempo RTC;                             /* Estructura de tipo tiempo para
                                         * almacenar los datos del RTC.       */


char* Alma_RTC(uint8_t numParam, uint8_t dato)/* Funci�n para el almacenamiento*/
{                                       /* de los datos en las estructuras    */
    static uint8_t contDato = 0, temp = 1;/* correspondientes.                */
    char *exporta = 0;
    if(temp != numParam)                /* Se reinicia contDato si se cambia  */
    {                                   /* par�metro a llenar en la estructura*/
        contDato = 0;                   /* para configurar el reloj del       */
    }                                   /* sistema.                           */
    switch(numParam)                    /* Llema el par�metro en funci�n de la*/
    {                                   /* funci�n seleccionada.              */
        case 1:
        {
            if(contDato <= 3)
            {
                RTC.ano[contDato] = dato;
                exporta = (char*) RTC.ano;
                contDato++;
            }
        }
        break;
        case 2:
        {
            if(contDato <= 1)
            {
                RTC.mes[contDato] = dato;
                exporta = (char*) RTC.mes;
                contDato++;
            }
        }
        break;
        case 3:
        {
            if(contDato <= 1)
            {
                RTC.dia[contDato] = dato;
                exporta = (char*) RTC.dia;
                contDato++;
            }
        }
        break;
        case 4:
        {
            if(contDato <= 1)
            {
                RTC.hora[contDato] = dato;
                exporta = (char*) RTC.hora;
                contDato++;
            }
        }
        break;
        case 5:
        {
            if(contDato <= 1)
            {
                RTC.minuto[contDato] = dato;
                exporta = (char*) RTC.minuto;
                contDato++;
            }
        }
        break;
        case 6:
        {
            if(contDato <= 1)
            {
                RTC.segundo[contDato] = dato;
                exporta = (char*) RTC.segundo;
                contDato++;
            }
        }
        break;
    }
    temp = numParam;                    /* Se asigna numParam a temp para
                                         * comparar en la pr�xima entrada a la
                                         * funci�n.                           */
    return exporta;
}


