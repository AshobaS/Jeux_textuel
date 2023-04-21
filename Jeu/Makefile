JeuPrison.exe : Personnage.o fonctions.o main.o
	g++ Personnage.o fonctions.o main.o -o JeuPrison.exe

Personnage.o: Personnage.cpp Personnage.h
	g++ -Wall -c Personnage.cpp

fonctions.o: fonctions.cpp fonctions.h Personnage.cpp Personnage.h
	g++ -Wall -c fonctions.cpp

main.o: main.cpp fonctions.cpp fonctions.h Personnage.cpp Personnage.h
	g++ -Wall -c main.cpp

clean:
	rm *.o JeuPrison.exe