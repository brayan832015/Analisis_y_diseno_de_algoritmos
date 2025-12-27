.PHONY: all clean

BANDERAS = -std=c++11 -Wall -g
SALIDA = list

all: ejemplo

ejemplo:
	g++ $(BANDERAS) main.cpp list.cpp -o $(SALIDA)

clean:
	rm -r *.dSYM $(SALIDA)