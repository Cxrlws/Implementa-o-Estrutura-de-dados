#ifndef COFO_H
#define COFO_H

//Definindo um aluno
typedef struct {
    char nome[30];
    int idade;
    float nota;
} Aluno;

//Definindo o Cofo
typedef struct {
    Aluno *alunos;
    int tamanho;
    int capacidade;
} Cofo;

//Funções do meu TAD (cofo)
Cofo* criarCofo(int capacidade);
int destruirCofo(Cofo *cofo);
int esvaziarCofo(Cofo *cofo);
int inserirAluno(Cofo *cofo, Aluno elemento);
int removerAlunoPorNomeIdadeNota(Cofo *cofo, char *nome, int idade, float nota);
int consultarAlunoPorNomeIdadeNota(Cofo *cofo, char *nome, int idade, float nota);


#endif
