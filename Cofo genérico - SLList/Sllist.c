#include <stdlib.h>
#include <string.h>
#include "sllist.h"

SLList* criar_colecao() {
    SLList* list = (SLList*)malloc(sizeof(SLList));
    list->first = NULL;
    return list;
}

void inserir(SLList* list, Aluno aluno) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = aluno;
    new_node->next = list->first;
    list->first = new_node;
}

void remover(SLList* list, char nome[30], int idade, float nota) {
    Node *current = list->first, *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->data.nome, nome) == 0 && current->data.idade == idade && current->data.nota == nota) {
            if (prev == NULL) {
                list->first = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

Aluno* consultar(SLList* list, char nome[30], int idade, float nota) {
    Node* current = list->first;
    while (current != NULL) {
        if (strcmp(current->data.nome, nome) == 0 && current->data.idade == idade && current->data.nota == nota) {
            return &current->data;
        }
        current = current->next;
    }
    return NULL;
}

void listar(SLList* list) {
    Node* current = list->first;
    while (current != NULL) {
        current = current->next;
    }
}

void esvaziar(SLList* list) {
    Node* current = list->first;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    list->first = NULL;
}

void destruir(SLList* list) {
    esvaziar(list);
    free(list);
}
