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
}pilha;

int indice = 0;

void cadastraAluno();
void consultaAluno();

int main(){
    pilha *p = sizeof(pilha);
    p->topo = NULL;

    return 0;
}

Aluno cadastraAluno(){
    Aluno aluno;  
    FILE *f, *f2;
    char ra[128];
    int tamanho;
    
    f = fopen("unesp.txt", "w");
    if(f == NULL)
        return ;
    
    f2 = fopen("index.txt", "w");
    if(f2 == NULL)
        return ;
    
    printf("\nDigite o nome do aluno: ");
    gets(aluno.nome);
    printf("\nDigite o curso do aluno: ");
    gets(aluno.curso);
    printf("\nDigite o RA do aluno: ");
    scanf("%d", &aluno.nro_UNESP);
    sprintf(ra, "%s|%s|%d", aluno.nome, aluno.curso, aluno.nro_UNESP);
    
    fprintf(f2, "%d %d\n", aluno.nro_UNESP, indice);
    indice++;
    
    tamanho = strlen(ra);
    
    while(tamanho < 128){
        strcat(ra, "#");
        tamanho++;
    }
    
    fprintf(f, ra);
    
    fclose(f);
    fclose(f2);

    return aluno;
}

void consultaAluno(){
    Aluno aluno;
    FILE *f;
    f = fopen("unesp.txt", "r");
	while(!feof(f)){
		fscanf(f, "%s", aluno.nome);
		printf("Nome: %s| ", aluno.nome);
		fscanf(f, "%s", aluno.curso);
		printf("Curso: %s| ", aluno.curso);
		fscanf(f, "%d", &aluno.nro_UNESP);
		printf("Nro. UNESP: %d|\n", aluno.nro_UNESP);
	}
    fclose(f);
}