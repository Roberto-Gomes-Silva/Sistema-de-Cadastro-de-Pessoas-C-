#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "arquivo.h"

//cadastrar
void cadastrar (){
    Pessoa p;

    printf("ID:");
    scanf("%d", &p.id);
    printf("Nome:");
    scanf(" %49[^\n]", p.nome);
    printf("Idade: ");
    scanf("%d", &p.idade);
    
    salvarPessoa(p);
    printf("cadastro realizado com sucesso!\n");
}

//listar
void listar(){
    listarPessoas();
}

void buscar(){
    int id;
    printf("digite o ID para buscar:");
    scanf("%d", &id);

    buscarPessoa(id);
}

//editar
void editar(){
    int id;
    printf("Digite o ID para editar:");
    scanf("%d", &id);

    editarPessoa(id);
}

//remover
void remover(){
    int id;
    printf("digite o ID para remover: ");
    scanf("%d", &id);

    removerPessoa(id);
}