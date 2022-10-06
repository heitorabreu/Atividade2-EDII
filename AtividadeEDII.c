#include <stdio.h>
#include "escreveArquivos.c"

void encerraPrograma(pilha*);
void iniciaPrograma(pilha*);

int main(){
    pilha *P = malloc(sizeof(pilha));
    inicializaPilha(P);
    cadastraAluno(P);
    imprimePilha(P);
    encerraPrograma(P);
    return 0;
}

void iniciaPrograma(pilha* P){
    //Procurar por funçoes na biblioteca string.h
    //que separem strings
}

void encerraPrograma(pilha* P){
    imprimeNoArquivo(P);
}