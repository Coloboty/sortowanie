#include <stdlib.h>
#include <iostream>
#include "scalanie.h"

using namespace std;


int scalanie( int *tab, ulong lewo, ulong srodek, ulong prawo){
    ulong l_ind, p_ind;
    int *l_temp, *p_temp;

    /* Inicjalizacja tablic tymczasowych */
    l_temp= (int*) malloc(sizeof(int) * (srodek-lewo));
    p_temp= (int*) malloc(sizeof(int) * (prawo-srodek));
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
	    
	    return 0;
	}
    }

    return 0;
}


int scalanieSortowanie( int *tab, ulong lewo, ulong prawo){
    int srodek;
    
    /* Zwróć błąd jeśli indeksy są nieprawidłowe */
    if(lewo<0 || prawo<0 || prawo<lewo)
	return 1;

    /* Znajdź środek i podziel na dwie połowy */
    /* Środkowy indeks jest częścią 'lewej' połowy */
    if(lewo < prawo){
	srodek= (lewo+prawo)/2;
	/* cout << lewo << "   " << srodek << "   " << prawo << '\n'; */
	
	scalanieSortowanie(tab, lewo, srodek);
	scalanieSortowanie(tab, srodek+1, prawo);
	scalanie(tab, lewo, srodek, prawo);
    }
    

    return 0;
}
