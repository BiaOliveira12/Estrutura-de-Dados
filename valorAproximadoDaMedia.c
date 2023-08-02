#include <stdio.h>
#include <stdlib.h> //abs
#include <math.h>
#define MAX 10


/* Faça um programa que leia um vetor de 10 posições.
Após a leitura, defina qual é o valor do vetor mais
próximo da média dos valores do vetor*/

int main() {
	int vet[MAX], i, pos;
	float media;
	
	for(i=0; i<MAX; i++){
		printf("Informe o %do valor: ", i+1);
		scanf("%d", &vet[i]);
		media += (float)vet[i]/MAX;
	}
	printf("\nMedia: %.2f", media);
	pos = 0;
	for(i=1; i<MAX; i++){
		
		/* PODE SER FEITO ASSIM TAMBÉM:
		float d1 = vet[i]-media;
		//d1 = (cond) ? true : false;
		d1 = d1 < 0 ? d1*-1 : d1;*/
		
		if(fabs(vet[i] - media) < fabs(vet[pos] - media))
			pos = i;
	
			
	}
		printf("\nO valor mais proximo da media (%.2f) eh: %d", media, vet[pos]);
	return 0;
}