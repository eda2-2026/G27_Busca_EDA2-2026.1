/*
Arquivo: backend/include/local.h
Funcao no projeto: definir os tipos de dados centrais do dominio.
Conteudo: constantes de tamanho, struct Local e struct FiltroLocal.
O que faz: padroniza o formato dos dados de local e dos filtros de consulta.
*/
#ifndef LOCAL_H
#define LOCAL_H

#define NOME_MAX 100
#define BLOCO_MAX 30
#define TIPO_MAX 40
#define PROFESSOR_MAX 100
#define DEPARTAMENTO_MAX 100
#define CODIGO_MAX 20

typedef struct {
    int id;
    char codigo[CODIGO_MAX];
    char nome[NOME_MAX];
    char bloco[BLOCO_MAX];
    int andar;
    char tipo[TIPO_MAX];
    int capacidade;
    int tem_ar;
    char professor[PROFESSOR_MAX];
    char departamento[DEPARTAMENTO_MAX];
} Local;

typedef struct {
    const char *professor;
    const char *bloco;
    const char *tipo;
    const char *departamento;
    int tem_ar;
    int capacidade_minima;
} FiltroLocal;

#endif
