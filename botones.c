#include "botones.h"
#include "globales.h"
#include <stdbool.h>

/*            Funciones para discriminar la tecla presionada.                 */

bool flanco(bool bitAnt, bool bit)  /* Función para determinar el tipo de     */
{                                   /* flanco que hubo al darse un cambio de  */
    extern SENALES senales;         /* estado en el puerto E. La función solo */
    if(!bitAnt && bit)              /* debe llamarse al darse un cambio en el */
    {                               /* estado del puerto.                     */
        senales.flanco = 1;
    }
    else if(bitAnt && !bit)
    {
        senales.flanco = 0;
    }
    return senales.flanco;
}

char det_Tecla(unsigned char lectura)/* Función para asignar el valor*/
{                                       /* a la tecla presionada.             */
    char valorTecla;
    switch(lectura)
    {
        /* Teclas de la fila superior.                                        */
        case(0x11):
        {
            valorTecla = 7;
        }
        break;
        case(0x21):
        {
            valorTecla = 8;
        }
        break;
        case(0x41):
        {
            valorTecla = 9;
        }
        break;
        case(0x81):
        {
            valorTecla = 'D';
        }
        break;
        /* Teclas de la segunda fila.                                         */
        case(0x12):
        {
            valorTecla = 4;
        }
        break;
        case(0x22):
        {
            valorTecla = 5;
        }
        break;
        case(0x42):
        {
            valorTecla = 6;
        }
        break;
        case(0x82):
        {
            valorTecla = 'C';
        }
        break;
        /* Teclas de la tercera fila.                                         */
        case(0x14):
        {
            valorTecla = 1;
        }
        break;
        case(0x24):
        {
            valorTecla = 2;
        }
        break;
        case(0x44):
        {
            valorTecla = 3;
        }
        break;
        case(0x84):
        {
            valorTecla = 'B';
        }
        break;
        /* Teclas de la cuarta fila.                                          */
        case(0x18):
        {
            valorTecla = '*';
        }
        break;
        case(0x28):
        {
            valorTecla = 0;
        }
        break;
        case(0x48):
        {
            valorTecla = '#';
        }
        break;
        case(0x88):
        {
            valorTecla = 'A';
        }
        break;
        default:                        /* La opción en caso de que se        */
        {                               /* más de una tecla al mismo tiempo es*/
            valorTecla =0xff;           /* no asignar ninguna tecla.          */
        }
    }
    return valorTecla;
}