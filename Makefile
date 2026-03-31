# Arquivo: Makefile
# Funcao no projeto: centralizar comandos de build, teste e limpeza.
# Conteudo: variaveis de compilacao e alvos (build, run, test, check, clean).
# O que faz: padroniza o fluxo para toda a equipe com um conjunto unico de comandos.
CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11 -Ibackend/include -g
LDFLAGS :=

TARGET := bin/campus_busca
TEST_TARGET := bin/test_buscas

SRC_COMMON := \
	backend/src/dataset.c \
	backend/src/util.c \
	backend/src/busca_sequencial.c \
	backend/src/busca_binaria.c \
	backend/src/busca_indexada.c \
	backend/src/busca_interpolacao.c

MAIN_SRC := backend/src/main.c
TEST_SRC := backend/tests/test_buscas.c

.PHONY: all build run test check clean

all: build

build: $(TARGET)

$(TARGET): $(SRC_COMMON) $(MAIN_SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TEST_TARGET): $(SRC_COMMON) $(TEST_SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

check: build test

clean:
	rm -rf bin
