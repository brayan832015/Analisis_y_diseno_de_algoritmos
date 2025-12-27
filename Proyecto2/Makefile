.PHONY: all clean

BANDERAS = -std=c++11 -Wall -g
SALIDA = tree

all: ejemplo

ejemplo:
	g++ $(BANDERAS) main.cpp tree.cpp -o $(SALIDA)

clean:
	rm -r *.dSYM $(SALIDA)

