# Mapa de Campus

Número da Lista: Trabalho 1 - Busca <br>
Conteúdo da Disciplina: Algoritmos de Busca <br>

## Alunas
|Matrícula | Aluno |
| -- | -- |
| 241036142  | Júlia Gabriella Ferreira Siqueira |
| 231035722  | Marina Agostini Galdi |

## Sobre 
O **Mapa de Campus** é um serviço projetado para gerenciar e consultar o catálogo de locais de um campus universitário (salas, laboratórios, auditórios, etc.). O principal objetivo deste projeto é aplicar estruturas de dados de alto desempenho na prática, conectando um backend nativo em C a uma interface Web de pesquisas e filtros.

O sistema atua como uma central inteligente de roteamento de buscas:
* **Buscas Numéricas e Textuais secundárias (ID, Capacidade, Andar, etc.):** Utilizam a combinação de Busca Binária, Busca Sequencial Indexada e Busca por Interpolação, isolando blocos de memória para reduzir as varreduras.
* **Busca Textual Primária (Nome do local):** É interceptada por uma **Tabela de Espalhamento (Hash)**. Utilizando a matemática do Método da Divisão para o cálculo de índices e Listas Encadeadas para o tratamento de colisões (Hashing Estático Aberto), o sistema garante tempo de recuperação constante O(1) e acesso direto à memória.

## Screenshots

## Instalação 
Linguagem: C<br>


**Pré-requisitos:**
* Compilador GCC.


**Comandos necessários:**

make run-api
