#ifndef KOPCOWANIE_H
#define KOPCOWANIE_H

typedef unsigned long ulong;

int kopcowanie( int *tab, ulong rozmiar, char kolejnosc);
int tworzKopiecRosnacy( int *tab, ulong rozmiar, ulong korzen);
int tworzKopiecMalejacy( int *tab, ulong rozmiar, ulong korzen);
void zamien( int& jeden, int& dwa);

#endif
