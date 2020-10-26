#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int q1(int n) {
	// Caso base da recursao
    if(n < 2) {
		return 1;
	}
    // Demais casos, onde ocorre as chamadas recursivas
	return n * q1(n - 1);
}

int q2(int n) {
    // Caso base da recursao
	if(n < 2) {
		return 1;
	}
    // Demais casos
	return q2(n-1) + q2(n-2);
}

int q3(int x) {
    //Caso base da recursao
	if((x / 10) == 0) {
		return x;
	}
    
	return q3(x / 10) + (x % 10) * pow(10, abs(log10(x)));
}

int q4(int vetAux[], int x) {
	// Caso base da recursao
    if(x == 1) {
		return vetAux[0];
	}
    // Demais casos
	return vetAux[x-1] + q4(vetAux, x-1);
}

int q5(int x) {
    // Caso base da recursao
	if(x == 1) {
		return 1;
	}
    // Demais casos
	return x + q5(x - 1);
}

int q6(int m, int n) {
    // Caso base da recursao
	if(n == 1) {
		return m;
	}
    // Demais casos
	return m * q6(m, n - 1);
}

float q7(float vetAux[], int x) {
	int aux;
    // Caso base da primeira recursao
	if(x % 2 == 0) {
		aux = 0;
	} else {
        // Demais casos
		aux = -1;
	}
	float q7Aux(float vet[], int x, int z) {
		// Caso base da segunda recursao
        if(x == z) {
			return vet[x];
		}
		float aux;
		q7Aux(vetAux, x-1, z+1);
		// Lógica do metodo bolha de ordenação
        aux = vetAux[x-1];
		vetAux[x-1] = vetAux[z+1];
		vetAux[z+1] = aux;
	}
	return(q7Aux(vetAux, x, aux));
}

int q8(int m, int n) {
	//Caso base da recursao
    if(n == 0) {
		return m;
	}

    // Demais chamadas recursivas
	q8(n, m % n);
}

int q9(int m, int n, int o) {
    if(m % 10 == n) {
		o++;
	}
    // Caso base da recursao
	if(m % 10 == m) {
		return o;
	}
	q9(m / 10, n, o);
}

int q10(int m, int n) {
	// Caso base recursao
    if(m == 0 || n == 0) {
		return 0;
	}
    // Caso base recursao
	if(n == 1) {
		return m;
	}
	return m + q10(m, n - 1);
}