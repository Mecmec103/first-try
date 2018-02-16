/*ESQUELETO DEL FICHERO func.c donde se define el código de las funciones a utilizar*/
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

typedef struct {
    int pid ; // Pid del hijo
    int num ; // Numero de orden del hijo
    int num_aciertos; // Numero de aciertos.
	int pipehijo[2]; // Descriptores el pipe del hijo
    long premio; //WSEn mi caso el premio se escribe directamente en el fichero.
} HIJO ;

//void HijoApuesta(int sig, siginfo_t *siginfo, void *context);
//void SorteoRealizado (int sig, siginfo_t *siginfo, void *context);
int ValidarArgumentos(int argc, char** argv);
void CrearTuberias(int numHijos);
void ComunicarApuesta(int numHijo, unsigned int *ganadora);
void ApuestaRealizada();
int ComprobarCombinacion(unsigned int *ganadora, unsigned int *apuesta);
int CalcularPremio(int numAciertos);
void LeerGanadora(int numHijo, unsigned int *ganadora);
void GenerarCombinacion(unsigned int *combinacion, int pid);
