#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directa.h"
#include "kmp.h"
#include "bm.h"
#include "perf.h"

void ejecuta_algoritmo(int identificador) { // 1: Directo, 2: KMP, 3: BM
  int i;
  double tiempo;

  // Leyendo archivo
  FILE *fp;
  long lSize;
  char *buffer;

  fp = fopen ("texto.txt", "rb");
  if(!fp) perror("texto.txt"),exit(1);

  fseek(fp, 0L, SEEK_END);
  lSize = ftell(fp);
  rewind(fp);

  buffer = calloc(1, lSize+1);
  if(!buffer) fclose(fp),fputs("Memoria insuficiente",stderr),exit(1);

  if(1 != fread(buffer, lSize, 1, fp))
    fclose(fp),free(buffer),fputs("Ha fallado la lectura del archivo",stderr),exit(1);

  // Creando array posiciones
  int posiciones[strlen(buffer)];
  for (i = 0; i<strlen(buffer); i++) {
    posiciones[i] = 0;
  }
  // Empezando a contar el rendimiento
  empieza_rendimiento();

  // Ejecutando algoritmo
  if (identificador == 1) {
    directa(buffer, "porompomrom", posiciones);
  } else if (identificador == 2) {
    KMPSearch(buffer, "porompomrom", posiciones);
  } else {
    boyermoore_search(buffer, "porompomrom", posiciones);
  }

  // Recopilando datos del rendimiento
  tiempo = termina_rendimiento();
  printf("Rendimiento: %d s y %d ms  (%f)\n", (int)(tiempo/1000), (int)(tiempo)%1000, tiempo);

  // Mostrando array posiciones
  printf("Array posiciones encontradas: \n");
  for (i = 0; i<strlen(buffer); i++) {
    if (posiciones[i] == 0) {
      break;
    }
    printf("%i, ", posiciones[i]);
  }
  printf("\n\n");

  // Terminando programa
  fclose(fp);
  free(buffer);
}

int main() {
  printf("BUSQUEDA DIRECTA:\n");
  ejecuta_algoritmo(1);
  printf("\n\n");
  printf("BUSQUEDA KMP:\n");
  ejecuta_algoritmo(2);
  printf("\n\n");
  printf("BUSQUEDA BM:\n");
  ejecuta_algoritmo(3);
  printf("\n\n");
  system("PAUSE");
  return 0;
}
