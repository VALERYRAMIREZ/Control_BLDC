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
    Posicion_Cur4b(1,0);
    Menu();
    Ciclo_Timer1(10,0b0000000000000010);
    PORTE = 0x08;
    Inicia_Ciclo_Timer1();
    senales.tecla = 0;                  /* Lo puedo llamar de esa forma porque*/
                                        /* ya est� instanciada la union en    */
                                        /* interup.c y al inicio de main se   */
                                        /* instancia la estructura como una   */
                                        /* variable externa.                  */
    while(1)
    {
        tecladoAnt = PORTE;
        if(senales.tecla)
        {
//            Posicion_Cur4b(1,11);
            boton = det_Tecla(teclado);
//            Mensaje_Ent(&boton);
            if(strcmp(&boton,"#"))
            {
                Selec_MenuS(boton);
            }
            else if(!strcmp(&boton,"#"))
            {
                Menu_S(selMenu);
            }
            senales.tecla = 0;     
            
        }                               
    }
    return 0;
}
