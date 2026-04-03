#include "busca_hash.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* funcao para transformar o nome da sala em hash.
incluindo metodo static para
Aplicando o size_t para nao incluir nº negativos

*/

static size_t calcula_hash(const char *texto, size_t tabela_tamanho) {
    if (tabela_tamanho == NULL || tabela_tamanho == 0) {
        return 0;
    }
    unsigned long hash = 47;  //numero primo aleatorio para evitar padrões na divisão
}