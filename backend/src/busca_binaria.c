/*
Funcao no projeto: implementar a busca binaria por id.
Conteudo: implementacao da funcao busca_binaria_por_id.
O que faz: encontra um id em vetor ordenado com complexidade O(log n).
*/
#include "buscas.h"

int busca_binaria_por_id(
    const Local *locais,
    size_t total,
    int id,
    ResultadoBusca *resultado
) {
    if (locais == NULL || resultado == NULL || total == 0) {
        return -1;
    }

    resultado_inicializar(resultado);

    size_t esquerda = 0;
    size_t direita = total;

    while (esquerda < direita) {
        size_t meio = esquerda + (direita - esquerda) / 2;
        resultado->comparacoes++;

        if (locais[meio].id == id) {
            resultado->indice_unico = (int)meio;
            if (resultado_adicionar(resultado, meio) != 0) {
                return -1;
            }
            return 0;
        }

        if (locais[meio].id < id) {
            esquerda = meio + 1;
        } else {
            direita = meio;
        }
    }

    return -1;
}
