#include <stdio.h>
#include <stdlib.h>
#define MAX 40

typedef struct {
	int ra;
	char nome [50];
	char curso [50];
	float notas [4];
	int anoInicio;
	int idade;

} Aluno;

Aluno lerAluno() {
	Aluno aluno;
	int i;

	printf("Informe o RA: \n");
	scanf("%d", &aluno.ra);
	getchar();
	//ou poderia ser fflush(stdin);
	printf("Informe o nome: \n");
	//fgets(aluno.nome, 50, stdin); -> função segura, sabe quantos caracteres no maximo ele deve ler
	gets(aluno.nome); //descontinuado, não recomendado, ele não reconhece quebra de linha
	printf("Informe a idade: \n");
	scanf("%d", &aluno.idade);
	getchar();
	printf("Informe o curso: \n");
	gets(aluno.curso);
	printf("Infome o ano de Inicio: \n");
	scanf("%d", &aluno.anoInicio);

	for(i=0; i<4; i++) {
		printf("Informe a %da nota: \n", i+1);
		scanf("%f", &aluno.notas[i]);
	}

	return aluno;
}

float calcularMedia(Aluno aluno) {
	int i;
	float soma=0;
	for(i=0; i<4; i++) {
		soma += aluno.notas[i];
	}
	return soma/4;
}

void exibirAluno(Aluno aluno) {
	int i;
	//RA 		NOME 		IDADE  CURSO 		INICIO  N1  N2  N3  N4  MEDIA
	printf("\n%d", aluno.ra);
	printf("\t%s", aluno.nome);
	printf("\t\t%d", aluno.idade);
	printf("\t%s", aluno.curso);
	printf("\t\t%d", aluno.anoInicio);
	for(i=0; i<4; i++) {
		printf("\t%.2f", aluno.notas[i]);
		printf("\t%.2f", calcularMedia(aluno));
	}
}

int buscarAlunoRA(Aluno alunos[], int ra, int tam) {
	int i;
	for(i=0; i<tam; i++)
		if(alunos[i].ra == ra) {
			return i;
		}
	return -1;
}

void exibirTurma(Aluno alunos[], int tam) {
	if(tam > 0) {
		exibirTurma(alunos, tam-1);//a função está chamando a si própria, sendo assim uma função recursiva
		exibirAluno(alunos[tam-1]);//como essa função está sendo chamada na volta, os alunos são mostrados em ordem crescente
	}
}

Aluno maiorMedia(Aluno alunos[], int tam) {
	int i, maior = 0;
	for(i=1; i<tam; i++) {
		if(calcularMedia(alunos[i]) > calcularMedia(alunos[maior])) {
			maior = i;
		}
	}
	return alunos[maior];
}

float mediaDasMedias(Aluno alunos[], int tam) { //forma iterativa, ainda existe a forma recursiva ** ESTUDAR
	int i;
	float soma = 0;
	for (i=0; i<tam; i++) {
		soma += calcularMedia(alunos[i]);
	}
	return soma/tam;
}

int excluirAluno(Aluno alunos[], int ra, int tam) {
	int i = buscarAlunoRA(alunos, ra, tam); //pos ou -1
	if(i < 0) {
		return 0;
	}
	for (i=i; i<tam-1; i++) {
		alunos[i] = alunos[i+1];
	}
	return 1;
}

int menu() {
	int op;
	printf("\n[1] Cadastrar aluno");
	printf("\n[2] Listar turma");
	printf("\n[3] Buscar por RA");
	printf("\n[4] Exibir aluno com maior media");
	printf("\n[5] Exibir media da turma");
	printf("\n[6] Excluir por RA");
	printf("\n[7] Sair\n");
	scanf("%d", &op);
	return op;
}
int main() {
	Aluno turma[MAX];
	int matriculas = 0;
	int op, ra;

	do {
		op = menu();
		switch(op) {
			case 1:
				if(matriculas < 40) {
					turma[matriculas++] = lerAluno();
					printf("\nAluno cadastrado!\n");
				} else {
					printf("\nTurma cheia!\n");
				}
				break;
			case 2:
				if(matriculas > 0) {
					exibirTurma(turma, matriculas);
				} else {
					printf("\nTurma vazia\n");
				}
				break;
			case 3:
				if(matriculas > 0) {
					printf("Informa o RA: ");
					scanf("%d", &ra);
					ra = buscarAlunoRA(turma, ra, matriculas);
					if(ra >= 0)
						exibirAluno(turma[ra]);
					else
						printf("\nNao encontrado\n");
				} else
					printf("\nTurma Vazia\n");
				break;

			case 4:
				if(matriculas > 0) {
					exibirAluno(maiorMedia(turma, matriculas));
				} else {
					printf("\nTurma vazia\n");
				}
				break;
			case 5:
				if(matriculas > 0) {
					printf("Media da turma: %.2f", mediaDasMedias(turma, matriculas));
				} else {
					printf("\nTurma vazia\n");
				}
				break;
			case 6:
				if(matriculas > 0) {
					printf("Informe o RA: \n");
					scanf("%d", &ra);
					if(excluirAluno(turma, ra, matriculas)) {
						matriculas--;
					}
				} else {
					printf("\nTurma vazia\n");
				}
				break;
			case 7:
				printf("Ate logo!");
				break;
			default:
				printf("Opcao invalida!");
				break;
		}
	} while(op!=7);
}
