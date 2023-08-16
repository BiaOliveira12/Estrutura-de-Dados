#include<stdio.h>
/*Pedir 2 numeros inteiros, fazer uma função com a soma desses inteiros e retornar a soma no final*/
int soma(int a, int b){
	int rest;
	rest = a+b;
	return rest;/*O valor do parametro tem que obrigatoriamente ser do mesmo tipo que a função e o valor de retorno é o valor que será apresentado quando chamamos a função*/
}
float media(float val){
	float resto;
	resto = val/2;
	return resto;
}
int main(){
	int numero1, numero2, conta;
	float media1;
	
	printf("Digite o primeiro numero: ");
	scanf("%d", &numero1);
	
	printf("Digite o segundo numero: ");
	scanf("%d", &numero2);
	
	conta = soma(numero1, numero2);
	media1 = media(conta);
	
	printf("\nO resultado da soma dos numeros eh: %d\n", conta);
	printf("O resultado da media da soma dos numeros eh: %.1f", media1);
}
