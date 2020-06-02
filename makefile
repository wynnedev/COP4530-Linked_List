list : mydriver.o 
	-g++ -o list mydriver.o 

mydriver.o : mydriver.cpp tlist.h
	-g++ -c -O0 mydriver.cpp

clean : 
	rm list *.o