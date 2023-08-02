#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que determine o maior e o menor
valor de uma sequência de N valores fornecidos pelo
usuário.*/

int main() {
	int n, i, val, maior, menor;
	
	
	
	printf("Informe N: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Informe o %d-ezimo valor: ", i+1);
		scanf("%d", &val);
		
		if(i==0){
			menor = val;
			maior = val;
		}
		else{
			if(val > maior)
				maior = val;
			if(val < menor)
				menor = val;
		}
	}
	
	printf("\nO menor valor eh: %d", menor);
	printf("\nO maior valor eh: %d", maior);
	return 0;
}