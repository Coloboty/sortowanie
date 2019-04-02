#include "qsort.h"
#include "kopcowanie.h"
#include <iostream>
/* kopcowanie.h dla funkcji zamien() */

/* Wywołuje właściwą funkcję sortowania */
/* (bo f. testująca w main musi przyjmować funkcję o trzech konkretnych argumentach) */
int sortowanieSzybkie( int *tab, ulong rozmiar, char kolejnosc){
    qsort(tab, 0, rozmiar-1);
    return 0;
}

/* Wraz z funkcją dzielącą realizuje algorytm sortowania szybkiego */
void qsort( int *tab, ulong lewo, ulong prawo){
    ulong os;

    /* Jeśli jest jeszcze co sortować */
    if(lewo < prawo){
	/* Podziel na dwie podtablice */
	os= podziel(tab, lewo, prawo);

	/* Jeśli w ogóle jest jakaś podtablica po lewej, ją też sortuj */
	if(os > 0)
	    qsort(tab, lewo, os-1);

	/* Sortuj prawą podtablicę */
	qsort(tab, os+1, prawo);
    }
}

/* Układa daną tablicę i dzieli na element osiowy, elem. większe od osiowego i mniejsze od osiowego */
/* Zwraza */
/*  indeks elementu osiowego */
ulong podziel( int *tab, ulong lewo, ulong prawo){
    int os;
    ulong indeks_osi;
    ulong i;

    /* Wybierz jakiś element 'osiowy' */
    indeks_osi= prawo;
    os= tab[indeks_osi];
    i= lewo-1;

    /* Umieść wszystkie elementy mniejsze od osi po lewej stronie osi */
    /* a większe po prawej */
    for(ulong j= lewo; j < prawo; j++){
	if(tab[j] <= os){
	    i++;
	    zamien(tab[i], tab[j]);
	}
    }
    /* Wstaw elem. osiowy we właściwe miejsce */
    zamien(tab[i+1], tab[indeks_osi]);

    /* Zwróć miejsce, w którym stoi oś */
    return i+1;
}

