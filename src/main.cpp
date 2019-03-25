#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
#include "czas.h"
#include "scalanie.h"
#include "funkcjePomocnicze.h"

using namespace std;


int chujnia[8]= { 1, 6, 7, 8, 2, 3, 4, 5};
int chujowka[8]= {5, 4, 3, 2, 8, 7, 6, 1};

ulong wykonajTesty( ulong rozmiar, int tysieczne, char kolejnosc);

int main(void){
    int promil;
    string nazwa;
    char k= 'r';

    cout << "Jaki promil posortowany?: ";
    cin >> promil;

    if(promil == 1000)
	k= 'm';

    nazwa= to_string(promil);

    ofstream plik("wyniki/" + nazwa + ".txt");
    plik << wykonajTesty(10000, promil, k) << '\n';
    plik << wykonajTesty(50000, promil, k) << '\n';
    plik << wykonajTesty(100000, promil, k) << '\n';
    plik << wykonajTesty(500000, promil, k) << '\n';
    plik << wykonajTesty(1000000, promil, k) << '\n';
    plik.close();

    cout << "Cyka blyat, paka\n";
    
    return 0;
}

ulong wykonajTesty( ulong rozmiar, int tysieczne, char kolejnosc){
    int *tablica;
    ulong czas_min, czas_sredni, czas_tymcz;
    czas start, stop;
    const char k='r';

    tablica= czesciowoPosortowanaTablica(rozmiar, 0, 'r');
    czas_min= 0;
    czas_sredni= 0;

    for(ulong i= 0; i < 50; i++){
	czesciowoPosortowanaTablica(tablica, rozmiar, tysieczne, kolejnosc);
	start= zegar::now();
	sortowanieScalanie(tablica, 0, rozmiar-1, k);
	stop= zegar::now();

	if(!sprawdzPoprawnosc(tablica, rozmiar, k))
	    return false;

	czas_tymcz= obliczCzas(start, stop, 'm');
	if(czas_min > czas_tymcz || czas_min == 0)
	    czas_min= czas_tymcz;
	czas_sredni+= czas_tymcz;

	if(!(i % 5))
	    cout << "nadal żyję, " << i*2 << "%\n";
    }

    czas_sredni= czas_sredni/50;

    cout << "Test tablicy [" << rozmiar << "] elementow:\n";
    cout << " Najlepszy czas: " << czas_min << "ms\n";
    cout << " Sredni czas: " << czas_sredni << "ms\n";

    free(tablica);
    return czas_min;
}

