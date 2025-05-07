#ifndef TIPOS_H
#define TIPOS_H

#define TAM_NOME 100
#define TAM_AUTOR 100
#define TAM_DESC 200

typedef struct {
    int codigo;
    char titulo[TAM_NOME];
    char autor[TAM_AUTOR];
    char descricao[TAM_DESC]; //Não obrigatorio
    int quantidade;
    float preco;
} Livro;

#endif