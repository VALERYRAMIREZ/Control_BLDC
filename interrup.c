#include "interrup.h"
#include "globales.h"
#include "botones.h"


SENALES senales;                        /* Declaraci�n de la variable senales */
                                        /* para usarla en la interrupci�n que */
                                        /* sea necesaria.                     */
unsigned char teclado;
unsigned char tecladoAnt;

void Inicia_Interr(void)                /* Funci�n para configurar e iniciar
                                         * las fuentes de interrupci�n.       */
{
    IEC0bits.T1IE = 1;                  /* Configuraci�n de las interrupciones*/
    IPC0bits.T1IP = 2;                  /* para el timer 1.                   */
    IFS0bits.T1IF = 0;
    
    IEC0bits.T3IE = 1;                  /* Se habilita la interrupci�n        */
    IPC2bits.T3IP = 1;                  /* para el timer de 32 bits, se       */
    IFS0bits.T3IF = 0;                  /* establece la prioridad de la       */
                                        /* interrupci�n en 1 y se borra la    */
                                        /* la bandera del timer de 32         */
                                        /* bits.                              */
    
    IEC1bits.CNIE = 1;                  /* Se habilitan los pines CN62 a CN65 */
    IPC4bits.CNIP = 1;                  /* para detectar el cambio de estado, */
    IFS1bits.CNIF = 0;                  /* esto es, los Puerto E,4 a Puerto   */
    CNEN4 = 0xc000;                     /* E,7 para detectar la tecla         */
    CNEN5 = 0x0003;                     /* presionada. Tambi�n se configur� la*/
                                        /* prioridad de la interrupci�n por   */
                                        /* notificaci�n de cambio de estado en*/
                                        /* 2, un nivel m�s alta que la del    */
                                        /* temporizador.                      */
}

/*               Funciones para el manejo de interrupciones                   */

void __attribute__((interrupt(no_auto_psv))) _T1Interrupt(void)/* Funci�n para*/
{                                       /* manejo de la interrupci�n del      */
    TMR1 = 0;                           /* timer 1, para usarlo como ciclo de */
    IFS0bits.T1IF = 0;                  /* trabajo del sistema.               */
    PORTE = PORTE/2;                    /* Se van rotando los pines activos   */
    if(PORTE == 0x00)                   /* del puerto E para realizar el      */ 
    {                                   /* del teclado.                       */
        PORTE = 0x08;
    }
    //tecladoAnt = PORTE;
}

void __attribute__((interrupt(no_auto_psv))) _T3Interrupt(void)/* Funci�n para*/
{                                       /* manejo de la interrupci�n del      */
    T2CONbits.TON = 0;                  /* timer 32 para usarlo como          */
    IFS0bits.T3IF = 0;                  /* temporizador de 32 bits.           */
}

void __attribute__((interrupt(no_auto_psv))) _CNInterrupt(void)/* Funci�n para*/
{                                       /* el manejo de la interrupci�n por   */
    teclado = PORTE;
    flanco(tecladoAnt & 0x10, teclado & 0x10);
    senales.tecla = 1;
    IFS1bits.CNIF = 0;
}