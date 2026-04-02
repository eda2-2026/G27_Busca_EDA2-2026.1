/*
Funcao no projeto: implementar busca por interpolacao para ids numericos.
Conteudo: implementacao da funcao busca_interpolacao_por_id.
O que faz: estima a posicao de busca em vetor ordenado com ids numericos.
*/
#include "buscas.h"

int busca_interpolacao_por_id(
    const Local *locais,
    size_t total,
    int id,
    ResultadoBusca *resultado
) {
    if (locais == NULL || resultado == NULL || total == 0) {
        return -1;
    }

    resultado_inicializar(resultado);

    size_t baixo = 0;
    size_t alto = total - 1;

    while (baixo <= alto && id >= locais[baixo].id && id <= locais[alto].id) {
        if (locais[baixo].id == locais[alto].id) {
            resultado->comparacoes++;
            if (locais[baixo].id == id) {
                resultado->indice_unico = (int)baixo;
                if (resultado_adicionar(resultado, baixo) != 0) {
                    return -1;
                }
                return 0;
            }
            break;
        }

        size_t posicao = baixo + (size_t)(
            ((double)(id - locais[baixo].id) * (double)(alto - baixo)) /
            (double)(locais[alto].id - locais[baixo].id)
        );

        if (posicao < baixo || posicao > alto) {
            break;
        }

        resultado->comparacoes++;

        if (locais[posicao].id == id) {
            resultado->indice_unico = (int)posicao;
            if (resultado_adicionar(resultado, posicao) != 0) {
                return -1;
            }
            return 0;
        }

        if (locais[posicao].id < id) {
            baixo = posicao + 1;
        } else {
            if (posicao == 0) {
                break;
            }
            alto = posicao - 1;
        }
    }

    return -1;
}
