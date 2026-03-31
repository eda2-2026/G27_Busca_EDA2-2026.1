# G27_Busca_EDA2-2026.1

## Sobre este arquivo

Funcao: apresentar a visao geral do repositorio.
Conteudo: objetivo do ambiente, estrutura de pastas, requisitos e comandos principais.
O que faz: serve como ponto de entrada para qualquer pessoa da equipe.

Este repositorio esta configurado apenas como **ambiente base** para a equipe.
Nao ha implementacao dos metodos de busca pronta.

## Estrutura

- `backend/include`: contratos compartilhados (structs e assinaturas)
- `backend/src`: arquivos em C com stubs para a equipe implementar
- `backend/tests`: teste de ambiente
- `frontend`: prototipo inicial de interface
- `docs`: setup e organizacao da equipe

## Requisitos

- `gcc` (C11)
- `make`

## Setup rapido

```bash
./scripts/bootstrap.sh
```

## Build manual

```bash
make build
make test
./bin/campus_busca
```

## Documentacao

- Guia de ambiente: [docs/SETUP.md](docs/SETUP.md)
- Divisao em dupla: [docs/DIVISAO_EQUIPE.md](docs/DIVISAO_EQUIPE.md)
