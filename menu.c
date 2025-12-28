#include <stdio.h>
#include "menu.h"
#include "cadastro.h"

void menu(){
int opcao;

    do
    {
        printf("\n====Sistema de Cadastro====\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Buscar\n");
    printf("4 - Editar\n");
    printf("5 -Rremover\n");
    printf("0 - Sair\n");
    printf("Escolha :");
    scanf("%d", &opcao);

    switch (opcao){
        case 1: cadastrar(); break;
        case 2: listar(); break;
        case 3: buscar (); break;
        case 4: editar(); break;
        case 5: remover(); break;
        case 0: printf("Saindo...\n"); break;
        default: printf("Opcao invalida!\n");
    }
    }
    while (opcao !=0);
      
}