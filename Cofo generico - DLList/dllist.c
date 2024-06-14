#include <stdlib.h>
#include <string.h>
#include "dllist.h"

DLList* criar_colecao() {
    DLList* list = (DLList*)malloc(sizeof(DLList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void inserir(DLList* list, Aluno aluno) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = aluno;
    new_node->next = list->first;
    new_node->prev = NULL;
    if (list->first != NULL) {
        list->first->prev = new_node;
    } else {
        list->last = new_node;
    }
    list->first = new_node;
}

int remover(DLList* list, char nome[30], int idade, float nota) {
    Node *current = list->first;
    while (current != NULL) {
        if (strcmp(current->data.nome, nome) == 0 && current->data.idade == idade && current->data.nota == nota) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->first = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->last = current->prev;
            }
            free(current);
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

Aluno* consultar(DLList* list, char nome[30], int idade, float nota) {
    Node* current = list->first;
    while (current != NULL) {
        if (strcmp(current->data.nome, nome) == 0 && current->data.idade == idade && current->data.nota == nota) {
            return &current->data;
        }
        current = current->next;
    }
    return NULL;
}

void listar(DLList* list) {
    Node* current = list->first;
    while (current != NULL) {
        current = current->next;
    }
}

void esvaziar(DLList* list) {
    Node* current = list->first;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    list->first = NULL;
    list->last = NULL;
}

void destruir(DLList* list) {
    esvaziar(list);
    free(list);
}
