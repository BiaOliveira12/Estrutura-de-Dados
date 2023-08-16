#include <stdio.h>
#include <stdlib.h>

/* Fatorial de 1 até n */

int main() {
	int fatorial =1;
	int n;
	
	printf("Digite um numero para saber o fatorial: ");
	scanf("%d", &n);
	
	for(int i=n;i>0;i--){
		fatorial*= i;
	}
	printf("\nO fatorial de %d eh: %d\n", n, fatorial);
}
