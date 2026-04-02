/*
Funcao no projeto: conectar UI web com a API real em C.
Conteudo: pesquisa textual por filtros, cadastro e renderizacao em cards.
O que faz: separa resultado da busca e lista completa de locais cadastrados.
*/
const API_BASE = "http://localhost:8091";

const formPesquisa = document.getElementById("formPesquisa");
const btnLimparPesquisa = document.getElementById("btnLimparPesquisa");
const formCadastro = document.getElementById("formCadastro");

const statusPesquisa = document.getElementById("statusPesquisa");
const listaPesquisa = document.getElementById("listaPesquisa");

const statusCadastro = document.getElementById("statusCadastro");
const listaCadastrados = document.getElementById("listaCadastrados");

function setStatus(elemento, texto, erro = false) {
  elemento.textContent = texto;
  elemento.classList.toggle("error", erro);
}

function escapeHtml(valor) {
  return String(valor)
    .replaceAll("&", "&amp;")
    .replaceAll("<", "&lt;")
    .replaceAll(">", "&gt;")
    .replaceAll('"', "&quot;")
    .replaceAll("'", "&#39;");
}

function extrairNumeroSala(texto) {
  if (!texto) {
    return null;
  }

  const match = texto.match(/^\s*(?:sala\s*)?(\d+)\s*$/i);
  if (!match) {
    return null;
  }
  return match[1];
}

function montarCardLocal(local) {
  const temAr = Number(local.temAr) === 1 ? "Sim" : "Nao";
  const responsavel = local.responsavel || local.professor || "-";
  return `
    <article class="local-card">
      <header class="local-card-header">
        <h4>${escapeHtml(local.nome)}</h4>
        <span class="chip">Bloco ${escapeHtml(local.bloco)} - Andar ${escapeHtml(local.andar)}</span>
      </header>
      <p class="local-card-subtitle">${escapeHtml(local.tipo)} | Capacidade ${escapeHtml(local.capacidade)} | Ar: ${escapeHtml(temAr)}</p>
      <p class="local-card-meta">Materia: ${escapeHtml(local.materia)}</p>
      <p class="local-card-meta">Horario: ${escapeHtml(local.horario || "-")}</p>
      <p class="local-card-meta">Responsavel: ${escapeHtml(responsavel)}</p>
    </article>
  `;
}

function renderListaResultados(elementoLista, locais, vazioMsg) {
  if (!Array.isArray(locais) || locais.length === 0) {
    elementoLista.innerHTML = `<p class="resultado-vazio">${escapeHtml(vazioMsg)}</p>`;
    return;
  }

  elementoLista.innerHTML = locais.map(montarCardLocal).join("");
}

function renderErroEmCard(elementoLista, mensagem) {
  elementoLista.innerHTML = `
    <article class="local-card local-card-error">
      <h4>Nao foi possivel carregar resultados</h4>
      <p class="local-card-meta">${escapeHtml(mensagem)}</p>
    </article>
  `;
}

async function fetchJson(url, options = undefined) {
  const resposta = await fetch(url, options);
  const texto = await resposta.text();

  let dados;
  try {
    dados = JSON.parse(texto);
  } catch {
    throw new Error(`Resposta nao-JSON da API (${resposta.status})`);
  }

  if (!resposta.ok) {
    const msg = dados && dados.erro ? dados.erro : `Erro HTTP ${resposta.status}`;
    throw new Error(msg);
  }

  return dados;
}

function montarQueryPesquisa() {
  const params = new URLSearchParams();

  const idDigitado = document.getElementById("pId").value.trim();
  const nomeOriginal = document.getElementById("pNome").value.trim();
  const materia = document.getElementById("pMateria").value.trim();
  const bloco = document.getElementById("pBloco").value.trim();
  const andar = document.getElementById("pAndar").value.trim();
  const tipo = document.getElementById("pTipo").value.trim();
  const responsavel = document.getElementById("pResponsavel").value.trim();
  const horario = document.getElementById("pHorario").value.trim();
  const temAr = document.getElementById("pTemAr").value;
  const capacidade = document.getElementById("pCapacidade").value.trim();

  let idBusca = idDigitado;
  let nome = nomeOriginal;

  if (!idBusca) {
    const salaExtraida = extrairNumeroSala(nomeOriginal);
    if (salaExtraida) {
      idBusca = salaExtraida;
      nome = "";
    }
  }

  if (idBusca) params.set("id", idBusca);
  if (nome) params.set("nome", nome);
  if (materia) params.set("materia", materia);
  if (bloco) params.set("bloco", bloco);
  if (andar) params.set("andar", andar);
  if (tipo) params.set("tipo", tipo);
  if (responsavel) {
    params.set("responsavel", responsavel);
    params.set("professor", responsavel);
  }
  if (horario) params.set("horario", horario);
  if (temAr !== "") params.set("temAr", temAr);
  if (capacidade) params.set("capacidadeMin", capacidade);

  return params;
}

