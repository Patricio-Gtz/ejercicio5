#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Prototipos de funciones;
void cuantiza(char *nombre_imagen, int factor);

void cuantiza(char *nombre_imagen, int factor)
{
  unsigned char c; // Se utiliza para la lectura y escritura de las imagenes caracter por caracter.
  char encabezado[15]; // Aqui se almacena el encabezado de las imagenes .raw
  FILE *entrada; // File pointer utilizado para la imagen a procesar.
  FILE *salida; // File pointer donde se escribe la imagen nueva.

  entrada= fopen(nombre_imagen, "rb");
  salida= fopen("cuantizada.raw", "wb");
  fseek(entrada, 0L, SEEK_SET); // Nos movemos al principio del archivo.
  fread(encabezado, 1, sizeof(encabezado), entrada); // Leemos el encabezado de la imagen.
  fprintf(salida, "%s", encabezado);
  fseek(entrada, 15, SEEK_SET); // Nos movemos hasta el primer pixel de la imagen.

  while(!feof(entrada)) // Se lee el archivo caracter por caracter (byte por byte).
  {
    fread(&c, sizeof(char), 1, entrada); // Lectura del archivo de entrada.
    if(feof(entrada) == 0)
    {
      c = c/factor; // Primero se divide el valor del caracter entre el factor de cuantificación.
      c = c*factor; // Despues se multiplica el resultado por el mismo factor, de manera que los caracteres que resultaron en 0 de la operación anterior se conserven en 0.
      fwrite(&c, 1, sizeof(char),salida); // Escritura en el archivo de salida.
    }
  }
  fclose(salida);
  fclose(entrada);
}