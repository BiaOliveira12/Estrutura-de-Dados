#include <stdio.h>
#include <stdlib.h>
void naorecursivo(int a){
	do{
		printf("\n%d", a);
	naorecursivo(a+1);
	}while (1==1);
}
void contador(int a){
	printf("\n%d", a);
	contador(a+1);
}
int main(){
	naorecursivo(0);
	return 0;
}
