#include <stdlib.h>
#include <chrono>
#include "funkcjePomocnicze.h"

/* Zwraca wskaźnik do początku częściowo posortowanej tablicy 
    Argumenty: 
     rozmiar - rozmiar tablicy 
     tysieczne - jaka część tablicy ma być już posortowana, w tysięcznych 
     kolejnosc - 'r' dla rosnacych, 'm' dla malejących */
int* czesciowoPosortowanaTablica( ulong rozmiar, int tysieczne, char kolejnosc){
    int *tab;
    ulong prog;

    prog= rozmiar*tysieczne/1000;
    tab= (int*) malloc(sizeof(int) * rozmiar);

    if(kolejnosc != 'r' && kolejnosc != 'm')
	return NULL;
    
    srand(time(0));

    for(ulong i= 0; i < prog; i++){
	if(kolejnosc == 'r')
	    tab[i]= i+1;
	else
	    tab[i]= rozmiar-i;
    }

    for(ulong i= prog; i < rozmiar; i++){
	tab[i]= rand() % rozmiar;
    }

    return tab;
}

void czesciowoPosortowanaTablica( int *tab, ulong rozmiar, int tysieczne, char kolejnosc){
    ulong prog;

    prog= rozmiar*tysieczne/1000;
    
    if(kolejnosc != 'r' && kolejnosc != 'm')
	return;
    
    srand(time(0));

    for(ulong i= 0; i < prog; i++){
	if(kolejnosc == 'r')
	    tab[i]= i+1;
	else
	    tab[i]= rozmiar-i;
    }

    for(ulong i= prog; i < rozmiar; i++){
	tab[i]= rand() % rozmiar;
    }
}

int* losowaTablica( ulong rozmiar){
    int *tab;
    tab= (int*) malloc(sizeof(int) * rozmiar);

    srand(time(0));
    
    for(ulong i= 0; i < rozmiar; i++){
	tab[i]= rand() % rozmiar;
    }
    
    return tab;
}

void losowaTablica( int *tab, ulong rozmiar){
    srand(time(0));
    
    for(ulong i= 0; i < rozmiar; i++){
	tab[i]= rand() % rozmiar;
    }
}

bool sprawdzPoprawnosc( int *tab, ulong rozmiar, char kolejnosc){
    if(kolejnosc != 'r' && kolejnosc != 'm')
	return false;
    
    for(ulong i= 1; i < rozmiar; i++){
	if(kolejnosc == 'r'){
	    if(tab[i-1] > tab[i])
		return false;
	}
	else{
	    if(tab[i-1] < tab[i])
		return false;
	}
    }

    return true;
}
