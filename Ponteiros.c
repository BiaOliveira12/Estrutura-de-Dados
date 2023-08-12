#include <stdio.h>
#include <stdlib.h>

/*Ponteiros*/

int main(int argc, char *argv[]) {
	/*
	A  declaração de variavel é: 
	<tipo> *nome
	<tipo> *nome 
	O endereço para chamar o valor é:
	&nome(ESPAÇO DE MEMÓRIA QUE ESTÁ SENDO REFERENCIADO)
	*/
	int n = 10;
	int *p;
	p = &n;
	printf("Valor na memoria: %d\n", *p);
	printf("Endereco da memoria: %p\n", p);/* %p => Ponteiro */
	*p = 5;
	printf("Valor de n: %d\n", n);
	return 0;
}