#include <stdio.h>
#include <stdlib.h>

void Dec2Bin(int n){
	if(n == 0){
		printf("%d", n);
	}else{
		Dec2Bin(n / 2);
		printf("%d", n % 2);
	}
}

int main(){
	int numero;
	
	printf("Digite o um numero: \n");
	scanf("%d", &numero);
	Dec2Bin(numero);
}
