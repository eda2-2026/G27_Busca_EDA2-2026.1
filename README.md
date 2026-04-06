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

**1. Interface e Filtros (Busca Binária, Indexada e Interpolada)**
![Interface com Busca Múltipla e Interpolada](./docs/Print1_interface_busca_interpolada.PNG)

**2. Comprovação da Busca Hash com custo O(1)**
![Interface com Busca Hash direta por nome](./docs/Print2_interface_busca_hash.PNG)

**3. Estrutura do Código: Busca Binária**
![Trecho do código mostrando a lógica da Busca Binária](./docs/Print3_codigo_busca_binaria.PNG)

**4. Estrutura do Código: Busca Sequencial Indexada**
![Trecho do código mostrando a construção do índice primário](./docs/Print4_codigo_busca_indexada.PNG)

**5. Estrutura do Código: Busca por Interpolação**
![Trecho do código mostrando a Busca Interpolada por ID](./docs/Print5_codigo_busca_interpolada.PNG)

**6. Estrutura do Código: Busca Hash**
![Trecho do código mostrando a alocação dinâmica da Tabela Hash](./docs/Print6_codigo_busca_hash.PNG)

**7. Servidores em Execução (Estabilidade)**
![Terminais rodando o servidor Backend em C e o Frontend simultaneamente](./docs/Print7_Terminais.PNG)

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
