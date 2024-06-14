/*
Trabalho de implementação
Aluno: Carlos Vinicius Lima Pereira
Ambiente de execução: Visual Studio Code
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cofo.h" 

#define MAX_NOME 30 // Tamanho máximo para o nome do aluno

int main() {
    int capacidade;
    printf("Digite a capacidade inicial do cofo: ");
    scanf("%d", &capacidade);

    Cofo *cofo = criarCofo(capacidade);
    if (cofo == NULL) {
        printf("Erro ao criar o cofo.\n");
        return 1;
    }

    int opcao = 0;
    while (opcao != 6) {
        printf("\n--- Menu ---\n");
        printf("1. Inserir aluno\n");
        printf("2. Remover aluno por nome, idade e nota\n");
        printf("3. Consultar aluno por nome, idade e nota\n");
        printf("4. Listar todos os alunos\n");
        printf("5. Esvaziar cofo\n");
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

                if (inserirAluno(cofo, aluno)){
                    printf("Aluno inserido com sucesso.\n");
                }else{
                    printf("Erro ao inserir aluno. Cofo cheio.\n");
                }
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

                if (removerAlunoPorNomeIdadeNota(cofo, nome, idade, nota))
                    printf("Aluno removido com sucesso.\n");
                else
                    printf("Aluno nao encontrado.\n");
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

                int posicao = consultarAlunoPorNomeIdadeNota(cofo, nome, idade, nota);
                if (posicao)
                    printf("Aluno encontrado na posicao %d.\n", posicao);
                else
                    printf("Aluno nao encontrado.\n");
                break;
            }
            case 4: {
                printf("--- Lista de Alunos ---\n");
                for (int i = 0; i < cofo->tamanho; i++) {
                    printf("Nome: %s, Idade: %d, Nota: %.2f\n", cofo->alunos[i].nome, cofo->alunos[i].idade, cofo->alunos[i].nota);
                }
                break;
            }
            case 5: {
                if (esvaziarCofo(cofo))
                    printf("Cofo esvaziado com sucesso.\n");
                else
                    printf("Erro ao esvaziar o cofo.\n");
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

    destruirCofo(cofo);
    return 0;
}
