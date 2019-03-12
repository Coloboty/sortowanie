#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

int* losowaTablica( int rozmiar);

int main(void){
    int *tablica, rozmiar;
    cout << "Cyka Blyat, początek programu.\n";

    rozmiar= 10;
    tablica= losowaTablica(rozmiar);
    for(int i= 0; i < rozmiar; i++){
	cout << tablica[i];
	cout << '\n';
    }

    cout << "Cyka blyat, paka\n";
    cout << 3/2;
    
    return 0;
}

int* losowaTablica( int rozmiar){
    int *tab;
    tab= (int*) malloc(rozmiar);

    srand(time(0));
    
    for(int i= 0; i < rozmiar; i++){
	tab[i]= rand() % rozmiar;
    }
    
    return tab;
}
