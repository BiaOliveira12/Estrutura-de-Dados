#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	char nome[50];
	float notaSem;
	float notaEsp;
	float media;
}estrutura;

estrutura Cadastro(estrutura aluno){
	printf("\nDigite o nome do aluno: \n");
	gets(aluno.nome);
	printf("\nDigite a nota obtida ao longo do semestre: \n");
	scanf("%f", &aluno.notaSem);
	printf("\nDigite a nota da avaliacao especial: \n");
	scanf("%f", &aluno.notaEsp);
	return aluno;
}
float calcularMedia(estrutura aluno){
	
	aluno.media = aluno.notaEsp + aluno.notaSem/2;
	return aluno.media;
}
float mediaDasMedias(estrutura aluno[], int tam){
	int i;
	float soma = 0;
	for (i=0; i<tam; i++) {
		soma += calcularMedia(aluno[i]);
	}
	return soma/tam;
}

void exibirAluno(estrutura aluno){
	printf("Nome: %s\t", aluno.nome);
	printf("Nota Semestral: %d\t", aluno.notaSem);
	printf("Nota Especial: %d\t", aluno.notaEsp);
	printf("Nota Final: %d", aluno.media);
}
void exibirTurma(estrutura aluno[], int tam){
	if(tam > 0){
		exibirAluno(aluno[tam]);
		exibirAluno(aluno[tam]);
	}
}
int main(){
	int op, turma = 0;
	estrutura tam[MAX];
	
	printf("[1] Cadastrar aluno");
	printf("[2] Exibir turma");
	printf("[3] Media da turma");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			if(tam < 10){
				tam[turma++] = Cadastro();
				printf("\nAluno Cadastrado!");
			}else{
				printf("TURMA CHEIA!");
			}
			break;
		case 2:
			if(turma >  )
			break;
		case 3:
			
			break;
		default:
			printf("Opcao invalida!");
			break;
	}
	return 0;
}
