#include <stdio.h>
#include <string.h>
#include "../include/tipos.h"

void consultarLivro() {
    FILE *arquivo = fopen("data/livros.bin", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    int opcao;

    printf("=====================================================\n");
    printf("======================== BUSCA ======================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");

    printf("Pesquisar por:\n1. Codigo\n2. Nome\n0. Voltar\n ");
    printf("\nDigite a opcao: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 0) {
        fclose(arquivo);
        return;
    }

    Livro livro;
    int encontrado = 0;

    switch (opcao) {
        case 1: {
            int codigo;
            printf("\nDigite o codigo do livro: ");
            scanf("%d", &codigo);

            while (fread(&livro, sizeof(Livro), 1, arquivo)) {
                if (livro.codigo == codigo) {
                    printf("\nCodigo: %d\nTitulo: %s\nAutor: %s\nPreco: %.2f\nQuantidade: %d\n",
                        livro.codigo, livro.titulo, livro.autor, livro.preco, livro.quantidade);
                    encontrado = 1;
                    break;
                }
            }
            break;
        }

        case 2: {
            char nome[TAM_NOME];
            printf("\nDigite o nome do livro: ");
            fgets(nome, TAM_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            while (fread(&livro, sizeof(Livro), 1, arquivo)) {
                if (strcasecmp(livro.titulo, nome) == 0) {
                    printf("\nCodigo: %d\nTitulo: %s\nAutor: %s\nPreco: %.2f\nQuantidade: %d\n",
                        livro.codigo, livro.titulo, livro.autor, livro.preco, livro.quantidade);
                    encontrado = 1;
                }
            }
            break;
        }
        default: printf("\nOpcao invalida.\n");
    }
    if (!encontrado) {
        printf("\nLivro nao encontrado.\n");
    }
    fclose(arquivo);
}
