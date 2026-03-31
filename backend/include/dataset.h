/*
Arquivo: backend/include/dataset.h
Funcao no projeto: declarar operacoes relacionadas ao conjunto de dados.
Conteudo: assinaturas para carregar dataset e ordenar locais por id.
O que faz: define o contrato de entrada de dados para o backend.
*/
#ifndef DATASET_H
#define DATASET_H

#include <stddef.h>
#include "local.h"

size_t carregar_dataset_exemplo(Local *destino, size_t capacidade);
void ordenar_locais_por_id(Local *locais, size_t total);

#endif
