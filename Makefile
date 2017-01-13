main:castle.o	Heros.o  compagnon.o coeur.o enigme.o adversaire.o combat.o dragon.o
	g++ castle.o Heros.o compagnon.o coeur.o enigme.o adversaire.o combat.o dragon.o -o main

Heros.o:	Heros.cpp
	g++ -c Heros.cpp

dragon.o:	dragon.cpp
	g++ -c dragon.cpp 
	
compagnon.o : compagnon.cpp
	g++ -c compagnon.cpp 
	
castle.o : castle.cc
	g++ -c castle.cc 

coeur.o: coeur.cpp
	g++ -c coeur.cpp

enigme.o: enigme.cpp
	g++ -c enigme.cpp

adversaire.o: adversaire.cpp
	g++ -c adversaire.cpp
		
combat.o: combat.cpp
	g++ -c combat.cpp
	
clean:
	rm -f *~ *.o
test:
	./main
valgrind:
	valgrind ./main
