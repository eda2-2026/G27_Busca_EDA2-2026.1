#include "busca_hash.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* funcao para transformar o nome da sala em hash.
incluindo metodo static para
Aplicando o size_t para nao incluir nº negativos

*/

//funcao de CALCULAR o hash, formula baseada na estrutura dos slides da disciplina
static size_t calcular_hash(const char *texto, size_t tabela_tamanho) {
    if (texto == NULL || tabela_tamanho == 0) {
        return 0;
    }
    size_t letras_soma = 0;  //numero primo aleatorio para evitar padrões na divisão

    for (size_t i = 0; texto[i] != '\0'; i++) {

        //converter todas as letras do texto para minusculas usando o 'tolower' para obter uma estrutura padrão
        letras_soma = letras_soma + (unsigned char) tolower ((unsigned char) texto[i]);
    }

    return letras_soma % tabela_tamanho;
}

//funcao que CRIAR a tabela hash
TabelaHash* criar_tabela_hash(size_t tamanho) {
    if (tamanho == 0) {
        return NULL;
    }
    TabelaHash *tabela = (TabelaHash *) malloc (sizeof(TabelaHash));
    
    if (tabela == NULL) {
        return NULL;
    }

    tabela->inicio = (ListaEnc_hash **) calloc (tamanho, sizeof(ListaEnc_hash *));
    if(tabela->inicio == NULL){
        free (tabela);
        return NULL;
    }

    tabela->tamanho_total = tamanho;
    return tabela;
}

//funcao de INSERIR hash
void inserir_hash(TabelaHash *tabela, const Local *local_campus) {
    if (tabela == NULL || local_campus == NULL) return;

    //indice que foi calculado pela funcao hash
    size_t indice_hash = calcular_hash(local_campus->nome, tabela->tamanho_total);

   //logica de colisao insere sempre no primeiro da lista: novo_local
    ListaEnc_hash *novo_local = (ListaEnc_hash *)malloc(sizeof(ListaEnc_hash));
    if (novo_local == NULL) return; // verifica memoria
    
    novo_local->dados_local = local_campus;

    //solucao para a colisao
    novo_local->proximo = tabela->inicio[indice_hash];

    // no_cbc no indice mais recente
    tabela->inicio[indice_hash] = novo_local;
}


// COMPARA TEXTO QUE FOI INSERIDO PELO USUARIO COM O QUE ESTA SALVO NO BANCO
static int cadastro_vs_busca(const char *local_cadastrado, const char *local_buscado) {
    int i = 0;

    while (local_cadastrado[i] != '\0' && local_buscado[i] != '\0') {
        
        // Transformar em minusculo e comparar
        unsigned char letra_cadastro = (unsigned char)tolower((unsigned char)local_cadastrado[i]);
        unsigned char letra_busca = (unsigned char)tolower((unsigned char)local_buscado[i]);
        
        if (letra_cadastro != letra_busca) {
            return 0; //palavras diferentes
        }

        i++; 
    }

    if (local_cadastrado[i] == '\0' && local_buscado[i] == '\0') {
        return 1; //confirma que são iguais
    }

    //se não entrou nos if provavel que palavra era maior que a outra
    return 0; 
}


//funcao de BUSCAR local pelo nome
const Local* buscar_hash(TabelaHash *tabela, const char *nome_buscado) {
    if (tabela == NULL || nome_buscado == NULL) return NULL;

    // 1. Vai direto na gaveta certa usando a mesma matemática
    size_t indice_hash = calcular_hash(nome_buscado, tabela->tamanho_total);

    // 2. Olha para a primeira etiqueta que está nessa gaveta
    ListaEnc_hash *local_em_verificacao = tabela->inicio[indice_hash];

    //percorre lista encd ate achar nome/fim
    while (local_em_verificacao != NULL) {
        if (cadastro_vs_busca(local_em_verificacao->dados_local->nome, nome_buscado) == 1) {
            return local_em_verificacao->dados_local; 
        }

        local_em_verificacao = local_em_verificacao->proximo;
    }

    // Se o while nao achou nada, devolve NULL
    return NULL; 
}