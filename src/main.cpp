#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "header.h"
#include "czas.h"
#include "scalanie.h"

using namespace std;

int* losowaTablica( ulong rozmiar);

int chujnia[8]= { 1, 6, 7, 8, 2, 3, 4, 5};
int chujowka[8]= {5, 4, 3, 2, 8, 7, 6, 1};

int main(void){
    int *tablica;
    
    ulong rozmiar;
    czas start, stop;
    cout << "Cyka Blyat, początek programu.\n";
    
    rozmiar= 25;
    tablica= losowaTablica(rozmiar);

    for(ulong i= 0; i < rozmiar; i++){
	/* cout << tablica[i]; */
    	/* cout << '\n'; */
    }
    
    scalanieSortowanie(tablica, 0, rozmiar-1);
    
    /* scalanie(tablica, 0, 3, 7); */
    cout << "\n\n";
    for(ulong i= 0; i < rozmiar; i++){
    	cout << tablica[i];
    	cout << '\n';
    }
    cout << "Cyka blyat, paka\n";
    
    return 0;
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
