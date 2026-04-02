/*
Funcao no projeto: implementar indice primario e busca sequencial indexada.
Conteudo: construcao de indice primario e busca por faixa indexada.
O que faz: reduz a varredura para um trecho menor do vetor ordenado.
*/
#include "buscas.h"

size_t construir_indice_primario(
    const Local *locais,
    size_t total,
    size_t passo,
    EntradaIndice *indice,
    size_t capacidade_indice
) {
    if (locais == NULL || indice == NULL || total == 0 || capacidade_indice == 0) {
        return 0;
    }

    if (passo == 0) {
        passo = 1;
    }

    size_t total_indice = 0;
    for (size_t i = 0; i < total && total_indice < capacidade_indice; i += passo) {
        indice[total_indice].id_minimo = locais[i].id;
        indice[total_indice].posicao_inicio = i;
        total_indice++;
    }

    if (total_indice < capacidade_indice && indice[total_indice - 1].posicao_inicio != (total - 1)) {
        indice[total_indice].id_minimo = locais[total - 1].id;
        indice[total_indice].posicao_inicio = total - 1;
        total_indice++;
    }

    return total_indice;
}

int busca_sequencial_indexada_por_id(
    const Local *locais,
    size_t total,
    int id,
    const EntradaIndice *indice,
    size_t total_indice,
    ResultadoBusca *resultado
) {
    if (locais == NULL || indice == NULL || resultado == NULL || total == 0 || total_indice == 0) {
        return -1;
    }

    resultado_inicializar(resultado);

    size_t inicio = 0;
    size_t fim = total;

    resultado->comparacoes++;
    if (id < indice[0].id_minimo) {
        fim = indice[0].posicao_inicio;
    } else {
        inicio = indice[0].posicao_inicio;

        for (size_t i = 1; i < total_indice; i++) {
            resultado->comparacoes++;
            if (id < indice[i].id_minimo) {
                fim = indice[i].posicao_inicio;
                break;
            }
            inicio = indice[i].posicao_inicio;
        }
    }

    if (inicio >= total) {
        return -1;
    }
    if (fim > total) {
        fim = total;
    }
    if (inicio > fim) {
        return -1;
    }

    for (size_t i = inicio; i < fim; i++) {
        resultado->comparacoes++;

        if (locais[i].id == id) {
            resultado->indice_unico = (int)i;
            if (resultado_adicionar(resultado, i) != 0) {
                return -1;
            }
            return 0;
        }

        if (locais[i].id > id) {
            return -1;
        }
    }

    return -1;
}
