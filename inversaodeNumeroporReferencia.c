#include <stdio.h>
#include <stdlib.h>

void organizar(int *x, int *y){
	if(*y> *x){
		int aux = *y;
		*y = *x;
		*x = aux;
	}
}
int main(){
	int a, b;
	
	printf("Informe A: ");
	scanf("%d", &a);
	
	printf("Informe B: ");
	scanf("%d", &b);
	
	organizar(&a, &b);
	
	printf("Organizacao: A = %d | B = %d", a, b);
}
