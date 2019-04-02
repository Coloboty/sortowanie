#include <iostream>
#include <string>
#include <fstream>
#include "czas.h"
#include "scalanie.h"
#include "kopcowanie.h"
#include "qsort.h"
#include "funkcjePomocnicze.h"

using namespace std;

ulong wykonajTesty( ulong rozmiar, int tysieczne, bool pod_wlos,  int (*funkcja)(int*, ulong, char));

int main(void){
    int promil, wybor;
    string nazwa;
    bool pod_wlos;
    int (*funkcja)(int*, ulong, char);

    cout << "Jaki promil posortowany?: ";
    cin >> promil;
    cout << "Jakiego algorytmu użyć?" << '\n';
    cout << "1 Scalanie" << '\n';
    cout << "2. Kopcowanie " << '\n';
    cout << "3. Sortowanie szybkie" << '\n';
    cin >> wybor;

    switch(wybor){
    case 1:
	funkcja= sortowanieScalaniem;
	nazwa= "scalanie";
	break;
    case 2:
	funkcja= sortowanieKopcowaniem;
	nazwa= "kopcowanie";
	break;
    case 3:
	funkcja= sortowanieSzybkie;
	nazwa= "szybkie";
	break;
    default:
	cout << "Nie umiem tak sortować!" << '\n';
	return 0;
	break;
    }

    /* No bo po co sortować już posortowaną tablicę... */
    if(promil == 1000)
	pod_wlos= true;
    else
	pod_wlos= false;

    /* Testuj każdy rozmiar tablicy i zapisuj wyniki do pliku w folderze wyniki */
    ofstream plik("wyniki/" + nazwa + "/" + to_string(promil) + ".txt");
    plik << wykonajTesty(10000, promil, pod_wlos, funkcja) << '\n';
    plik << wykonajTesty(50000, promil, pod_wlos, funkcja) << '\n';
    plik << wykonajTesty(100000, promil, pod_wlos, funkcja) << '\n';
    plik << wykonajTesty(500000, promil, pod_wlos, funkcja) << '\n';
    plik << wykonajTesty(1000000, promil, pod_wlos, funkcja) << '\n';
    plik.close();
    
    return 0;
}

/* Wykonuje testy funkcji sortującej danej w argumencie tablicą o parametrach danych w argumencie */
/* Przyjmuje */
/*  rozmiar - rozmiar tablicy do testów */
/*  tysieczne - ile tysiacznych tablicy przekazanej do funkcji ma być już posortowane */
/*  pod_wlos - czy tablica przekazywana do funkcji jest posortowana zgodnie, czy przeciwko kierunkowi sortowania */
/*  funkcja - wskaźnik funkcji do testów */
/* Zwraca */
/*  najlepszy czas wykonania funkcji */
ulong wykonajTesty( ulong rozmiar, int tysieczne, bool pod_wlos, int (*funkcja)(int*, ulong, char)){
    int *tablica;
    ulong czas_min, czas_sredni, czas_tymcz;
    czas start, stop;
    const char k='r';
    char kolejnosc_startowa;

    /* Rób bylejaką tablicę w celu alokacji pamięci */
    tablica= czesciowoPosortowanaTablica(rozmiar, 0, 'r');
    czas_min= 0;
    czas_sredni= 0;

    /* Zdecyduj, czy tablica do testów ma być tworzona częściowo posortowana w kierunku sortowania, czy odwrotnie */
    if(pod_wlos)
	kolejnosc_startowa= 'm';
    else
	kolejnosc_startowa= 'r';

    /* Testuj 50 razy, sprawdzając poprawność sortowania i licząc czas */
    for(ulong i= 0; i < 50; i++){
	/* Losuj nową tablicę */
	czesciowoPosortowanaTablica(tablica, rozmiar, tysieczne, kolejnosc_startowa);

	/* Mierz czas sortowania */
	start= zegar::now();
	funkcja(tablica, rozmiar, k);
	stop= zegar::now();

	/* Sprawdź poprawność działania funkcji */
	if(!sprawdzPoprawnosc(tablica, rozmiar, k)){
	    cout << "BŁĄD! ALGORYTM SIĘ POMYLIŁ\n";
	    return false;
	}

	/* Licz minimalny czas wykonania */
	czas_tymcz= obliczCzas(start, stop, 'm');
	if(czas_min > czas_tymcz || czas_min == 0)
	    czas_min= czas_tymcz;
	czas_sredni+= czas_tymcz;

	/* Informuj użytkownika, że program się nie zawiesił */
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

