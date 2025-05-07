#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "menu.h"

int main() {
    system("cls || clear");
    Livro livro;

    tela_menu();
    menu(&livro);

    return 0;
}