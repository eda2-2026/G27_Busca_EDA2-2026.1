/*
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
#define MATERIA_MAX 100
#define HORARIO_MAX 40

typedef struct {
    int id;
    char nome[NOME_MAX];
    char bloco[BLOCO_MAX];
    int andar;
    char tipo[TIPO_MAX];
    int capacidade;
    int tem_ar;
    char responsavel[PROFESSOR_MAX];
    char materia[MATERIA_MAX];
    char horario[HORARIO_MAX];
} Local;

typedef struct {
    const char *nome;
    const char *responsavel;
    const char *bloco;
    const char *tipo;
    const char *materia;
    const char *horario;
    int tem_ar;
    int andar_igual;
    int capacidade_minima;
} FiltroLocal;

#endif
