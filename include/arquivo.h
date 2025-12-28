#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "cadastro.h"

void salvarPessoa(Pessoa p);
void listarPessoas(void);
void buscarPessoa(int id);
void editarPessoa(int id);
void removerPessoa(int id);

#endif