/*
Arquivo: backend/include/util.h
Funcao no projeto: expor utilitarios compartilhados entre modulos.
Conteudo: funcoes de comparacao de strings e impressao de resultados.
O que faz: centraliza rotinas auxiliares reutilizadas no backend.
*/
#ifndef UTIL_H
#define UTIL_H

#include "buscas.h"
#include "local.h"

int strings_iguais_case_insensitive(const char *a, const char *b);
void imprimir_local(const Local *local);
void imprimir_resultado(const ResultadoBusca *resultado, const Local *locais);

#endif
