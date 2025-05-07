#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/tipos.h"
#include "../include/relatorio.h"

void gerarRelatorioEstoque() {
    FILE *arquivo = fopen("data/livros.bin", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char nomeArquivo[50];
    snprintf(nomeArquivo, sizeof(nomeArquivo), "relatorio_estoque_%d-%02d-%02d.txt", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    FILE *relatorio = fopen(nomeArquivo, "w");
    if (!relatorio) {
        printf("Erro ao criar o arquivo de relatório.\n");
        fclose(arquivo);
        return;
    }

    fprintf(relatorio, "=====================================================\n");
    fprintf(relatorio, "================ RELATÓRIO DE ESTOQUE ===============\n");
    fprintf(relatorio, "=====================================================\n\n");

    Livro livro;
    int contador = 0;

    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        fprintf(relatorio, "Código: %d\nTítulo: %s\nAutor: %s\nPreço: %.2f\nQtd: %d\n",
                livro.codigo, livro.titulo, livro.autor, livro.preco, livro.quantidade);
        fprintf(relatorio, "-----------------------------------------------------\n");
        contador++;
    }

    if (contador == 0) {
        fprintf(relatorio, "Nenhum livro encontrado no estoque.\n");
    }

    fclose(arquivo);
    fclose(relatorio);

    printf("Relatório de estoque gerado com sucesso! Arquivo: %s\n", nomeArquivo);
}
