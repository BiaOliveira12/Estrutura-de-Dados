#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float potencia(float, int);
int main() {
	float resultado, base;//PRIMEIRA LINHA (onde o programa inicia)
	int expoente;
		
		base = lerInteiro("Informe a base: ");
		expoente = lerInteiro("Informe o expoente: ");		
		resultado = potencia(base, expoente);
		
		printf("%.2f elevado a %d = %.2f", base, expoente, resultado);
	return 0;
	}	
	int par(int num){
		return num%2==0 ? 1 : 0;
	}
float potencia(float base, int expoente){
		int i;
		float res = 1;
		for(i=0;i<expoente; i++)
			res *= base;
		return res;
	}
int lerInteiro(char *frase){
	int val;
	printf("%s", frase);
	scanf("%d", &val);
	return val;
}

	