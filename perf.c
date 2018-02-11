#include <windows.h>

#include "perf.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

// Inicia un contador que servirá para medir el rendimiento de algoritmos
void empieza_rendimiento() {
  LARGE_INTEGER li;
  QueryPerformanceFrequency(&li);
  PCFreq = ((double)li.QuadPart)/1000.0;
  QueryPerformanceCounter(&li);
  CounterStart = li.QuadPart;
}

// Termina el contador iniciado por la función anterior
double termina_rendimiento() {
  LARGE_INTEGER li;
  QueryPerformanceCounter(&li);
  return ((double)li.QuadPart-CounterStart)/PCFreq;
}
