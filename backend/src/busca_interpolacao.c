/*
Arquivo: backend/src/busca_interpolacao.c
Funcao no projeto: implementar busca por interpolacao para ids numericos.
Conteudo: stub da funcao busca_interpolacao_por_id.
O que faz: separa o ponto de extensao para comparacao com busca binaria.
*/
#include "buscas.h"

int busca_interpolacao_por_id(
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
