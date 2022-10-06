#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[55];
    char curso[55];
    int nro_UNESP;
    struct aluno *prox;
}Aluno;

typedef struct{
    Aluno *topo;
    int tamanho;
}pilha;

void cadastraAluno(pilha*);
//void consultaAluno();
void inicializaPilha(pilha*);
void inserePilha(pilha*, Aluno*);
void imprimePilha(pilha *P);


int main(){
    pilha *P = malloc(sizeof(pilha));
    inicializaPilha(P);
    cadastraAluno(P);
    imprimePilha(P);
    return 0;
}

void imprimePilha(pilha *P){
    Aluno *aux = P->topo;
    while(aux){
        printf("%s|%s|%d", aux->nome, aux->curso, aux->nro_UNESP);
        aux = aux->prox;
    }
}

void inicializaPilha(pilha *p){
    p->topo = NULL;
    p->tamanho = 0;
}

void inserePilha(pilha *P, Aluno *aluno){
    aluno->prox = P->topo;
    P->topo = aluno;
}

void cadastraAluno(pilha *P){
    Aluno *aluno = malloc(sizeof(Aluno));
    FILE *f, *f2;
    char ra[128];
    int tamanho;
    
    f = fopen("unesp.txt", "w");
    if(f == NULL){
        printf("Não foi possível abrir o arquivo.");
        return;
    }
    
    f2 = fopen("index.txt", "w");
    if(f2 == NULL){
        printf("Não foi possível abrir o arquivo.");
        return;
    }
    
    printf("\nDigite o nome do aluno: ");
    fgets(aluno->nome, 54, stdin);
    printf("\nDigite o curso do aluno: ");
    fgets(aluno->curso, 54, stdin);
    printf("\nDigite o RA do aluno: ");
    scanf("%d", &aluno->nro_UNESP);
    sprintf(ra, "%s|%s|%d", aluno->nome, aluno->curso, aluno->nro_UNESP);
    
    inserePilha(P, aluno);

    tamanho = strlen(ra);
    while(tamanho < 128){
        strcat(ra, "#");
        tamanho++;
    }
    
    // if(f != NULL && f2 != NULL){
    //     fprintf(f, "%s", ra);
    //     fprintf(f2, "%d\n", aluno->nro_UNESP);
    // }
    
    fclose(f);
    fclose(f2);

}

// void consultaAluno(){
//     Aluno aluno;
//     FILE *f;
//     f = fopen("unesp.txt", "r");
// 	while(!feof(f)){
// 		fscanf(f, "%s", aluno.nome);
// 		printf("Nome: %s| ", aluno.nome);
// 		fscanf(f, "%s", aluno.curso);
// 		printf("Curso: %s| ", aluno.curso);
// 		fscanf(f, "%d", &aluno.nro_UNESP);
// 		printf("Nro. UNESP: %d|\n", aluno.nro_UNESP);
// 	}
//     fclose(f);
// }