#include <stdio.h>
#include <stdlib.h>

/* Calculadora com operações básicas */
void calculadora(int op, float n1, float n2){
	switch(op){
		case 1: 
			printf("%.2f + %.2f = %.2f", n1, n2, n1+n2);
			break;
		case 2: 
			printf("%.2f - %.2f = %.2f", n1, n2, n1-n2);
			break;
		case 3:
			printf("%.2f * %.2f = %.2f", n1, n2, n1*n2);
			break;
		case 4: 
			if(n2==0)
				printf("Nao eh possivel dividir por zero!");
			else
				printf("%.2f / %.2f = %.2f", n1, n2, n1/n2);	
			break;
		default:
			printf("Operacao invalida!");
			break;
	}
}

int main(int argc, char *argv[]) {
	int op; // 1 - SOMA, 2 - SUB, 3 - MULT e 4 - DIVISÃO
	float n1, n2;
	
	printf("Informe a operacao: \n[1]Soma \n[2]Subtracao \n[3]Multiplicacao \n[4]Divisao \nOpcao");
	scanf("%d", &op);
	
	printf("Informe o primeiro valor: ");
	scanf("%f", &n1);
	
	printf("Informe o segundo valor: ");
	scanf("%f", &n2);
	
	calculadora(op, n1, n2);
}