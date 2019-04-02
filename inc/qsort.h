#ifndef QSORT_H
#define QSORT_H

typedef unsigned long ulong;

int sortowanieSzybkie( int *tab, ulong rozmiar, char kolejnosc);
void qsort( int *tab, ulong lewo, ulong prawo);
ulong podziel( int *tab, ulong lewo, ulong prawo);

#endif
