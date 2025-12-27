.PHONY: all clean

BANDERAS = -std=c++11 -Wall -g
SALIDA = deck

all: ejemplo

ejemplo:
	g++ $(BANDERAS) main.cpp deck.cpp -o $(SALIDA)

clean:
	rm -r *.dSYM $(SALIDA)