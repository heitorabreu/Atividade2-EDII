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
void consultaAluno();
void inicializaPilha(pilha*);
void inserePilha(pilha*, Aluno*);
void imprimePilha(pilha *);
void imprimeNoArquivo(pilha*);