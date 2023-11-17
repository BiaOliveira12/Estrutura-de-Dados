#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ra;
    char nome[50];
    char curso[50];
    float notas[4];
    int anoInicio;
    int idade;
} Aluno;

typedef struct lista {
    Aluno aluno;
    struct lista *prox;
} ciclo;

ciclo* criarNo() {
    ciclo* novoNo = (ciclo*)malloc(sizeof(ciclo));
    if(novoNo == NULL) {
        printf("Erro\n");
        exit(0);
    }
    novoNo->prox = NULL;
    return novoNo;
}

Aluno lerAluno() {
    Aluno aluno;
    int i;
    printf("Informe o RA: ");
    scanf("%d", &aluno.ra);
    getchar();
    printf("Informe o nome: ");
    fgets(aluno.nome, 50, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = 0; // remove newline character
    printf("Informe a idade: ");
    scanf("%d", &aluno.idade);
    getchar();
    printf("Informe o curso: ");
    fgets(aluno.curso, 50, stdin);
    aluno.curso[strcspn(aluno.curso, "\n")] = 0; // remove newline character
    printf("Informe o ano de inicio do curso: ");
    scanf("%d", &aluno.anoInicio);
    for(i=0; i<4; i++){
        printf("Informe a %da nota: ", i+1);
        scanf("%f", &aluno.notas[i]);
    }
    return aluno;
}

float calcularMedia(Aluno aluno){
    int i;
    float soma=0;
    for(i=0; i<4; i++){
        soma += aluno.notas[i];
    }
    return soma/4;
}

void exibirAluno(Aluno aluno){
    int i;
    printf("\n%d", aluno.ra);
    printf("\t%s", aluno.nome);
    printf("\t\t%d", aluno.idade);
    printf("\t%s", aluno.curso);
    printf("\t\t%d", aluno.anoInicio);
    for(i=0; i<4; i++){
        printf("\t%.2f", aluno.notas[i]);
    }
    printf("\t%.2f", calcularMedia(aluno));
}

ciclo* inserirOrdenado(ciclo *inicio, Aluno aluno) {
    ciclo *lista = criarNo();
    lista->aluno = aluno;

    if (inicio == NULL || strcmp(aluno.nome, inicio->aluno.nome) < 0) {
        lista->prox = inicio;
        return lista;
    }

    ciclo *atual = inicio;
    while (atual->prox != NULL && strcmp(aluno.nome, atual->prox->aluno.nome) > 0) {
        atual = atual->prox;
    }

    lista->prox = atual->prox;
    atual->prox = lista;
    return inicio;
}

ciclo* buscarAlunoRA(ciclo* inicio, int ra){
    ciclo* atual = inicio;
    while(atual != NULL){
        if(atual->aluno.ra == ra)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

void exibirTurma(ciclo* inicio){
    ciclo* atual = inicio;
    while(atual != NULL){
        exibirAluno(atual->aluno);
        atual = atual->prox;
    }
}

ciclo* maiorMedia(ciclo* inicio){
    ciclo* atual = inicio;
    ciclo* maior = inicio;
    while(atual != NULL){
        if(calcularMedia(atual->aluno) > calcularMedia(maior->aluno)){
            maior = atual;
        }
        atual = atual->prox;
    }
    return maior;
}

float mediaDasMedias(ciclo* inicio){
    ciclo* atual = inicio;
    float soma = 0;
    int conta = 0;
    while(atual != NULL){
        soma += calcularMedia(atual->aluno);
        conta++;
        atual = atual->prox;
    }
    return soma/conta;
}

ciclo* excluirAluno(ciclo* inicio, char* nome){
    ciclo* atual = inicio;
    ciclo* ant = NULL;
    while(atual != NULL){
        if(strcmp(atual->aluno.nome, nome) == 0){
            if(ant == NULL){
                ciclo* novo = atual->prox;
                free(atual);
                return novo;
            } else {
                ant->prox = atual->prox;
                free(atual);
                return inicio;
            }
        }
        ant = atual;
        atual = atual->prox;
    }
    return inicio;
}


int menu(){
    int op;
    printf("\n\n--------------------------------------");
    printf("\n1-Cadastrar aluno");
    printf("\n2-Listar turma");
    printf("\n3-Buscar por RA");
    printf("\n4-Exibir aluno com maior media");
    printf("\n5-Exibir media da turma");
    printf("\n6-Excluir aluno");
    printf("\n7-Sair");
    printf("\nOpcao: ");
    scanf("%d", &op);
    return op;    
}

int main (void){
    ciclo* turma = NULL;
    int op, ra;
    char nome[50];
   
    do{
        op = menu();
        switch(op){
            case 1:
                turma = inserirOrdenado(turma, lerAluno());
                printf("\nAluno cadastrado!\n");
                break;
            case 2:
                if(turma != NULL)
                    exibirTurma(turma);
                else
                    printf("\nTurma Vazia\n");
                break;
            case 3:
                if(turma != NULL){
                    printf("Informa o RA: ");
                    scanf("%d", &ra);
                    ciclo* aluno = buscarAlunoRA(turma, ra);
                    if(aluno != NULL)
                        exibirAluno(aluno->aluno);
                    else
                        printf("\nNao encontrado\n");    
                }else
                    printf("\nTurma Vazia\n");
                break;
            case 4:
                if(turma != NULL){
                    exibirAluno(maiorMedia(turma)->aluno);
                }else
                    printf("\nTurma Vazia\n");
                break;
            case 5:
                if(turma != NULL){
                    printf("\nMedia da turma: %.2f", mediaDasMedias(turma));
                }else
                    printf("\nTurma Vazia\n");
                break;
            case 6:
    if(turma != NULL){
        char nome[50];
        printf("Informa o nome: ");
        scanf(" %[^\n]", nome);
        turma = excluirAluno(turma, nome);
        printf("Aluno Excluido\n");
    }else {
        printf("\nTurma Vazia\n");
    }
    break;

            case 7:
                printf("Ate logo");
                break;
            default:
                printf("Opcao invalida");
                break;                
        }
    } while(op!=7);
}
