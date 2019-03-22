#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

# __start__: uklad_rownan
	# ./uklad_rownan

sortowanie: obj/main.o obj/scalanie.o  obj/czas.o
	g++ -Wall -pedantic -o sortowanie obj/main.o obj/scalanie.o obj/czas.o

obj/main.o: src/main.cpp inc/header.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/main.o src/main.cpp

obj/scalanie.o: src/scalanie.cpp inc/scalanie.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/scalanie.o src/scalanie.cpp

obj/czas.o: src/czas.cpp inc/czas.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/czas.o src/czas.cpp



clean:
	rm -f obj/*.o uklad_rownan
