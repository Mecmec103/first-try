#!/bin/bash
#-----------------------------
# Definición de Constantes
#-----------------------------

## En esta sección definiremos constantes que vamos a usar en el código, como por ejemplo
## el número máximo de jugadores, o el número máximo de sorteos, así como cualquier código de
## error que vayamos a utilizar.

#Consantes
MAX_SORTEOS=15
MAX_JUGADORES=10
NUM_ARGUMENTOS=2
NUM_ARGUMENTOS_AYUDA=1
REGEX=^[0-9]+$

#Errores
ERR_NUM_ARGS=1
ERR_NUM_SORTEOS=2
ERR_TIPO_PARAMETROS=3
ERR_VALOR_CERO=4

#Códigos de retorno
RET_OK=0


#-------------------------------
# Funciones
#-------------------------------

## En esta sección definiremos todas las funciones que vamos a utilizar en la sección prinpipal
## Definir las necesarias. Algunas funciones que podéis definir serían las siguientes.

Sintaxis(){
#-----------------------------------
#Esta función se encarga de mostrar la ayuda de cómo utilizar el script y termina su ejecución
#Recibe como parametro el código de terminación
if [ $1 -eq $ERR_NUM_PARAMETROS ]
   then
      echo "Has insertado un numero de parametros superior al especificado"
elif [ $1 -eq $ERR_VALOR_PARAMETROS ]
   then
      echo "El valor maximo del parametro 1 deberia ser 10, y el del parametro 2 15"
elif [ $1 -eq $ERR_TIPO_PARAMETROS ]
   then
      echo "Los parametros introducidos han de ser numericos del 1-10 o del 1-15"
elif [ $1 -eq $ERR_VALOR_CERO ]
   then
      echo "Los parametros introducidos no pueden tener como valor 0"
else
      echo "Todo correcto"
fi
}
Inicializar(){
#-----------------------------------
#Esta función se encarga de inicializar el array de premios
#Recibe como parámetro el número de jugadores que entran en los sorteos que se ejecutan
clear
for jugador in `seq 1 $1`; do
	premios[$jugador]=0
done
}

ControlArgumentos(){
#-----------------------------------
# Esta función se encarga de controlar que los argumentos están en el rango permitido
# Recibe el conjunto de argumentos que se han pasado al script
# Devuelve un código de error indicando el tipo de error que se ha producido
# Si piden ayuda con -? llama a Sintaxis con el código de retorno 0
if [ $# -ne $NUM_ARGUMENTOS ] && [ $# -ne $NUM_ARGUMENTOS_AYUDA ]
   then
      return $ERR_NUM_ARGS
   fi
if [[ $1 =~ $REGEX ]] && [[ $2 =~ $REGEX ]]
   then
       if [ $1 -eq 0 ] || [ $1 -eq 0 ]
    then
       return $ERR_VALOR_CERO
       elif [ $1 -le $MAX_SORTEOS ] && [ $2 -le $MAX_JUGADORES ]
          then
       return $FINALIZACION_CORRECTA
       else
          return $ERR_NUM_SORTEOS
       fi
   else
       return $ERR_TIPO_PARAMETROS
   fi

return $ERR_
}

LimpiarFicheros(){
#-----------------------------------
# Esta función elimina los ficheros de ejecuciones anteriores
for i in $(seq 1 15);do
  rm "s${i}r.txt" 2>/dev/null
done
}

LeerFicherosPremios(){
#-----------------------------------
# Esta función se encarga de leer uno a uno los ficheros de premios
# Recibe como parámetros el numero de sorteos y el de jugadores en cada sorteo
# Rellenará el array de premios, sumando a cada jugador su importe correspondiente al numero de sorteo

}

MostrarResultados(){
#-----------------------------------
# Esta función se encarga de mostrar los resultados en el informe final.
}

#-------------------------------
# PRINCIPAL - CODIGO
#-------------------------------

## Esta es la sección principal donde comienza la ejecución del código del script, aqui haremos uso
## de las funciones, constantes y errores definidos en las secciones anteriores.

#Llamamos al controld e argumentos pasándole los argumentos recibidos
ControlArgumentos $*
retVal=$?
if [ $retVal -eq $ERR_ ]; then
   #Mostramos mensaje y llamamos a Sintaxis
   echo "Se ha producido el error ...."
   Sintaxis $RET_
fi

#Si superamos el control de argumentos asignamos los argumentos a las variables
numSorteos=$1
numJugadores=$2

#Inicializamos el array de premios
Inicializar $numJugadores

#Limpiamos de ejecuciones anteriores
LimpiarFicheros

#Ejecutamos los sorteos en un bucle para el número de sorteos que nos pasan.
#En cada sorteo pasamos como parámetro el número de sorteo y el número de jugadores
#sorteo es el ejecutable en C que realiza el sorteo



#Una vez realizados los sorteos leemos los premios
LeerFicherosPremios $numSorteos $numJugadores

#Y finalmente mostramos los resultados
MostrarResultados

exit 0
