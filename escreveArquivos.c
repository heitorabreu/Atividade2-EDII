#include "declaracoesAtividadeEDII.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    P->tamanho++;
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
    scanf("%54[^\n]", aluno->nome);
    setbuf(stdin, NULL);
    printf("\nDigite o curso do aluno: ");
    scanf("%54[^\n]*c", aluno->curso);
    setbuf(stdin, NULL);
    printf("\nDigite o RA do aluno: ");
    scanf("%d", &aluno->nro_UNESP);
    
    inserePilha(P, aluno);
    
    sprintf(ra, "%s|%s|%d", aluno->nome, aluno->curso, aluno->nro_UNESP);
    tamanho = strlen(ra);
    while(tamanho < 128){
        strcat(ra, "#");
        tamanho++;
    }
    
    if(f != NULL && f2 != NULL){
    fprintf(f, "%s", ra);
    fprintf(f2, "%d\n", aluno->nro_UNESP);
    }
    
    fclose(f);
    fclose(f2);

}

void imprimeNoArquivo(pilha *p){
    FILE *index, *registros;
    Aluno *aux = p->topo;
    char ra[128];
    int tamanho, contador = 0;
    
    index = fopen("index.txt", "w");
    fprintf(index, "%d\n", p->tamanho);
    registros = fopen("unesp.txt", "w");

    while(aux){
        sprintf(ra, "%s|%s|%d", aux->nome, aux->curso, aux->nro_UNESP);
        tamanho = strlen(ra);
        while(tamanho < 128){
            strcat(ra, "#");
            tamanho++;
        }
        fprintf(index, "%d %d\n", aux->nro_UNESP, contador);
        fprintf(registros, "%s", ra);

        contador++;
        aux = aux->prox;
    }
    fclose(index);
    fclose(registros);
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