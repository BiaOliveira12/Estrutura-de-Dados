#include <stdio.h>

int fatorial(int n){
	int i;
	int res = 1;
	for(i=n;i > 0; i--)
		res *= i;
	return res;
	
}
int main(){
	int n;
	
	printf("Informe N: ");
	scanf("%d", &n);
	
	printf("%d! = %d", n, fatorial(n));
}
