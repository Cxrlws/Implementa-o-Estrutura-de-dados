#ifndef SLLIST_H
#define SLLIST_H

typedef struct {
    char nome[30];
    int idade;
    float nota;
} Aluno;

typedef struct Node {
    Aluno data;
    struct Node* next;
} Node;

typedef struct {
    Node* first;
} SLList;


SLList* criar_colecao();
void inserir(SLList* list, Aluno aluno);
void remover(SLList* list, char nome[30], int idade, float nota);
Aluno* consultar(SLList* list, char nome[30], int idade, float nota);
void listar(SLList* list);
void esvaziar(SLList* list);
void destruir(SLList* list);

#endif 
