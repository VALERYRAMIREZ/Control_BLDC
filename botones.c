#include "botones.h"
#include "globales.h"
#include <stdbool.h>
#include <stdio.h>

/*             Variables a utilizar por las funciones.                        */

enum estBotones                     /* Enumerador para seleccionar el valor de*/
{                                   /* salida de la funci�n para deteccion de */
    bajo,                           /* flancos.                               */
    alto,
    subida,
    bajada
};
/*            Funciones para discriminar la tecla presionada.                 */

uint8_t Anti_R(uint8_t estado, bool pin)
{
    uint8_t vieja = estado & 0x7f;
    bool bandera = (estado & 0x80)? true : false;
    
    vieja -= (vieja >> 2);          /* El corrimiento de 2 divide a la variable
                                     * "vieja" por 4: y = x/n es lo mismo que
                                     * x >> n.                                */
    vieja += pin? 0x1f : 0x00;      /* Si el bit es igual a 1 le suma 25%.    */
    
    estado = (vieja & 0x7f) | ((bandera & 0x01) << 0x07);
    return estado;
}

unsigned int flanco(bool bitAnt, bool bit)/* Funci�n para determinar el tipo  */
{                                   /* de flanco que hubo al darse un cambio  */
    extern unsigned int estBotones; /* de estado en el puerto E. La funci�n   */
    if(!bitAnt && bit)              /* solo debe llamarse al darse un cambio  */
    {                               /* en el estado del puerto.               */
        estBotones = subida;
    }
    else if(bitAnt && !bit)
    {
        estBotones = bajada;
    }
    return estBotones;
}

char det_Tecla(unsigned char lectura)/* Funci�n para asignar el valor*/
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
        default:                        /* La opci�n en caso de que se        */
        {                               /* m�s de una tecla al mismo tiempo es*/
            valorTecla =0xff;           /* no asignar ninguna tecla.          */
        }
    }
    return valorTecla;
}