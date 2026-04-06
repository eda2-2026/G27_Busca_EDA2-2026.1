# Mapa de Campus

Número da Lista: Trabalho 1 - Busca <br>
Conteúdo da Disciplina: Algoritmos de Busca <br>

## Alunas
|Matrícula | Aluno |
| -- | -- |
| 231035722  | Marina Agostini Galdi |
| 241036142  | Júlia Gabriella Ferreira Siqueira |

## Sobre 
O **Mapa de Campus** é um serviço projetado para gerenciar e consultar o catálogo de locais de um campus universitário (salas, laboratórios, auditórios, etc.). O principal objetivo deste projeto é aplicar estruturas de dados de alto desempenho na prática, conectando um backend nativo em C a uma interface Web de pesquisas e filtros.

O sistema atua como uma central inteligente de roteamento de buscas:
* **Buscas Numéricas e Textuais secundárias (ID, Capacidade, Andar, etc.):** Utilizam a combinação de Busca Binária, Busca Sequencial Indexada e Busca por Interpolação, isolando blocos de memória para reduzir as varreduras.
* **Busca Textual Primária (Nome do local):** É interceptada por uma **Tabela de Espalhamento (Hash)**. Utilizando a matemática do Método da Divisão para o cálculo de índices e Listas Encadeadas para o tratamento de colisões (Hashing Estático Aberto), o sistema garante tempo de recuperação constante O(1) e acesso direto à memória.

## Screenshots

## Instalação 
Linguagem: C (Backend) e HTML/JS/CSS (Frontend)<br>
Framework: Nenhum (Sockets nativos em C)<br>

**Pré-requisitos:**
* Compilador `gcc` (C11)
* `make`
* `python3` (necessário apenas para subir o servidor local do frontend)

## Uso 
Para rodar a aplicação completa, você precisará iniciar o backend e o frontend em **dois terminais diferentes**.

**Terminal 1 (Iniciando o Backend em C):**
```bash
make run-api
```

**Terminal 2 (Iniciando o Frontend):**
```bash
cd frontend
python3 -m http.server 5500
```

Após rodar os dois comandos, abra o seu navegador e acesse: `http://localhost:5500`.

**Documentação da API Disponível:**
* `GET /api/busca`: Busca com filtros (ex: `id`, `nome`, `bloco`, `andar`, `tipo`, `responsavel`, `materia`, `horario`, `temAr`, `capacidadeMin`). O sistema decide automaticamente qual algoritmo (Binária, Interpolada, Indexada ou Hash) utilizar com base no parâmetro fornecido.
* `GET /api/locais`: Lista todos os locais cadastrados.
* `POST /api/locais`: Cadastro de novo local (form urlencoded) com os campos obrigatórios: `id`, `nome`, `bloco`, `andar`, `tipo`, `capacidade`, `temAr`, `responsavel`, `materia`, `horario`.

*Exemplo de requisição de busca nativa via terminal (cURL):*
```bash
curl "http://localhost:8091/api/busca?bloco=UAC&capacidadeMin=40"
```

## Outros 
**Estrutura de Pastas do Projeto:**
* `backend/include`: Contratos compartilhados (structs e assinaturas).
* `backend/src`: Implementações em C (métodos de busca clássicos, Busca Hash e API).
* `backend/data`: Banco local em CSV populado com as salas.
* `frontend`: Interface de pesquisa, filtros e cadastro conectada à API.
* `docs`: Setup e organização da equipe (veja o guia completo em [docs/SETUP.md](docs/SETUP.md)).

**Destaques da Arquitetura:**
* **Modularidade:** O código-fonte foi estruturado separando a lógica matemática dos algoritmos de busca da infraestrutura de rede HTTP (endpoints).
* **Case-Insensitive Search na Hash:** A implementação da Tabela Hash conta com otimização de varredura caractere por caractere (conversão para *lowercase* em tempo de execução), permitindo encontrar locais independentemente da formatação textual da query, protegendo a integridade dos dados no banco.


## Apresentação em Vídeo
**Vídeo de Apresentação e Explicação do Código:**

[![Explicação do Código](https://img.youtube.com/vi/mDGuuiOSasI/0.jpg)](https://www.youtube.com/watch?v=mDGuuiOSasI)
