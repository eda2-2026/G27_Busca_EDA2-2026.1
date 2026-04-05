#include "busca_hash.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* funcao para transformar o nome da sala em hash.
incluindo metodo static para
Aplicando o size_t para nao incluir nº negativos

*/

//funcao de calcular o hash, formula baseada na estrutura dos slides da disciplina
static size_t calcula_hash(const char *texto, size_t tabela_tamanho) {
    if (tabela_tamanho == NULL || tabela_tamanho == 0) {
        return 0;
    }
    size_t letras_soma = 0;  //numero primo aleatorio para evitar padrões na divisão

    for (size_t i = 0; texto[i] != '\n'; i++) {

        //converter todas as letras do texto para minusculas usando o 'tolower' para obter uma estrutura padrão
        letras_soma = letras_soma + (unsigned char) tolower ((unsigned char) texto[i]);
    }

    return letras_soma % tabela_tamanho;
}

//funcao que cria a tabela hash
TabelaHash* cria_tabelaHash (size_t tamanho) {
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

//funcao de inserir hash
void inserir_hash(TabelaHash *tabela, const Local *local_campus) {
    if (tabela == NULL || local_campus == NULL) return;

    //indice que foi calculado pela funcao hash
    size_t indice_hash = calcular_hash(local_campus->nome, tabela->tamanho_total);

   //logica de colisao insere sempre no primeiro da lista: no_cbc
    ListaEnc_hash *no_cbc = (ListaEnc_hash *)malloc(sizeof(ListaEnc_hash));
    if (no_cbc == NULL) return; // verifica memoria
    
    no_cbc->dados_local = local_campus;

    //solucao para a colisao
    no_cbc->proximo = tabela->inicio[indice_hash];

    // no_cbc no indice mais recente
    tabela->inicio[indice_hash] = no_cbc;
}