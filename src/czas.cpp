#include "czas.h"

unsigned long obliczCzas(czas start, czas stop, char jednostka){
    switch(jednostka){
    case 's':
	
	break;
    case 'm':
	return duration_cast<milliseconds>(stop-start).count();
	break;
    case 'u':
	return duration_cast<microseconds>(stop-start).count();
	break;
    case 'n':
	return duration_cast<nanoseconds>(stop-start).count();
	break;

    default:
	return 0;
    }
}

