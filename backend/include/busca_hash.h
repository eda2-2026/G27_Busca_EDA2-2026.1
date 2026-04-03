
#ifndef BUSCA_HASH_H
#define BUSCA_HASH_H

#include "local.h"
#include "util.h"

//molde para a lista encadeada
typedef struct ListaEnc_hash {
    const Local *dados_local;   // Aponta pros dados reais
    struct NoHash *proximo;     // para o caso de colisão
} ListaEnc_hash;

//monta a tabela hash de tamanho n
typedef struct {
    ListaEnc_hash **inicio;     // guarda início das listas
    size_t tamanho_total;        // tamanho total do hash
} TabelaHash;

#endif