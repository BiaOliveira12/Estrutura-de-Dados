#include <stdio.h>
#include <stdlib.h>
int maiorValor(int v[], int tam, int indice){
	
	if(tam == 0){
		return v[indice]; //maior elemento
	}else{
		if(v[tam-1] > v[indice]){
			return maiorValor(v, tam - 1, tam - 1);
		}else{
			return maiorValor(v, tam -1, indice);
		}
	}
}
int main(){
	int val[5] = {1, 2, 6, 8, 3};
	
	
	printf("Maior valor: %d", maiorValor(val, 5, 0));
	return 0;
}
