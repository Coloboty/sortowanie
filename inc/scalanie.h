#ifndef SCALANIE_H
#define SCALANIE_H


typedef unsigned long ulong;


void scalanieMalejaco( int *tab, ulong lewo, ulong srodek, ulong prawo);
void scalanieRosnaco( int *tab, ulong lewo, ulong srodek, ulong prawo);
void scalanieRekurencyjne( int *tab, ulong lewo, ulong prawo, char kolejnosc);
int sortowanieScalaniem( int *tab, ulong rozmiar, char kolejnosc);

#endif
