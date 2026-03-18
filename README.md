# JogoDaforca em C

## 📖 Descrição

Este é um jogo da forca desenvolvido em linguagem C, executado no terminal. O computador escolhe aleatoriamente uma palavra de uma lista predefinida e o jogador tenta adivinhar as letras que a compõem. A cada erro, partes do boneco são desenhadas. O jogo termina quando o jogador acerta toda a palavra (vitória) ou quando o boneco é completado (derrota).

## ✨ Funcionalidades

-  Seleção aleatória de palavra a cada partida.
-  Exibição do progresso da palavra (letras acertadas e underscores).
-  Desenho da forca atualizado conforme os erros.
-  Controle de letras já tentadas para evitar repetição.
-  Validação de entrada (apenas letras, conversão para maiúsculas).
-  Mensagens de feedback e condições de vitória/derrota.

## 🛠️ Tecnologias utilizadas

- *Linguagem:* C (padrão C99)
- *Bibliotecas:* stdio.h, stdlib.h, string.h, ctype.h, time.h
- *Compilador:* GCC (ou qualquer compilador C padrão)

### Pré-requisitos

- Ter um compilador C instalado (ex: GCC no Linux/Mac, MinGW no Windows).