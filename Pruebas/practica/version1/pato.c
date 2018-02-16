#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int arg[2];
arg [0] = atoi(argv[1]);
arg [1] = atoi(argv[2]);

if(arg[0] == 0 || arg[1] == 0)
printf("los argumentos son 0\n");
else 
{
int i;char hola[4];FILE *fp;
hola[0]='s';
hola[2]='\0';
for (i = 1; i<=arg[0];i++)
 {
  hola[1]=i+48;
  fp = fopen(hola,"w");
  fclose(fp);
 }
}

}
