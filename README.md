# G27_Busca_EDA2-2026.1

## Sobre este arquivo

Funcao: apresentar a visao geral do repositorio.
Conteudo: objetivo da aplicacao, estrutura de pastas, requisitos e comandos principais.
O que faz: serve como ponto de entrada para qualquer pessoa da equipe.

Este repositorio ja esta preparado para desenvolvimento em dupla.
Ja inclui:
- API HTTP em C para consulta e cadastro de locais.
- Integracao com os 3 metodos de busca (binaria, indexada e interpolacao) no fluxo da API.
- Tela web conectada ao backend real.

## Estrutura

- `backend/include`: contratos compartilhados (structs e assinaturas)
- `backend/src`: implementacoes em C (metodos de busca + API)
- `backend/data`: banco local CSV de locais
- `frontend`: interface de pesquisa/filtros/cadastro conectada na API
- `docs`: setup e organizacao da equipe

## Requisitos

- `gcc` (C11)
- `make`

## Setup rapido

```bash
./scripts/bootstrap.sh
```

## Build manual (sem bootstrap)

```bash
make build
./bin/campus_busca binaria 203
./bin/campus_api 8091
```

## Rodar a aplicacao completa

Em dois terminais:

```bash
# Terminal 1
make run-api

# Terminal 2
cd frontend
python3 -m http.server 5500
```

Abra `http://localhost:5500`.

## API disponivel

- `GET /api/busca` com filtros: `id`, `nome`, `bloco`, `andar`, `tipo`, `responsavel`, `materia`, `horario`, `temAr`, `capacidadeMin`.
- `GET /api/locais` para listar locais cadastrados.
- `POST /api/locais` (form urlencoded) com campos obrigatorios:
  `id`, `nome`, `bloco`, `andar`, `tipo`, `capacidade`, `temAr`, `responsavel`, `materia`, `horario`.

Exemplo:

```bash
curl "http://localhost:8091/api/busca?bloco=UAC&capacidadeMin=40"
```

## Documentacao

- Guia de ambiente: [docs/SETUP.md](docs/SETUP.md)
