# Setup do ambiente (dupla)

## Sobre este arquivo

Funcao: guiar a configuracao local do projeto.
Conteudo: instalacao de ferramentas, validacao inicial e fluxo de trabalho recomendado.
O que faz: garante que as duas integrantes tenham o mesmo ambiente.

## 1) Ferramentas minimas

No Ubuntu/WSL:

```bash
sudo apt update
sudo apt install -y build-essential
```

No macOS (com Homebrew):

```bash
brew install gcc make
```

## 2) Clone e primeira validacao

```bash
git clone <url-do-repo>
cd G27_Busca_EDA2-2026.1
./scripts/bootstrap.sh
```

Se o script passar, o ambiente esta pronto.

## 3) Fluxo recomendado de trabalho

1. Atualizar branch principal: `git checkout main && git pull`
2. Criar branch da tarefa: `git checkout -b feat/<descricao-curta>`
3. Codar e validar: `make build`
4. Abrir PR para revisao da colega
5. Merge apos aprovacao

## 4) Padrao de validacao antes de commit

```bash
make clean
make build
```

## 5) Comandos uteis

```bash
./bin/campus_busca binaria 203
make run-api
curl "http://localhost:8091/api/locais"
make build
```

## 6) Rodar interface web conectada na API

Em dois terminais:

```bash
# Terminal 1
make run-api

# Terminal 2
cd frontend
python3 -m http.server 5500
```

Depois abra `http://localhost:5500`.

## 7) Checklist rapido para subir e compartilhar

```bash
make clean
make build
git status
git add .
git commit -m "setup pronto para integracao da dupla"
git push
```
