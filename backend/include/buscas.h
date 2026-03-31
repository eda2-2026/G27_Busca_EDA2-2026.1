/*
Arquivo: backend/include/buscas.h
Funcao no projeto: declarar contratos das buscas e estruturas de resultado.
Conteudo: ResultadoBusca, EntradaIndice e assinaturas das funcoes de busca.
O que faz: garante uma API unica para as implementacoes de busca no backend.
*/
#ifndef BUSCAS_H
#define BUSCAS_H

#include <stddef.h>
#include "local.h"

#define MAX_RESULTADOS_BUSCA 256

typedef struct {
    size_t indices[MAX_RESULTADOS_BUSCA];
    size_t quantidade;
    unsigned long comparacoes;
    int indice_unico;
} ResultadoBusca;

typedef struct {
    int id_minimo;
    size_t posicao_inicio;
} EntradaIndice;

void resultado_inicializar(ResultadoBusca *resultado);
int resultado_adicionar(ResultadoBusca *resultado, size_t indice);

int busca_sequencial_por_filtro(
    const Local *locais,
    size_t total,
    const FiltroLocal *filtro,
    ResultadoBusca *resultado
);

int busca_sequencial_tabela_ordenada_por_id(
    const Local *locais,
    size_t total,
    int id,
    ResultadoBusca *resultado
);

int busca_binaria_por_id(
    const Local *locais,
    size_t total,
    int id,
    ResultadoBusca *resultado
);

size_t construir_indice_primario(
    const Local *locais,
    size_t total,
    size_t passo,
    EntradaIndice *indice,
    size_t capacidade_indice
);

int busca_sequencial_indexada_por_id(
    const Local *locais,
    size_t total,
    int id,
    const EntradaIndice *indice,
    size_t total_indice,
    ResultadoBusca *resultado
);

int busca_interpolacao_por_id(
    const Local *locais,
    size_t total,
    int id,
    ResultadoBusca *resultado
);

#endif
