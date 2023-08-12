#include <stdio.h>
#include <stdlib.h>

/* Fibonacci */
void fibo(int n){
	int pen=0; //1
	int ult1=1; //2
	int aux, i;
	
	for(i=0; i<n; i++){
		if(i < 2)
			printf("\n%d", i);
		else 
			aux = ult+pen;
			pen = ult;
			ult = aux;
			printf("\n%d", ult);
	}
}
int main(int argc, char *argv[]) {
	return 0;
}