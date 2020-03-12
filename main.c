/*
 * File:   main.c
 * Author: valery
 *
 * Created on 5 de septiembre de 2019, 14:54
 */


#include <xc.h>
#include <string.h>
#include "globales.h"
#include "sistema.h"
#include "E_S.h"
#include "temporizadores.h"
#include "interrup.h"
#include "mensajes.h"
#include "LCD_44780.h"
#include "botones.h"

int main(void) {
    extern SENALES senales;
    char boton;
    extern uint8_t selMenu;
    Tipo_Osc(PROSC);
    Confi_E_S();
    Inicia_Interr();
    Inicia_LCD4();
    Ciclo_Timer1(10,0b0000000000000010);
    PORTE = 0x08;
    Inicia_Ciclo_Timer1();
    senales.tecla = 0;                  /* Lo puedo llamar de esa forma porque*/
    Posicion_Cur4b(1,0);                /* ya está instanciada la union en    */
    Menu();                             /* interup.c y al inicio de main se   */
    Selec_MenuS(1);                      /* instancia la estructura como una   */
                                        /* variable externa.                  */
    while(1)
    {
        tecladoAnt = PORTE;
        if(senales.tecla)
        {
            boton = det_Tecla(teclado);
            if(strcmp(&boton,"#") && !senales.nInterfaz)/* Se cambia la opción*/
            {                               /* del menú seleccionado.         */
                Selec_MenuS(boton);
            }
            else if(!strcmp(&boton,"#") && !senales.nInterfaz)/* Se accede al */
            {                               /* menú secundario seleccionado.  */
                Menu_S(selMenu);
                senales.nInterfaz = 1;
            }
            else if(!strcmp(&boton,"*") && senales.nInterfaz)/* Se sale del   */
            {                               /* menú secundario actual y se    */
                Menu();                     /* vuelve al menú principal.      */
                Selec_MenuS(boton);
                senales.nInterfaz = 0;
            }
            else if(senales.nInterfaz)// && (selMenu == 1))/* Se permite que el  */
            {                               /* cursor se mueva entre los      */
                cpos_Menu_S(selMenu,(uint8_t) boton);/* parámetros a llenar   */
            }                               /* del menú secundario 1          */
            boton = 0;                      /* (configuración del reloj).     */
            senales.tecla = 0;    
        }                               
    }
    return 0;
}
