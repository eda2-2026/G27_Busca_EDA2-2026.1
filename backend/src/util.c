/*
Arquivo: backend/src/util.c
Funcao no projeto: implementar utilitarios comuns de apoio ao backend.
Conteudo: inicializacao de resultado, comparacao de strings e funcoes de impressao.
O que faz: oferece funcoes reutilizaveis para reduzir duplicacao entre modulos.
*/
#include "util.h"

#include <ctype.h>
#include <stdio.h>

void resultado_inicializar(ResultadoBusca *resultado) {
    if (resultado == NULL) {
        return;
    }

    resultado->quantidade = 0;
    resultado->comparacoes = 0;
    resultado->indice_unico = -1;
}

int resultado_adicionar(ResultadoBusca *resultado, size_t indice) {
    if (resultado == NULL) {
        return -1;
    }

    if (resultado->quantidade >= MAX_RESULTADOS_BUSCA) {
        return -1;
    }

    resultado->indices[resultado->quantidade] = indice;
    resultado->quantidade++;
    return 0;
}

int strings_iguais_case_insensitive(const char *a, const char *b) {
    if (a == NULL || b == NULL) {
        return 0;
    }

    while (*a != '\0' && *b != '\0') {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return 0;
        }
        a++;
        b++;
    }

    return *a == '\0' && *b == '\0';
}

void imprimir_local(const Local *local) {
    if (local == NULL) {
        return;
    }

    printf(
        "id=%d | codigo=%s | nome=%s | bloco=%s | andar=%d | tipo=%s | capacidade=%d | temAr=%d | professor=%s | departamento=%s\n",
        local->id,
        local->codigo,
        local->nome,
        local->bloco,
        local->andar,
        local->tipo,
        local->capacidade,
        local->tem_ar,
        local->professor,
        local->departamento
    );
}

void imprimir_resultado(const ResultadoBusca *resultado, const Local *locais) {
    if (resultado == NULL || locais == NULL) {
        return;
    }

    if (resultado->quantidade == 0) {
        printf("Nenhum local encontrado.\n");
        printf("Comparacoes: %lu\n", resultado->comparacoes);
        return;
    }

    for (size_t i = 0; i < resultado->quantidade; i++) {
        imprimir_local(&locais[resultado->indices[i]]);
    }
    printf("Total encontrados: %zu\n", resultado->quantidade);
    printf("Comparacoes: %lu\n", resultado->comparacoes);
}
