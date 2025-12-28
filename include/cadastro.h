#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct 
{
    int id;
    char nome[50];
    int idade;
} Pessoa;

void cadastrar(void);
void listar(void);
void buscar(void);
void editar(void);
void remover(void);

#endif