async function pesquisarLocais() {
  const params = montarQueryPesquisa();
  const sufixo = params.toString();

  if (!sufixo) {
    renderListaResultados(listaPesquisa, [], "Digite ao menos um filtro para pesquisar.");
    setStatus(statusPesquisa, "Digite ao menos um filtro (ou numero da sala) para pesquisar.");
    return;
  }

  const dados = await fetchJson(`${API_BASE}/api/busca?${sufixo}`);
  renderListaResultados(listaPesquisa, dados.locais || [], "Nenhum local encontrado com esses filtros.");
  setStatus(
    statusPesquisa,
    `Metodo usado: ${dados.metodoUsado || "algoritmo"} | Consulta: ${dados.consulta || "auto"} | Total=${dados.total} | Comparacoes=${dados.comparacoes ?? "-"}.`
  );
}

async function carregarLocaisCadastrados() {
  const dados = await fetchJson(`${API_BASE}/api/locais`);
  renderListaResultados(listaCadastrados, dados.locais || [], "Nenhum local cadastrado.");
  setStatus(statusCadastro, `Total de locais cadastrados: ${dados.total}.`);
}

formPesquisa.addEventListener("submit", async (event) => {
  event.preventDefault();
  setStatus(statusPesquisa, "Pesquisando locais...");

  try {
    await pesquisarLocais();
  } catch (erro) {
    setStatus(statusPesquisa, `Falha na pesquisa: ${erro.message}`, true);
    renderErroEmCard(listaPesquisa, erro.message);
  }
});

btnLimparPesquisa.addEventListener("click", () => {
  formPesquisa.reset();
  renderListaResultados(listaPesquisa, [], "Digite ao menos um filtro para pesquisar.");
  setStatus(statusPesquisa, "Filtros limpos. Preencha os campos e clique em Pesquisar.");
});

formCadastro.addEventListener("submit", async (event) => {
  event.preventDefault();

  const payload = new URLSearchParams({
    id: document.getElementById("cId").value.trim(),
    nome: document.getElementById("cNome").value.trim(),
    bloco: document.getElementById("cBloco").value.trim(),
    andar: document.getElementById("cAndar").value.trim(),
    tipo: document.getElementById("cTipo").value.trim(),
    capacidade: document.getElementById("cCapacidade").value.trim(),
    temAr: document.getElementById("cTemAr").value,
    responsavel: document.getElementById("cResponsavel").value.trim(),
    professor: document.getElementById("cResponsavel").value.trim(),
    materia: document.getElementById("cMateria").value.trim(),
    horario: document.getElementById("cHorario").value.trim(),
  });

  setStatus(statusCadastro, "Cadastrando local...");

  try {
    const dados = await fetchJson(`${API_BASE}/api/locais`, {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded;charset=UTF-8",
      },
      body: payload.toString(),
    });

    setStatus(statusCadastro, `${dados.mensagem}. ID criado: ${dados.id}.`);
    formCadastro.reset();
    await carregarLocaisCadastrados();
  } catch (erro) {
    setStatus(statusCadastro, `Falha ao cadastrar local: ${erro.message}`, true);
    renderErroEmCard(listaCadastrados, erro.message);
  }
});

(async function iniciarTela() {
  renderListaResultados(listaPesquisa, [], "Digite ao menos um filtro para pesquisar.");
  try {
    await carregarLocaisCadastrados();
  } catch (erro) {
    setStatus(
      statusCadastro,
      [
        "Nao foi possivel conectar na API.",
        "Inicie o backend com: make run-api",
        `Detalhe: ${erro.message}`,
      ].join("\n"),
      true
    );
    renderErroEmCard(listaCadastrados, erro.message);
  }
})();
