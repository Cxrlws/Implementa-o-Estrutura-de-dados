/*
Trabalho de implementação
Aluno: Carlos Vinicius Lima Pereira
Ambiente de execução: Visual Studio Code
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

#define MAX_NOME 30

void print_aluno(Aluno* aluno) {
    printf("Nome: %s, Idade: %d, Nota: %.2f\n", aluno->nome, aluno->idade, aluno->nota);
}

void listar_e_print(SLList* list) {
    Node* current = list->first;
    while (current != NULL) {
        print_aluno(&current->data);
        current = current->next;
    }
}

int main() {
    SLList* lista = criar_colecao();
    if (lista == NULL) {
        printf("Erro ao criar a coleção.\n");
        return 1;
    }

    int opcao = 0;
    while (opcao != 6) {
        printf("\n--- Menu ---\n");
        printf("1. Inserir aluno\n");
        printf("2. Remover aluno por nome, idade e nota\n");
        printf("3. Consultar aluno por nome, idade e nota\n");
        printf("4. Listar todos os alunos\n");
        printf("5. Esvaziar coleção\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aluno aluno;
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno.nome);
                printf("Digite a idade do aluno: ");
                scanf("%d", &aluno.idade);
                printf("Digite a nota do aluno: ");
                scanf("%f", &aluno.nota);

                inserir(lista, aluno);
                printf("Aluno inserido com sucesso.\n");
                break;
            }
            case 2: {
                char nome[MAX_NOME];
                int idade;
                float nota;
                printf("Digite o nome do aluno a ser removido: ");
                scanf("%s", nome);
                printf("Digite a idade do aluno a ser removido: ");
                scanf("%d", &idade);
                printf("Digite a nota do aluno a ser removido: ");
                scanf("%f", &nota);

                remover(lista, nome, idade, nota);
                printf("Aluno removido com sucesso.\n");
                break;
            }
            case 3: {
                char nome[MAX_NOME];
                int idade;
                float nota;
                printf("Digite o nome do aluno a ser consultado: ");
                scanf("%s", nome);
                printf("Digite a idade do aluno a ser consultado: ");
                scanf("%d", &idade);
                printf("Digite a nota do aluno a ser consultado: ");
                scanf("%f", &nota);

                Aluno* aluno = consultar(lista, nome, idade, nota);
                if (aluno != NULL) {
                    printf("Aluno encontrado:\n");
                    print_aluno(aluno);
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            }
            case 4: {
                printf("--- Lista de Alunos ---\n");
                listar_e_print(lista);
                break;
            }
            case 5: {
                esvaziar(lista);
                printf("Coleção esvaziada com sucesso.\n");
                break;
            }
            case 6: {
                printf("Saindo...\n");
                break;
            }
            default:
                printf("Opcao invalida.\n");
        }
    }

    destruir(lista);
    return 0;
}
