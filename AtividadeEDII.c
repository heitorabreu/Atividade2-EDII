#include <stdio.h>

typedef struct {
    char nome[62];
    char curso[62];
    int nro_UNESP;
}Aluno;

int main(){
    int i, n = 5;
    Aluno aluno[5];  
    FILE *f;
    f = fopen("unesp.txt", "w");
    for(i=0; i<n; i++){
        printf("\n\tAluno - [%d]\nDigite o nome do aluno: ", i+1);
        scanf("%s", aluno[i].nome);
        printf("\nDigite o curso do aluno: ");
        scanf("%s", aluno[i].curso);
        printf("\nDigite o RA do aluno: ");
        scanf("%d", &aluno[i].nro_UNESP);
    }
    for(i=0; i<n; i++)
        fprintf(f, "\n%s\n%s\n%d", aluno[i].nome, aluno[i].curso, aluno[i].nro_UNESP);
    fclose(f);
	f = fopen("unesp.txt", "r");
	i = 0;
	while(!feof(f)){
		fscanf(f, "%s", aluno[i].nome);
		printf("Nome: %s| ", aluno[i].nome);
		fscanf(f, "%s", aluno[i].curso);
		printf("Curso: %s| ", aluno[i].curso);
		fscanf(f, "%d", &aluno[i].nro_UNESP);
		printf("Nro. UNESP: %d|\n", aluno[i].nro_UNESP);
		i++;
	}
	
    return 0;
}