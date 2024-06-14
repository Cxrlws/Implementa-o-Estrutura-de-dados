#ifndef DLLIST_H
#define DLLIST_H

typedef struct {
    char nome[30];
    int idade;
    float nota;
} Aluno;

typedef struct Node {
    Aluno data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* first;
    Node* last;
} DLList;

DLList* criar_colecao();
void inserir(DLList* list, Aluno aluno);
int remover(DLList* list, char nome[30], int idade, float nota);
Aluno* consultar(DLList* list, char nome[30], int idade, float nota);
void listar(DLList* list);
void esvaziar(DLList* list);
void destruir(DLList* list);

#endif 
