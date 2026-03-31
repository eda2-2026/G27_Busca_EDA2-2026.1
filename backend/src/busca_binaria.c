/*
Arquivo: backend/src/busca_binaria.c
Funcao no projeto: implementar a busca binaria por id.
Conteudo: stub da funcao busca_binaria_por_id.
O que faz: reserva o modulo para a estrategia de busca em vetor ordenado.
*/
#include "buscas.h"

int busca_binaria_por_id(
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
