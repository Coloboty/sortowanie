#include <iostream>
#include "kopcowanie.h"

/* Funkcja sortuje daną tablice w danej kolejności, wykorzystując właściwości kopca binarnego */
int sortowanieKopcowaniem( int *tab, ulong rozmiar, char kolejnosc){
    /* Sprawdź poprawność podanych argumentów */
    if(kolejnosc != 'r' && kolejnosc != 'm')
	return 1;

    /* 'Kopcuj' od dołu w stronę korzenia */
    if(kolejnosc == 'r')
	for(long i= rozmiar/2 - 1; i >= 0; i--){
	    tworzKopiecMalejacy(tab, rozmiar, i);
	}
    else
	for(long i= rozmiar/2 - 1; i >= 0; i--){
	    tworzKopiecRosnacy(tab, rozmiar, i);
	}

    /* Ściągaj elementy z kopca i przywracaj jego właściwości */
    for(long i= rozmiar - 1; i > 0; i--){
	zamien(tab[i], tab[0]);
	if(kolejnosc == 'r')
	    tworzKopiecMalejacy(tab, i, 0);
	else
	    tworzKopiecRosnacy(tab, i, 0);
    }

    /* Na koniec pętli istnieje możliwośc, że pierwsze dwa elementy są w złej kolejności */
    if(kolejnosc == 'r' && tab[0] > tab[1])
	zamien(tab[0], tab[1]);
    else if(kolejnosc == 'm' && tab[0] < tab[1])
	zamien(tab[0], tab[1]);
    
    return 0;
}

/* Funkcja nadaje zadanej tablicy właściwości kopca binarnego (każdy punkt jest mniejszy od swoich synów)*/
void tworzKopiecRosnacy( int *tab, ulong rozmiar, ulong korzen){
    ulong najmniejsza, lewo, prawo;
    
    lewo= 2*korzen + 1;
    prawo= 2*korzen + 2;

    /* Przerwij, jeśli poza obszarem kopca */
    if(prawo > rozmiar - 1)
	return;

    /* Sprawdź, który z trzech elementów jest najmniejszy */
    najmniejsza= korzen;
    
    if(tab[lewo] < tab[korzen])
	najmniejsza= lewo;
    if(tab[prawo] < tab[najmniejsza])
	najmniejsza= prawo;

    /* Jeśli to nie korzeń jest największy, zamień go z największym elementem, a następnie powtórz całą operację kopcowania niżej */
    if(najmniejsza != korzen){
	zamien(tab[korzen], tab[najmniejsza]);
	tworzKopiecMalejacy(tab, rozmiar, najmniejsza);
    }
    
    return;
}

/* Funkcja nadaje zadanej tablicy właściwości kopca binarnego (każdy punkt jest większy od swoich synów)*/
void tworzKopiecMalejacy( int *tab, ulong rozmiar, ulong korzen){
    ulong najwieksza, lewo, prawo;
    
    lewo= 2*korzen + 1;
    prawo= 2*korzen + 2;

    /* Przerwij, jeśli poza obszarem kopca */
    if(prawo > rozmiar - 1)
	return;

    /* Sprawdź, który z trzech elementów jest największy */
    najwieksza= korzen;
    
    if(tab[lewo] > tab[korzen])
	najwieksza= lewo;
    if(tab[prawo] > tab[najwieksza])
	najwieksza= prawo;

    /* Jeśli to nie korzeń jest największy, zamień go z największym elementem, a następnie powtórz całą operację kopcowania niżej */
    if(najwieksza != korzen){
	zamien(tab[korzen], tab[najwieksza]);
	tworzKopiecMalejacy(tab, rozmiar, najwieksza);
    }
    
    return;
}

/* Prosta funkcja do zamiany wartości dwóch komórek pamięci */
void zamien( int& jeden, int& dwa){
    int temp;

    temp= jeden;
    jeden= dwa;
    dwa= temp;
}
