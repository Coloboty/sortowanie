#include <iostream>
#include "kopcowanie.h"

int kopcowanie( int *tab, ulong rozmiar, char kolejnosc){
    /* if(kolejnosc != 'r' && kolejnosc != 'm') */
	/* return 1; */

    if(kolejnosc == 'r')
	for(ulong i= rozmiar/2 - 1; i >= 0; i--)
	    tworzKopiecMalejacy(tab, rozmiar, i);
    else
	for(ulong i= rozmiar/2 - 1; i >= 0; i--)
	    tworzKopiecRosnacy(tab, rozmiar, i);

    return 0;
    
    for(ulong i= rozmiar - 1; i <= 0; i--){
	zamien(tab[i], tab[0]);
	if(kolejnosc == 'r')
	    tworzKopiecMalejacy(tab, i, 0);
	else
	    tworzKopiecRosnacy(tab, i, 0);
    }
    
    return 0;
}

int tworzKopiecRosnacy( int *tab, ulong rozmiar, ulong korzen){

    return 0;
}

int tworzKopiecMalejacy( int *tab, ulong rozmiar, ulong korzen){
    ulong najwieksza, lewo, prawo;
    
    lewo= 2*korzen + 1;
    prawo= 2*korzen + 2;

    najwieksza= korzen;
    
    if(tab[lewo] > tab[korzen])
	najwieksza= lewo;
    if(tab[prawo] > tab[najwieksza])
	najwieksza= prawo;

    if(najwieksza != korzen){
	zamien(tab[korzen], tab[najwieksza]);
	tworzKopiecMalejacy(tab, rozmiar, najwieksza);
    }
    
    return 0;
}

void zamien( int& jeden, int& dwa){
    int temp;

    temp= jeden;
    jeden= dwa;
    dwa= temp;
}
