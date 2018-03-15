#include "funciones.h"

/**
 * 
 * @brief       Programa que recibe una imagen .raw desde linea de comando y 
 *              la cuantiza, hasta 7 tonalidades de grises. Especial agradeciminto
 *              a Jose Carlos Paniagua.
 * @author      Diego Patricio Gutierrez Lopez Cano
 * @date        15/marzo/2018
 * @file        tarea5.c fucniones.h
 * 
 * */

int main (int argc, char **argv)
{
  int factor;
  char nombre_imagen[25];

  if (argc != 3)
  {
    printf("ERROR: Ingrese solo tres argumentos.\n");
  }
  else
  {
    if (strstr(argv[1], ".raw") == NULL)
    {
      printf("ERROR: la extension del archivo de entrada no es .raw\n");
    }
    else
    {
      factor= atoi(argv[2]);
      if (!(factor >= 0 && factor <= 7))
      {
        printf("ERROR: ingrese un factor valido, del 0-8\n");
      }
      else
      {
        strcpy(nombre_imagen, argv[1]);
        factor = pow(2, factor);
        cuantiza(nombre_imagen, factor);
      }
    }
  }
  return 0;
}