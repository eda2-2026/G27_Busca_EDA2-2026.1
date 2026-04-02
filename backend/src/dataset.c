/*
Funcao no projeto: implementar carga e ordenacao do dataset.
Conteudo: dataset inicial de exemplo e ordenacao por id.
O que faz: fornece dados basicos para exercitar os metodos de busca.
*/
#include "dataset.h"

#include <stdlib.h>

static const Local DATASET_EXEMPLO[] = {
    {303, "Sala 303", "C", 3, "Sala", 50, 1, "Fabio Neves", "Calculo III", "14:00-16:00"},
    {101, "Sala 101", "A", 1, "Sala", 40, 1, "Ana Silva", "EDA II", "08:00-10:00"},
    {402, "Lab Robotica", "D", 4, "Laboratorio", 28, 1, "Igor Ramos", "Robotica", "16:00-18:00"},
    {203, "Lab Eletrica", "B", 2, "Laboratorio", 25, 1, "Daniel Rocha", "Circuitos", "10:00-12:00"},
    {120, "Sala 120", "A", 1, "Sala", 35, 0, "Ana Silva", "Programacao I", "10:00-12:00"},
    {250, "Auditorio C", "C", 2, "Auditorio", 120, 1, "Elisa Prado", "Seminario", "19:00-21:00"},
    {150, "Biblioteca Setor B", "B", 1, "Biblioteca", 80, 1, "Gabriela Melo", "Pesquisa", "09:00-18:00"}
};

static int comparar_local_por_id(const void *a, const void *b) {
    const Local *local_a = (const Local *)a;
    const Local *local_b = (const Local *)b;

    if (local_a->id < local_b->id) {
        return -1;
    }
    if (local_a->id > local_b->id) {
        return 1;
    }
    return 0;
}

size_t carregar_dataset_exemplo(Local *destino, size_t capacidade) {
    if (destino == NULL || capacidade == 0) {
        return 0;
    }

    size_t total = sizeof(DATASET_EXEMPLO) / sizeof(DATASET_EXEMPLO[0]);
    size_t limite = total < capacidade ? total : capacidade;

    for (size_t i = 0; i < limite; i++) {
        destino[i] = DATASET_EXEMPLO[i];
    }

    return limite;
}

void ordenar_locais_por_id(Local *locais, size_t total) {
    if (locais == NULL || total == 0) {
        return;
    }
    qsort(locais, total, sizeof(Local), comparar_local_por_id);
}
