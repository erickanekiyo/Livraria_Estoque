#include <stdio.h>
#include <stdlib.h>
#include "../include/tipos.h"

void alterarQtdLivro() {
    int codigo, quantidade, sucesso = 0;
    char tipoOperacao;

    FILE *arquivo = fopen("data/livros.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para alteracao.\n");
        return;
    }

    printf("=====================================================\n");
    printf("=============== ATUALIZAR QUANTIDADE ================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");

    printf("Digite o tipo de operacao (c para compra, v para venda): ");
    scanf(" %c", &tipoOperacao);

    printf("Digite o codigo do livro para alteracao de estoque: ");
    scanf("%d", &codigo);

    printf("Digite a quantidade de livros a ser alterada: ");
    scanf("%d", &quantidade);

    Livro livro;

    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        if (livro.codigo == codigo) {
            if (tipoOperacao == 'c' || tipoOperacao == 'C') {
                livro.quantidade += quantidade;
            } else if (tipoOperacao == 'v' || tipoOperacao == 'V') {
                livro.quantidade -= quantidade;
            } else {
                printf("Operacao invalida.\n");
                fclose(arquivo);
                return;
            }

            if (livro.quantidade < 0) {
                printf("Erro: a quantidade nao pode ser negativa.\n");
                fclose(arquivo);
                return;
            }

            fseek(arquivo, -(long int)sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, arquivo);
            printf("Quantidade do livro alterada com sucesso!\n");
            sucesso = 1;
            break;
        }
    }

    if (!sucesso) {
        printf("Livro com codigo %d não encontrado.\n", codigo);
    }

    fclose(arquivo);
}

