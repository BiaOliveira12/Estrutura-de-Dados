#include <stdio.h>
#include <stdlib.h>

/* ATIVIDADE DE ESTRUTURA DE DADOS I */

float ladoQuadrado(float x) {
	float a;
	a = x * x;
	return a;
}
int Somaaten(int n) {
	int i;
	for(i=1; i<=n; i++) {
		if(i%2 != 0)
			printf(" %d |", i);
	}
	return i;
}
int tres(int valor) {

	int soma, i;

	if (valor >= 0) {
		for(i=0; i<=valor; i++) {
			soma += i;
		}
		printf("Resultado da soma entre numeros de 1 a n: %d", soma);
	} else {
		printf("Numero tem que ser positivo");
	}
	return soma;
}
int quatro(int a) {

	int i;

	if (a >= 0) {
		printf("Numeros multiplos de 5 de 0 a %d:\n", a);
		for(i=1; i<=a; i++) {
			if(i%5 == 0)
				printf(" %d |", i);
		}
	} else {
		printf("Numero tem que ser positivo");
	}
	return i;
}

int main() {
	char continua;
	int opcao, n, val, num;
	float lado;

	while(1) {
		printf("\n\n[1] Primos ate m");
		printf("\n[2] Area do quadrado");
		printf("\n[3] Soma de 1 a n");
		printf("\n[4] Multiplos de 5");
		printf("\n[5]Sair\n");

		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				printf("\nInforme um valor: ");
				scanf("%d", &n);

				Somaaten(n);

				printf("\nNumeros primos de 0 a %d:\n", n);
				break;
			case 2:
				printf("\nInforme o valor do lado do quadrado: ");
				scanf("%f", &lado);

				ladoQuadrado(lado);
				printf("A area do quadrado eh igual a: %.2f", ladoQuadrado(lado));

				break;
			case 3:
				printf("\nInforme um valor: ");
				scanf("%d", &val);

				tres(val);

				break;
			case 4:
				printf("Informe um valor: ");
				scanf("%d", &num);
				
				quatro(num);

				break;
			case 5:
				exit(1);
				break;
			default:
				printf("Operacao invalida!");
		}



	}


}
