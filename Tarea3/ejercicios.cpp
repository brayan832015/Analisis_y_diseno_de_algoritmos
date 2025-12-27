#include <iostream>

using namespace std;

class ejercicios {
public:
    // 1. Calcular largo de un número usando while
    int largoNumero(int n) {
        int contador = 0;

        if (n == 0) {
            return 1;
        }

        while (n != 0) {
            n /= 10;
            contador++;
        }
        return contador;
    }

    // 2. Sumatoria de 0 a n usando while
    int sumatoria(int n) {
        int suma = 0;
        int i = 0;

        while (i <= n) {
            suma += i;
            i++;
        }
        return suma;
    }

    // 3. Invertir cadena de char sin usar string
    void invertirCadena(char cadena[]) {
        int largo = 0;

        // Calcular largo de la cadena
        while (cadena[largo] != '\0') {
            largo++;
        }

        int inicio = 0;
        int fin = largo - 1;
        char temp;

        // Invertir la cadena
        while (inicio < fin) {
            temp = cadena[inicio];
            cadena[inicio] = cadena[fin];
            cadena[fin] = temp;

            inicio++;
            fin--;
        }
    }
};

int main() {
    ejercicios ej;

    int numero = 12345;
    cout << "Largo del numero: " << ej.largoNumero(numero) << endl;

    int n = 10;
    cout << "Sumatoria de 0 a " << n << ": " << ej.sumatoria(n) << endl;

    char texto[] = "Hola Mundo";
    ej.invertirCadena(texto);
    cout << "Cadena invertida: " << texto << endl;

    return 0;
}
