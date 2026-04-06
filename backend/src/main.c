#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "buscas.h"
#include "dataset.h"
#include "util.h"

#define CAPACIDADE_DATASET 128
#define CAPACIDADE_INDICE 64

static int parse_int(const char *texto, int *valor) {
    char *fim = NULL;
    long convertido = strtol(texto, &fim, 10);
    if (texto == fim || *fim != '\0') {
        return -1;
    }
    *valor = (int)convertido;
    return 0;
}

static void imprimir_uso(const char *programa) {
    printf("Uso:\n");
    printf("  %s binaria <id>\n", programa);
    printf("  %s indexada <id>\n", programa);
    printf("  %s interpolacao <id>\n", programa);
}

int main(int argc, char **argv) {
    Local locais[CAPACIDADE_DATASET];
    size_t total = carregar_dataset_exemplo(locais, CAPACIDADE_DATASET);
    ordenar_locais_por_id(locais, total);

    if (argc != 3) {
        imprimir_uso(argv[0]);
        return 1;
    }

    int id = 0;
    if (parse_int(argv[2], &id) != 0) {
        printf("ID invalido: %s\n", argv[2]);
        return 1;
    }

    ResultadoBusca resultado;
    int status = -1;

    if (strcmp(argv[1], "binaria") == 0) {
        status = busca_binaria_por_id(locais, total, id, &resultado);
    } else if (strcmp(argv[1], "indexada") == 0) {
        EntradaIndice indice[CAPACIDADE_INDICE];
        size_t total_indice = construir_indice_primario(locais, total, 3, indice, CAPACIDADE_INDICE);
        status = busca_sequencial_indexada_por_id(locais, total, id, indice, total_indice, &resultado);
    } else if (strcmp(argv[1], "interpolacao") == 0) {
        status = busca_interpolacao_por_id(locais, total, id, &resultado);
    } else {
        imprimir_uso(argv[0]);
        return 1;
    }

    if (status == 0 && resultado.indice_unico >= 0) {
        imprimir_local(&locais[resultado.indice_unico]);
    } else {
        printf("ID %d nao encontrado.\n", id);
    }

    printf("Comparacoes: %lu\n", resultado.comparacoes);
    return status == 0 ? 0 : 1;
}
