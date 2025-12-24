# 🕯️ Don’t Let Them In
<p align="center">
  <img src="https://media3.giphy.com/media/v1.Y2lkPTc5MGI3NjExZnV4c2RpOXkyYWE5bmIyN2M1b29rdWZjczl4aGxzbGtvbWd6OHhoeiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/Br9iG1RearpBctyK7F/giphy.gif" alt="Don't Let Them In" width="600">
</p>

## 🧠 Sobre o Projeto

**Don’t Let Them In** é um **jogo narrativo desenvolvido em C**, onde irá desafiar o jogador a tomar **decisões**, provocar **suspeitas** e buscar a **sobrevivência** durante um apocalipse misterioso.

Você está trancado em um bunker enquanto pessoas batem à sua porta pedindo abrigo.  
O problema? **Nem todos são humanos.**

Seu papel é **observar, analisar e decidir** quem entra, sabendo que **uma escolha errada pode significar o fim**.

O jogo combina:
- narrativa progressiva,
- múltiplos finais,
- estrutura de dados (fila),
- interação direta com o jogador via terminal.

---

## 🎮 Como Funciona

- Cada personagem chega com:
  - descrição,
  - falas,
  - informações adicionais,
  - características suspeitas (dentes, pele, olhos, temperatura e cheiro).
- O jogador pode:
  - analisar características,
  - pedir mais informações,
  - mandar embora,
  - ou deixar entrar.
- Se um **não-humano entrar**, o jogo acaba imediatamente.
- O número de humanos salvos (ou não) define o **final da história**.

---

## 🧩 Estruturas de Dados Utilizadas

### 📌 Fila Encadeada (FIFO)

Os suspeitos são organizados em uma **fila**, representando a ordem em que chegam à porta.

- Cada nó representa um **Suspeito**
- O primeiro da fila é sempre o próximo a ser analisado
- Após a decisão, ele é removido da fila

### 📌 Vetor Dinâmico

Os nomes das pessoas que entram no bunker são armazenados em um **vetor dinâmico**, que cresce conforme o jogo avança.

---

## 🧱 Estrutura Principal do Código

### 🔹 `struct Suspeito`

Armazena todas as informações de cada personagem:
- se é humano ou não
- nome e descrição
- falas e respostas
- características suspeitas
- ponteiro para o próximo da fila

### 🔹 `struct Fila`

Controla a fila de suspeitos:
- início
- fim
- quantidade de elementos

---

## 🏁 Finais Possíveis

O jogo possui **múltiplos finais**, definidos pelas decisões do jogador:

- **Morte** – um não-humano entrou no bunker
- **Salvador** – todos os humanos foram salvos
- **Egoísta** – ninguém entrou
- **Desconfiança** – poucos humanos salvos
- **Humano** – alguns sobreviveram, outros não

Cada final possui sua própria mensagem narrativa.

---

## 👥 Integrantes do Trabalho

- **[Arian Queiroz Dantas](https://github.com/arianqueiroz)**
- **[Francisco Gabriel Carvalho](https://github.com/Fratis35)**
- **[Giovana Joice Costa Moreira](https://github.com/GiovanaJoice)**
