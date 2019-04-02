#ifndef KOPCOWANIE_H
#define KOPCOWANIE_H

typedef unsigned long ulong;

int sortowanieKopcowaniem( int *tab, ulong rozmiar, char kolejnosc);
void tworzKopiecRosnacy( int *tab, ulong rozmiar, ulong korzen);
void tworzKopiecMalejacy( int *tab, ulong rozmiar, ulong korzen);
void zamien( int& jeden, int& dwa);

#endif
