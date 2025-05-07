#include <stdio.h>
#include <string.h>
#include "../include/cadastro.h"

void cadastrarLivro(Livro *livro) {
    char confirmacao;

    printf("=====================================================\n");
    printf("====================== CADASTRO =====================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");

    printf("Codigo: ");
    scanf("%d", &livro->codigo);
    getchar();

    printf("Titulo: ");
    fgets(livro->titulo, TAM_NOME, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(livro->autor, TAM_AUTOR, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = '\0';

    printf("Descricao (opcional): ");
    fgets(livro->descricao, TAM_DESC, stdin);
    livro->descricao[strcspn(livro->descricao, "\n")] = '\0';

    printf("Preco unitario: ");
    scanf("%f", &livro->preco);
    getchar();

    printf("\nConfirme os dados do livro:\n");
    printf("Codigo: %d\n", livro->codigo);
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Descricao: %s\n", livro->descricao[0] ? livro->descricao : "(sem descricao)");
    printf("Preco unitario: R$ %.2f\n", livro->preco);

    printf("\nDeseja salvar este livro? (s/n): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 's' || confirmacao == 'S') {
        FILE *arquivo = fopen("data/livros.bin", "ab");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para salvamento.\n");
            return;
        }

        fwrite(livro, sizeof(Livro), 1, arquivo);
        fclose(arquivo);

        printf("\nLivro salvo com sucesso no arquivo!\n");
    } else {
        printf("\nCadastro cancelado.\n"); 
        memset(livro, 0, sizeof(Livro));
    }
}

