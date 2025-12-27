# Tarea 3: Ejercicios Fundamentales con Clases

## Descripción General

Esta tarea implementa **tres ejercicios prácticos**.

## Objetivo

Implementar y practicar:
- Cálculo de cantidad de dígitos en un número
- Sumatoria de números secuenciales
- Inversión de cadenas de caracteres (arrays)
- Uso de bucles while para iteración
- Encapsulación mediante clases
- Manipulación de arreglos de caracteres

## 📁 Archivos

### `ejercicios.cpp` (Archivo Único)

Contiene la clase `ejercicios` con tres métodos públicos y el programa principal.

## 🎓 Métodos Implementados

### 1. largoNumero(int n) - Contar Dígitos

**Objetivo:** Calcular cuántos dígitos tiene un número entero.

**Lógica:**
12345 -> 5 dígitos
0 -> 1 dígito (caso especial)



**Funcionamiento:**
1. Si n es 0, retorna 1 (caso especial)
2. Mientras n sea diferente de 0:
   - Divide n entre 10 (elimina último dígito)
   - Incrementa contador
3. Retorna contador

**Ejemplo:**
n = 12345
Iteración 1: 12345 / 10 = 1234 (contador = 1)
Iteración 2: 1234 / 10 = 123 (contador = 2)
Iteración 3: 123 / 10 = 12 (contador = 3)
Iteración 4: 12 / 10 = 1 (contador = 4)
Iteración 5: 1 / 10 = 0 (contador = 5)
Resultado: 5

---

### 2. sumatoria(int n) - Suma de 0 a n

**Objetivo:** Calcular la suma de todos los números desde 0 hasta n.

**Fórmula Matemática:** Σ(i) para i = 0 hasta n

**Funcionamiento:**
1. Inicializar suma en 0 e i en 0
2. Mientras i sea menor o igual a n:
   - Sumar i al total
   - Incrementar i
3. Retorna la suma final

**Ejemplo:**
n = 5
suma = 0 + 1 + 2 + 3 + 4 + 5 = 15

Iteración 1: suma = 0 (i = 0)
Iteración 2: suma = 1 (i = 1)
Iteración 3: suma = 3 (i = 2)
Iteración 4: suma = 6 (i = 3)
Iteración 5: suma = 10 (i = 4)
Iteración 6: suma = 15 (i = 5)
Resultado: 15

---

### 3. invertirCadena(char cadena[]) - Invertir Cadena

**Objetivo:** Invertir el orden de caracteres en un arreglo sin usar strings.

**Funcionamiento:**

**Paso 1: Calcular Largo**
"Hola"
H o l a \0
0 1 2 3 4
largo = 4

**Paso 2: Invertir con Dos Punteros**
inicio = 0, fin = 3
Antes: H o l a

Iteración 1: Intercambiar H y a
a o l H (inicio = 1, fin = 2)

Iteración 2: Intercambiar o y l
a l o H (inicio = 2, fin = 1)

Fin: inicio >= fin, terminar
Después: a l o H -> "aloH"

**Ejemplo Completo:**
Entrada: "Hola Mundo"
H o l a M u n d o \
0 1 2 3 4 5 6 7 8 9

Salida: "odnum aloH"
o d n u m a l o H \0

**Caracteres Importantes:**
- `'\0'` - Carácter nulo (fin de cadena)
- `'\\'` - Carácter de escape
