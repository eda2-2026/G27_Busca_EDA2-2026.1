# Divisao sugerida para 2 pessoas

## Sobre este arquivo

Funcao: organizar responsabilidades da dupla.
Conteudo: base compartilhada, modulos sugeridos por pessoa e regra de colaboracao.
O que faz: ajuda a evitar desequilibrio de carga e conflito de integracao.

## Base compartilhada (as duas revisam)

- `backend/include/local.h`
- `backend/include/buscas.h`
- `backend/src/dataset.c`
- `backend/src/main.c`
- `backend/tests/test_buscas.c`

## Pessoa 1 (varredura e filtros)

- `backend/src/busca_sequencial.c`
- Evolucao de filtros compostos no CLI (`main.c`)
- Casos de teste de filtros

## Pessoa 2 (acesso eficiente)

- `backend/src/busca_binaria.c`
- `backend/src/busca_indexada.c`
- `backend/src/busca_interpolacao.c`
- Casos de teste de comparacao entre metodos

## Regra de ouro

Nenhuma pessoa fica so em "integracao"; as duas implementam metodos de busca em C e as duas revisam o contrato comum.
