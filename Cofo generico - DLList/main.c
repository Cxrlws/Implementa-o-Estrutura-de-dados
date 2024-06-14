#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"

#define MAX_NOME 30

void print_aluno(Aluno* aluno) {
    printf("Nome: %s, Idade: %d, Nota: %.2f\n", aluno->nome, aluno->idade, aluno->nota);
}

void listar_e_print(DLList* list) {
    Node* current = list->first;
    while (current != NULL) {
        print_aluno(&current->data);
        current = current->next;
    }
}

DLList* criar_nova_colecao() {
    DLList* lista = criar_colecao();
    if (lista == NULL) {
        printf("Erro ao criar a coleção.\n");
        exit(1);
    }
    printf("Coleção criada com sucesso.\n");
    return lista;
}

int main() {
    DLList* lista = NULL;
    int opcao = 0;

    while (opcao != 7) {
        printf("\n--- Menu ---\n");
        printf("1. Criar nova coleção\n");
        printf("2. Inserir aluno\n");
        printf("3. Remover aluno por nome, idade e nota\n");
        printf("4. Consultar aluno por nome, idade e nota\n");
        printf("5. Listar todos os alunos\n");
        printf("6. Esvaziar coleção\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (lista != NULL) {
                    destruir(lista);
                }
                lista = criar_nova_colecao();
                break;
            case 2:
                if (lista == NULL) {
                    printf("Por favor, crie uma coleção primeiro.\n");
                } else {
                    Aluno aluno;
                    printf("Digite o nome do aluno: ");
                    scanf("%s", aluno.nome); 
                    printf("Digite a idade do aluno: ");
                    scanf("%d", &aluno.idade);
                    printf("Digite a nota do aluno: ");
                    scanf("%f", &aluno.nota);

                    inserir(lista, aluno);
                    printf("Aluno inserido com sucesso.\n");
                }
                break;
            case 3:
                if (lista == NULL) {
                    printf("Por favor, crie uma coleção primeiro.\n");
                } else {
                    char nome[MAX_NOME];
                    int idade;
                    float nota;
                    printf("Digite o nome do aluno a ser removido: ");
                    scanf("%s", nome); 
                    printf("Digite a idade do aluno a ser removido: ");
                    scanf("%d", &idade);
                    printf("Digite a nota do aluno a ser removido: ");
                    scanf("%f", &nota);

                    int resultado = remover(lista, nome, idade, nota);
                    if (resultado) {
                        printf("Aluno removido com sucesso.\n");
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                }
                break;
            case 4:
                if (lista == NULL) {
                    printf("Por favor, crie uma coleção primeiro.\n");
                } else {
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
                }
                break;
            case 5:
                if (lista == NULL) {
                    printf("Por favor, crie uma coleção primeiro.\n");
                } else {
                    printf("--- Lista de Alunos ---\n");
                    listar_e_print(lista);
                }
                break;
            case 6:
                if (lista == NULL) {
                    printf("Por favor, crie uma coleção primeiro.\n");
                } else {
                    esvaziar(lista);
                    printf("Coleção esvaziada com sucesso.\n");
                }
                break;
            case 7:
                printf("Saindo...\n");
                if (lista != NULL) {
                    destruir(lista);
                }
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
