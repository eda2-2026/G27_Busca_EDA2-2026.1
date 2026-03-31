/*
Arquivo: frontend/script.js
Funcao no projeto: controlar a interacao da pagina de prototipo.
Conteudo: captura do submit do formulario e mensagem de saida em modo mock.
O que faz: demonstra o fluxo de consulta ate a integracao real com backend.
*/
const form = document.getElementById("formBusca");
const saida = document.getElementById("saida");

form.addEventListener("submit", (event) => {
  event.preventDefault();

  const tipoBusca = document.getElementById("tipoBusca").value;
  const entrada = document.getElementById("entrada").value.trim();

  saida.textContent = [
    "Frontend em modo mock.",
    "Backend em modo esqueleto (sem metodos implementados).",
    "Comando atual:",
    "./bin/campus_busca",
    "",
    "Proximo passo: integrar frontend -> API/adapter em C."
  ].join("\n");
});
