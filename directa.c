#include <string.h>

#include "directa.h"

void directa(char* s, char* p, int *posiciones) {
  int i, k = 0;
  int M = strlen(p);
  int N = strlen(s);

  // Bucle recorriendo la cadena madre letra por letra
  for (i = 0; i <= N - M; i++) { // Se quitan del bucle las letras finales, ya que no tendría sentido
    int j;

    // Para cada índice buscamos si coinciden el patrón y la cadena madre
    // (comparamos el patrón con la parte de la cadena madre)
    for (j = 0; j < M; j++)
      if (s[i + j] != p[j])
        break;

    if (j == M) { // Si llega al final y no ha hecho "break" es que son iguales
      posiciones[k] = i;
      k++;
    }
  }
}
