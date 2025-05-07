#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/cadastro.h"
#include "../include/atualz_qtd.h"
#include "../include/consulta.h"

void menu(Livro *livro) {
    int opcao;
    while (1) {
        printf("=====================================================\n");
        printf("======================== MENU =======================\n");
        printf("=====================================================\n\n");
        printf("-----------------------------------------------------\n\n");

        printf("                1. Cadastro de Livro\n");
        printf("                2. Alteracao no Estoque\n");
        printf("                3. Pesquisa de Estoque\n");
        printf("                4. Relatorio do Estoque\n");
        printf("                0. Sair\n\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);

        system("cls || clear");

        switch (opcao) {
            case 1: cadastrarLivro(livro); break;
            case 2: alterarQtdLivro(); break;
            case 3: consultarLivro(); break;
            case 4: "Relatorio"; break;
            case 0: printf("Saindo...\n"); exit(0);
            default: printf("\nOpcao invalida.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar(); getchar();
        system("cls || clear");
    }
}