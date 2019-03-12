#include "scalanie.h"

int scalanie( int *tab, int lewo, int srodek, int prawo){
    int l_ind, p_ind;
    int l_temp[srodek-lewo], p_temp[prawo-srodek];

    l_ind= lewo;
    p_ind= srodek + 1;

    /* Przepisz wartości z głównej tablicy do tymczasowych */
    for(int i= 0; i <= srodek; i++)
	l_temp[i]= tab[lewo+i];

    for(int i= 0; i <= prawo; i++)
	p_temp[i]= tab[srodek+i];

    /* Scal tymczasowe tablice do tablicy głównej */
    while((l_ind <= srodek) && (p_ind <= r)){
	if(tab[l_ind] < tab[p_ind])
    }
    return 0;
}

int scalanieSortowanie( int *tab, int lewo, int prawo){
    int srodek;
    
    /* Zwróć błąd jeśli indeksy są nieprawidłowe */
    if(lewo<0 || prawo<0 || prawo<lewo)
	return 1;

    /* Znajdź środek i podziel na dwie połowy */
    /* Środkowy indeks jest częścią 'lewej' połowy */
    if(lewo < prawo){
	srodek= (lewo+prawo)/2;
	
	scalanieSortowanie(tab, lewo, srodek);
	scalanieSortowanie(tab, srodek, prawo);
	scalanie(tab, lewo, srodek, prawo);
    }

    return 0;
}
