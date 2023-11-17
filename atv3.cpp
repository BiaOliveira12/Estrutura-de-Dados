#include <stdio.h>
#define N 2

typedef struct {
	char nome[50];
	float notas[2];
	float notaEsp;
} Registro;

Registro registrarAluno(){
	Registro aluno;
	
	printf("Digite o nome: ");
	gets(aluno.nome);
	
	for (int i = 1; i < 3; i++){
		printf("Digite a %da nota: ",i);
		scanf("%f",&aluno.notas[i]);
	}
	
	printf("Digite a nota da prova especial: ");
	scanf("%f",&aluno.notaEsp);
	
	return aluno;
}

float media(Registro aluno){
	float soma = 0;
	float media = 0;
	for (int i = 1; i < 3; i++){
		soma += aluno.notas[i];
	}
	media = soma/2;
	return media;
}

float mediaMedias(Registro aluno[], int tam){
	float soma = 0;
	for (int i = 1; i < tam + 1; i++){
		soma += media(aluno[i]);
	}
	return soma/tam;
}

int main(){
	Registro reginaldo[N];
	int teclado = 0;
	int op;
	printf("\n[1] Cadastrar aluno");
	printf("\n[2] Mostrar notas");
	printf("\n[4] Media final");
	printf("\n[4] Sair\n");
	scanf("%d", &op);
	do{
		switch(op){
			case 1:
				if (teclado < N){
					reginaldo[teclado++] = registrarAluno();
					printf("Aluno cadastrado!");
				}else{
					printf("Turma cheia");
				}
			break;
			
			case 2:
				if (teclado > 0){
					
					for (int i = 1; i < 3; i++){
						printf("%da nota %.2f\t",i ,reginaldo.notas);
					}
					printf("%.2f\t",reginaldo.notaEsp);
					printf("%.2f",media(aluno));
				}else{
					
				}	
		}
	}while(true);
		
}
