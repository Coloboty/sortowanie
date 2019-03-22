#include <chrono>

using namespace std::chrono;
typedef high_resolution_clock zegar;
typedef zegar::time_point czas;

unsigned long obliczCzas(czas start, czas stop, char jednostka);
