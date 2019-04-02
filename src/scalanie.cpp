#include <stdlib.h>
#include <iostream>
#include "scalanie.h"

using namespace std;

/* Sprawdza poprawność argumentu kolejność i wywołuję właściwą funkcję sortującą */
int sortowanieScalaniem(int *tab, ulong rozmiar, char kolejnosc){
    /* Zwróć błąd, jeżeli podano nieprawidłowy argument */
    if(kolejnosc != 'r' && kolejnosc != 'm')
	return 1;

    scalanieRekurencyjne(tab, 0, rozmiar - 1, kolejnosc);
    
    return 0;
}

/* Wraz z wybraną f. scalającą realizuje algorymt sortowania scalaniem */
void scalanieRekurencyjne( int *tab, ulong lewo, ulong prawo, char kolejnosc){
    ulong srodek;
    
    /* Znajdź środek i podziel na dwie połowy */
    /* Środkowy indeks jest częścią 'lewej' połowy */
    if(lewo < prawo){
	srodek= (lewo+prawo)/2;
		
	scalanieRekurencyjne(tab, lewo, srodek, kolejnosc);
	scalanieRekurencyjne(tab, srodek+1, prawo, kolejnosc);
	if(kolejnosc == 'r')
	    scalanieRosnaco(tab, lewo, srodek, prawo);
	else
	    scalanieMalejaco(tab, lewo, srodek, prawo);
    }
    
    return;
}

/* Scala dwie podtablice do tablicy właściwej, w kolejności malejącej */
void scalanieMalejaco( int *tab, ulong lewo, ulong srodek, ulong prawo){
    ulong l_ind, p_ind;
    int *l_temp, *p_temp;

    /* Inicjalizacja tablic tymczasowych */
    l_temp= (int*) malloc(sizeof(int) * (srodek-lewo+1));
    p_temp= (int*) malloc(sizeof(int) * (prawo-srodek+1));
    l_ind= 0;
    p_ind= 0;

    /* Przepisz wartości z głównej tablicy do tymczasowych */
    for(ulong i= 0; i <= srodek-lewo; i++){
	l_temp[i]= tab[lewo+i];
    }
    for(ulong i= 0; i < prawo-srodek; i++){
	p_temp[i]= tab[srodek+i+1];
    }
        
    /* Scal tymczasowe tablice do tablicy głównej */
    for(ulong i= lewo; i <= prawo; i++){
	/* Sortuj, sprawdząjac po kolei */
	if(l_temp[l_ind] >= p_temp[p_ind]){
	    tab[i]= l_temp[l_ind];
	    l_ind++;
	}
	else{
	    tab[i]= p_temp[p_ind];
	    p_ind++;
	}

	/* Jeśli wyczerpaliśmy liczby z którejś tablicy,  */
	/* to wystarczy przepisać resztę tej drugiej do   */
	/* tablicy głównej */
	if(l_ind > srodek-lewo || p_ind >= prawo-srodek){
	    i++;
	    
	    while(l_ind <= srodek-lewo){
		tab[i]= l_temp[l_ind];
		l_ind++;
		i++;
	    }
	    while(p_ind < prawo-srodek){	
		tab[i]= p_temp[p_ind];
		p_ind++;
		i++;
	    }

	    break;
	}
    }

    free(l_temp);
    free(p_temp);
    
    return;
}

/* To samo, tylko w kolejności rosnącej */
void scalanieRosnaco( int *tab, ulong lewo, ulong srodek, ulong prawo){
    ulong l_ind, p_ind;
    int *l_temp, *p_temp;

    /* Inicjalizacja tablic tymczasowych */
    l_temp= (int*) malloc(sizeof(int) * (srodek-lewo+1));
    p_temp= (int*) malloc(sizeof(int) * (prawo-srodek+1));
    l_ind= 0;
    p_ind= 0;

    /* Przepisz wartości z głównej tablicy do tymczasowych */
    for(ulong i= 0; i <= srodek-lewo; i++){
	l_temp[i]= tab[lewo+i];
    }
    for(ulong i= 0; i < prawo-srodek; i++){
	p_temp[i]= tab[srodek+i+1];
    }
        
    /* Scal tymczasowe tablice do tablicy głównej */
    for(ulong i= lewo; i <= prawo; i++){
	/* Sortuj, sprawdząjac po kolei */
	if(l_temp[l_ind] <= p_temp[p_ind]){
	    tab[i]= l_temp[l_ind];
	    l_ind++;
	}
	else{
	    tab[i]= p_temp[p_ind];
	    p_ind++;
	}

	/* Jeśli wyczerpaliśmy liczby z którejś tablicy,  */
	/* to wystarczy przepisać resztę tej drugiej do   */
	/* tablicy głównej */
	if(l_ind > srodek-lewo || p_ind >= prawo-srodek){
	    i++;
	    
	    while(l_ind <= srodek-lewo){
		tab[i]= l_temp[l_ind];
		l_ind++;
		i++;
	    }
	    while(p_ind < prawo-srodek){	
		tab[i]= p_temp[p_ind];
		p_ind++;
		i++;
	    }

	    break;
	}
    }

    free(l_temp);
    free(p_temp);
    
    return;
}
