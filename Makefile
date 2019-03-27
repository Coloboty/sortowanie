#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

# __start__: uklad_rownan
	# ./uklad_rownan

sortowanie: obj/main.o obj/scalanie.o  obj/czas.o obj/funkcjePomocnicze.o obj/kopcowanie.o
	g++ -Wall -pedantic -o sortowanie obj/main.o obj/scalanie.o obj/czas.o obj/funkcjePomocnicze.o obj/kopcowanie.o

obj/main.o: src/main.cpp inc/header.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/main.o src/main.cpp

obj/kopcowanie.o: src/kopcowanie.cpp inc/kopcowanie.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/kopcowanie.o src/kopcowanie.cpp

obj/funkcjePomocnicze.o: src/funkcjePomocnicze.cpp inc/funkcjePomocnicze.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/funkcjePomocnicze.o src/funkcjePomocnicze.cpp		

obj/scalanie.o: src/scalanie.cpp inc/scalanie.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/scalanie.o src/scalanie.cpp

obj/czas.o: src/czas.cpp inc/czas.h
	g++ ${CPPFLAGS} -Wall -pedantic -o obj/czas.o src/czas.cpp



clean:
	rm -f obj/*.o uklad_rownan
