/*
Arquivo: backend/src/busca_indexada.c
Funcao no projeto: implementar indice primario e busca sequencial indexada.
Conteudo: stubs para construcao de indice e busca por faixa indexada.
O que faz: prepara a base para a implementacao da estrategia indexada.
*/
#include "buscas.h"

size_t construir_indice_primario(
    const Local *locais,
    size_t total,
    size_t passo,
    EntradaIndice *indice,
    size_t capacidade_indice
) {
    (void)locais;
    (void)total;
    (void)passo;
    (void)indice;
    (void)capacidade_indice;

    return 0;
}

int busca_sequencial_indexada_por_id(
    const Local *locais,
    size_t total,
    int id,
    const EntradaIndice *indice,
    size_t total_indice,
    ResultadoBusca *resultado
) {
    (void)locais;
    (void)total;
    (void)id;
    (void)indice;
    (void)total_indice;

    if (resultado == NULL) {
        return -1;
    }

    resultado_inicializar(resultado);
    return -1;
}
