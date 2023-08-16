#include <stdio.h>

int fatorial(int n){
	int i;
	int res = 1;
	for(i=n;i > 0; i--)
		res *= i;
	return res;
	
}
float serie(int n){
	int i;
	float soma = 1;
	for(i=1; i<=n; i++)
		soma += 1.0/fatorial(i);
	return soma;
}
int main(){
	int n;
	
	printf("Informe N: ");
	scanf("%d", &n);
	
	printf("%d! = %d", n, fatorial(n));
	printf("\nResultado da serie: %.10f", serie(n));
}
