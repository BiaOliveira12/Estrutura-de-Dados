#include <stdio.h>
#include <stdlib.h>

/* Mostrar se o numero digitado é par ou impar*/
int ehpar(int n){
	return !(n%2);/*A sentença está sendo negada, então retornará a 1*/
	/*return n%2 == 0 ? 1 : 0; Após a (?), o resultado que irá aparecer se a condição for verdadeira/ Após os (:), o resultado que irá aparecer se a condição for falsa*/
}

int main(int argc, char *argv[]) {
	int val;
	
	printf("Informe um numero: ");
	scanf("%d", &val);
	
	if(ehpar(val))
		printf("%d eh par", val);
	else
		printf("%d nao eh par", val);
	
	return 0;
}