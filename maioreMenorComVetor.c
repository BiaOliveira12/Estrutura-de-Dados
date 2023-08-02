#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/* Faça um programa que leia um vetor de dez posições.
Em seguida, informe o menor e maior valor para o
usuário */

int main() {
	int vet[MAX];
	int i, menor, maior, val;
	
	for(i=0; i<MAX; i++){
		printf("Informe o %do valor: ", i+1);
		scanf("%d", &vet[i]);
		
	if(i==0){
		maior = vet[i];
		menor = vet[i];
	}
	else{
		if(vet[i] > maior)
			maior = vet[i];
		if( vet[i] < menor)
			menor = vet[i];
	}
	}
	
	printf("\nO menor valor eh: %d", menor);
	printf("\nO maior valor eh: %d", maior);
	

	return 0;
}