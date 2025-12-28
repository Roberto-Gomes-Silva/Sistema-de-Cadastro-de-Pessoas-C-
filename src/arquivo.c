#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

//salvar
void salvarPessoa(Pessoa p){
    FILE *arq = fopen("dados.txt","a");

    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    
    fprintf(arq, "%d;%s;%d\n", p.id, p.nome, p.idade);
    fclose(arq);
}

//listar
void listarPessoas(){
    FILE *arq = fopen("dados.txt", "r");
    Pessoa p;

    if (arq == NULL)
    {
        printf("nenhum dado encontrado.\n");
        return;
    }
    
    printf("\n--- LISTA DE PESSOAS ---\n");
    while (fscanf(arq, "%d;%49[^;];%d\n", &p.id, p.nome, &p.idade) !=EOF)
    {
        printf("ID: %d | Nome: %s | Idade: %d\n", p.id, p.nome, p.idade);
    }
    fclose(arq);
}

//Buscar
void buscarPessoa(int id){
    FILE *arq = fopen("dados.txt", "r");
    Pessoa p;
    int encontrado = 0;

    if (arq == NULL)
    {
        printf("Arquivo vazio!\n");
        return;
    }
    while (fscanf(arq, "%d;%49[^;];%d\n", &p.id, p.nome, &p.idade) !=EOF)
    {
        if (p.id == id)
        {
            printf("Encontrado: %s (%d anos)\n", p.nome, p.idade);
            encontrado = 1;
            break;
        }
        
    }
    
    if (!encontrado){
        printf("Pessoa nao encontrada.\n");

        }
        fclose(arq);
    
}

//editar
void editarPessoa(int id){
    FILE *arq = fopen("dados.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Pessoa p;
    int encontrado = 0;

    if (arq == NULL || temp == NULL)
    {
        printf("Arquivo vazio!\n");
        return;
    }
    
    while (fscanf(arq,"%d;%49[^;];%d\n", &p.id, p.nome, &p.idade) !=EOF)
    {
        if (p.id == id)
        {
            printf("Novo nome:");
            scanf(" %49[^\n]", p.nome);
            printf("Nova idade: ");
            scanf("%d", &p.idade);
            encontrado =  1;
        }
        fprintf(temp, "%d;%s;%d\n", p.id, p.nome, p.idade);
    }
    fclose(arq);
    fclose(temp);

    remove("dados.txt");
    rename("temp.txt", "dados.txt");

    if (encontrado)
    {
        printf("Registro editado com sucesso!\n");
    }else{
        printf("Pessoa nao encontrada.\n");
    }
    
}

//remover
void removerPessoa(int id){
    FILE *arq = fopen("dados.txt", "r");
    FILE *temp = fopen ("temp.txt", "w");
    Pessoa p;
    int encontrado = 0;

    if (arq == NULL || temp == NULL)
    {
        printf("Arquivo vazio!\n");
        return;
    }

    while (fscanf(arq, "%d;%49[^;];%d\n", &p.id, p.nome, &p.idade) !=EOF)
    {
        if (p.id != id)
        {
            fprintf(temp,"%d;%s;%d\n", p.id, p.nome, p.idade);
        }else {
            encontrado = 1;
        }
        
    }
    fclose(arq);
    fclose(temp);

    remove("dados.txt");
    rename("temp.txt", "dados.txt");

    if (encontrado)
    {
        printf("registro removido com sucesso\n");
    }else {
        printf("Pessoa nao encontrada.\n");
    }
    
    
}