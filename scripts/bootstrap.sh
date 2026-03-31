#!/usr/bin/env bash
# Arquivo: scripts/bootstrap.sh
# Funcao no projeto: automatizar a validacao inicial do ambiente.
# Conteudo: checagem de gcc/make e execucao de make clean + make check.
# O que faz: confirma que a maquina esta pronta para desenvolver no projeto.
set -euo pipefail

if ! command -v gcc >/dev/null 2>&1; then
  echo "Erro: gcc nao encontrado. Instale build-essential (Ubuntu/WSL) ou gcc (macOS)."
  exit 1
fi

if ! command -v make >/dev/null 2>&1; then
  echo "Erro: make nao encontrado."
  exit 1
fi

echo "Ferramentas encontradas:"
gcc --version | head -n 1
make --version | head -n 1

echo
echo "Rodando validacao do projeto..."
make clean
make check

echo
echo "Ambiente pronto."
echo "Executavel base:"
echo "  ./bin/campus_busca"
