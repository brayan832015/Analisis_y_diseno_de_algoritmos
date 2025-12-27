.PHONY: all clean

BANDERAS = -std=c++11 -Wall -g
SALIDA = battleship

all: ejemplo

ejemplo:
	g++ $(BANDERAS) main.cpp battleship.cpp -o $(SALIDA)

clean:
	rm -r *.dSYM $(SALIDA)