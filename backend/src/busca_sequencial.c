/*
Arquivo: backend/src/busca_sequencial.c
Funcao no projeto: concentrar as buscas por varredura.
Conteudo: stubs para busca por filtro e busca sequencial em tabela ordenada.
O que faz: define a estrutura base para a implementacao da Pessoa 1.
*/
#include "buscas.h"

int busca_sequencial_por_filtro(
    const Local *locais,
    size_t total,
    const FiltroLocal *filtro,
    ResultadoBusca *resultado
) {
    (void)locais;
    (void)total;
    (void)filtro;

    if (resultado == NULL) {
        return -1;
    }

    resultado_inicializar(resultado);
    return -1;
}

int busca_sequencial_tabela_ordenada_por_id(
    const Local *locais,
    size_t total,
    int id,
    ResultadoBusca *resultado
) {
    (void)locais;
    (void)total;
    (void)id;

    if (resultado == NULL) {
        return -1;
    }

    resultado_inicializar(resultado);
    return -1;
}
