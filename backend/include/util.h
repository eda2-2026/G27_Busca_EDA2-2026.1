#ifndef UTIL_H
#define UTIL_H

#include "buscas.h"
#include "local.h"

int strings_iguais_case_insensitive(const char *a, const char *b);
void imprimir_local(const Local *local);
void imprimir_resultado(const ResultadoBusca *resultado, const Local *locais);

#endif
