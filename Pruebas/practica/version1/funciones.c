/*ESQUELETO DEL FICHERO func.c donde se define el código de las funciones a utilizar*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>
#include "funciones.h"

#define UN_ACIERTO = 1;
#define DOS_ACIERTOS = 2;
#define TRES_ACIERTOS = 3;
#define CUATRO_ACIERTOS = 4;
#define CINCO_ACIERTOS = 5;
#define SEIS_ACIERTOS = 6;


//MANEJADORES ------------------------------------------------
//PADRE - MANEJADOR PARA LAS SEÑALES EN TIEMPO REAL ------
//void HijoApuesta(int sig, siginfo_t *siginfo, void *context){
// Esta función es el manejador de señales en tiempo real.
// Cada hijo enviará al padre una señal diciendo que ha apostado
// Aquí contaremos cuántos hijos han contestado en una variable global que habrá que definir
//}

//HIJOS - MANEJADOR DE SEÑALES NORMALES ------
//void SorteoRealizado (int sig, siginfo_t *siginfo, void *context)
//Esta función es el manejador de la señal que reciben los hijos para enterarse que el padre
//ya ha generado la combinación ganadora, es decir, que se ha realizado el sorteo.
//

//FUNCIONES  --------------------------------------------------
//FUNCIONES SOLO PADRE //////////////////////////////////////////////////////
int ValidarArgumentos(int argc, char** argv){
//Se podría utilizar esta función para validar los argumentos que recibe el programa sorteo.
//Los parámetros que recibe son los que recibe el propio main.
//El valor de retorno puede ser un código de OK u Error
}

void CrearTuberias(int numHijos){
//Esta función sirve para que el padre, antes de crear los hijos y sabiendo cuántos son
//cree todas las tuberias.
//Una forma es crear un array de tuberías global (que heredarán los hijos)
int pipes[numHijos][2];int i;
for(i = 0; i < numHijos; i++)
{
	if((pipe(pipes[i])) < 0)
 {
  	perror("Failed to open pipe");
 }
}
}

void ComunicarApuesta(int numHijo, unsigned int *ganadora){
//Esta función servirá al padre para enviar la combinación ganadora por la tubería correspondiente
//al hijo, siendo numHijo el índice del hijo en el array de tuberías.
}


//FUNCIONES SOLO HIJOS //////////////////////////////////////////////////////
void ApuestaRealizada(){
//Esta función la utilzarán los hijos para enviar una señal al padre de forma que éste
//sepa que el hijo ha realizado su apuesta.
}

int ComprobarCombinacion(unsigned int *ganadora, unsigned int *apuesta){
//Esta función la usarán los hijos para comprobar el número de aciertos de su combinación
//La función devuelve el número de aciertos que tendrá el jugador
int i , j,k;
j=0;k=0;
for (i = 0; i<6;i++)
{
	if(ganadora[i]>apuesta[j])
		j++;
	else if(ganadora[i]==apuesta[j])
	{j++;k++;}
}
return k;
}

int CalcularPremio(int numAciertos){
//Esta función servirá para calcular el importe del premio en función de la cantidad de números acertados
//Devuelve el premio en euros
int premio;
switch (numAciertos) {
	case 0:
		premio = 0;
		break;
	case 1:
		premio = 1;
		break;
	case 2:
		premio = 2;
		break;
	case 3:
		premio = 3;
		break;
	case 4:
		premio = 4;
		break;
	case 5:
		premio = 5;
		break;
	case 6:
		premio = 6;
		break;
}
return premio;
}

void LeerGanadora(int numHijo, unsigned int *ganadora){
//Esta función servirá al hijo para leer la combinación ganadora de su tubería, que vendrá indicada
//por el número de hijo numHijo que es el índice que el hijo tiene en el array de tuberías.
//La combinación ganadora se depositará en el array ganadora.
}

//FUNCIONES COMUNES PADRE HIJOS //////////////////////////////////////////////////////
void GenerarCombinacion(unsigned int *combinacion, int pid){
//Esta función la utilizarán el padre y el hijo para generar la combinación
//El padre generará la combinación ganadora y el hijo su apuesta.
//Hay que inicializar el generador de números aleatorios con valores distintos para el padre y para cada hijo
//Lo ideal es que la combinación se devuelva ordenada o bien hacer uso de otra función para ordenarla como qsort
int n,i,j;
int repeticiones[16];
for(n=0;n<16;n++)
	repeticiones[n]=0;
srand(pid);
for(n =0; n<6;)
{
i=(int)(rand()%16);
if(repeticiones[i]==0)
{
combinacion[n]=i;
n++;
repeticiones[i]++;
}
}
for(i = 1;i<6;i++)
{
	for(j=0;j<5;j++)
	{
	 if(combinacion[j]>combinacion[j+1])
	 {
	  n = combinacion[j];
	  combinacion[j]=combinacion[j+1];
	  combinacion[j+1]=n;
 	 }
	}
}
}
