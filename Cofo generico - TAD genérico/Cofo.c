#include "cofo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

Cofo* criarCofo(int capacidade) {
    Cofo *cofo = (Cofo*)malloc(sizeof(Cofo));
    if (cofo != NULL){
        cofo->alunos = (Aluno*)malloc(capacidade * sizeof(Aluno));
        if (cofo->alunos != NULL){
            cofo->tamanho = 0;
            cofo->capacidade = capacidade;
            return cofo;
        }
        //Libera memoria
        free(cofo->alunos);
        free(cofo);
    }

    return NULL;
}

int destruirCofo(Cofo *cofo) {
    if(cofo != NULL){
        if (cofo->tamanho == 0){
            free(cofo->alunos);
            free(cofo);
            return TRUE;  
        }
    }
    //Não foi possivel destruir o cofo
    return FALSE;
}

int esvaziarCofo(Cofo *cofo) {
    cofo->tamanho = 0;
    if (cofo->tamanho == 0){
        return TRUE;
    }
    return FALSE;
}

int inserirAluno(Cofo *cofo, Aluno aluno) {
    if (cofo->tamanho < cofo->capacidade) {
        cofo->alunos[cofo->tamanho++] = aluno;
        return TRUE;
    }
    return FALSE;
}

int removerAlunoPorNomeIdadeNota(Cofo *cofo, char *nome, int idade, float nota) {
    for (int i = 0; i < cofo->tamanho; i++) {
        if (strcmp(cofo->alunos[i].nome, nome) == 0 && cofo->alunos[i].idade == idade && cofo->alunos[i].nota == nota) {
            for (int j = i; j < cofo->tamanho - 1; j++) {
                cofo->alunos[j] = cofo->alunos[j + 1];//Movendo os alunos para uma posição a frente (reorganizando o vetor)
            }
            cofo->tamanho--;
            return TRUE;
        }
    }
    //Aluno não encontrado
    return FALSE;
}

int consultarAlunoPorNomeIdadeNota(Cofo *cofo, char *nome, int idade, float nota) {
    for (int i = 0; i < cofo->tamanho; i++) {
        if (strcmp(cofo->alunos[i].nome, nome) == 0 && cofo->alunos[i].idade == idade && cofo->alunos[i].nota == nota) {
            return i; //Retorna a posição do aluno no vetor
        }
    }
    //Aluno não encontrado
    return FALSE;
}
