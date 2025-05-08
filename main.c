#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tipos.h"
#include "menu.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    Livro livro;
    system("cls || clear");
    menu(&livro);

    return 0;
}