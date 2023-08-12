#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int fatorial =1;
	int n;
	
	printf("Digite um numero para saber o fatorial: ");
	scanf("%d", &n);
	
	for(int i=n;i>0;i--){
		fatorial*= i;
	}
	printf("\nO fatorial de %d eh: %d\n", n, fatorial);
}