#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kmp.h"

// Funci�n para mostrar la tabla siguiente
void mostrar_tabla_kmp(int *t, int size, const char *nombre_tabla) {
  printf("Tabla KMP %s: ",nombre_tabla);
  int i;
  for(i = 0; i < size; i++) {
    printf("%i ", t[i]);
  }
  printf("\n");
}



// p es el patr�n, size es el tama�o del patron y tablaNext es la tabla "siguiente" asociada a p
// Esta funci�n se encarga de calcular la tabla siguiente
void preKMP(char *p, int size, int *tablaNext) {
  int i,j;
  i = 0;
  j = tablaNext[0] = -1;
  while (i < size-1) {
    while (j > -1 && p[i] != p[j]) {
      j = tablaNext[j];
    }
    i++;
    j++;
    if (p[i] == p[j])
      tablaNext[i] = tablaNext[j];
    else
      tablaNext[i] = j;
  }
}


// s es la cadena madre, p es el patr�n, y posiciones es un array de enteros
// que contendr� las posiciones iniciales del patr�n p detectado en la cadena s
void KMPSearch(char *s, char *p, int *posiciones) {
  int i,j,k; // i �ndice de S, j �ndice de P, k �ndice de posiciones

  int  s_len, p_len;   // Obtener las longitudes de s y p
  p_len = strlen(p);
  s_len = strlen(s);

  int tablaNext[p_len];  // Crear la tabla siguiente de P y calcularla
  preKMP(p, p_len, tablaNext);
//  Comentamos para que no afecte al rendimiento
//  mostrar_tabla_kmp(tablaNext, p_len, "Sgte");
  i = j = k = 0;
  while (i < s_len) {
    while (j > -1 && s[i] != p[j]) {
      j = tablaNext[j];
    }
    i++;
    j++;
    if (j >= p_len) {
      posiciones[k] = i -j;  // Grabamos la primera posici�n del patr�n encontrado
      k++;
      j = 0;
    }
  }
}
