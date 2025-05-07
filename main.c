#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "menu.h"

void tela_menu() {
    printf("=====================================================\n");
    printf("======================== MENU =======================\n");
    printf("=====================================================\n\n");
    printf("-----------------------------------------------------\n\n");
}

int main() {
    system("cls || clear");
    Livro livro;
    
    tela_menu();
    menu(&livro);

    return 0;
}