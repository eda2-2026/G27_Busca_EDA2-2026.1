#ifndef DATASET_H
#define DATASET_H

#include <stddef.h>
#include "local.h"

size_t carregar_dataset_exemplo(Local *destino, size_t capacidade);
void ordenar_locais_por_id(Local *locais, size_t total);

#endif
