
# 🧙‍♂️ Compilador Faquir

**Compilador Faquir** é um projeto desenvolvido na disciplina de Compiladores da **Universidade Federal Rural do Rio de Janeiro (UFRRJ)**, no segundo semestre de 2024. O projeto tem como objetivo a construção de um compilador simples baseado em C, capaz de reconhecer, analisar e traduzir uma linguagem com sintaxe própria para código C compilável.  

Este compilador foi desenvolvido por **Pedro Júlio Silva Sucupira** e **Rodrigo de Souza**, sob orientação do professor **Filipe Braida**.

---

## 📘 Sobre o Projeto

O **Compilador Faquir** foi desenvolvido como parte do trabalho final da disciplina de Compiladores da UFRRJ, abrangendo as funcionalidades propostas nas Etapas I, II, III e funcionalidades Extras. A linguagem criada é de tipagem explícita (com inferência em casos extras), de escopo global, baseada em C, e com geração de código em C puro compatível com o `gcc`.

A seguir, o que a linguagem implementada suporta:

### ✅ Etapa I — Expressões e Tipagem
- Tipos primitivos: `int`, `float`, `char`, `bool`
- Operações aritméticas: `+`, `-`, `*`, `/`
- Operadores relacionais: `<`, `<=`, `>`, `>=`, `==`, `!=`
- Operadores lógicos: `&&`, `||`, `!`
- Declaração e uso de variáveis
- Atribuição de valores
- Conversão **implícita** e **explícita** entre tipos
- Geração de código intermediário com temporários e rótulos

### ✅ Etapa II — Controle e Entrada/Saída
- Delimitação de blocos com `{ ... }`
- Controle de escopo (escopo global implementado)
- Comandos condicionais: `if`, `if/else`, `switch`
- Laços de repetição: `while`, `do/while`, `for`
- Comandos de laço: `break`, `continue`
- Entrada e saída: comandos como `print(...)` (gerando `printf`)
- Manipulação de strings
- Detecção de erros simples durante a análise

### ✅ Etapa III — Consolidação e Complementos
- Integração completa das Etapas I e II
- Inicialização de variáveis
- Operadores compostos (como `+=`, `-=`, etc.)
- Operadores unários (`-x`, `+x`)
- Detecao de Erros


### 🌟 Funcionalidades Extras Implementadas
- Comentários (`// comentário`, `/* comentário */`)
- Inferência de tipo em certas expressões
- Operadores especiais: `pow`, `sqrt`, `min`, `max`, `log`
- Constantes (`const`)
- Concatenação de strings
- Enumerações (`enum`)
- Comando especial `break all` (encerra laços aninhados)

---

## ⚙️ Tecnologias e Ferramentas Utilizadas

- **Flex (Lex)** – para análise léxica (`analisador.l`)
- **Bison (Yacc)** – para análise sintática e geração de código (`analisador.y`)
- **C++** – utilizado nos analisadores com integração de estruturas como `std::string`
- **Shell Script** – automação da execução (`run_faq.sh`)
- **GCC** – compilador C usado para gerar o executável final a partir do código traduzido
- **Makefile** – automatiza a compilação do compilador

---

## 📁 Estrutura dos Arquivos

| Arquivo            | Descrição |
|--------------------|-----------|
| `analisador.l`     | Analisador léxico (tokenização) |
| `analisador.y`     | Analisador sintático com geração de código em C |
| `tipos.h`          | Definição da estrutura `atributos` e do `YYSTYPE` |
| `entrada.faq`      | Exemplo de código-fonte na linguagem Faquir |
| `run_faq.sh`       | Script que compila e executa o código da linguagem |
| `Makefile`         | Facilita a construção do compilador (`faquir`) |

---

## 🛠️ Como Instalar as Dependências

Antes de executar o projeto, é necessário instalar as seguintes ferramentas:

### No Ubuntu/Debian:

```bash
sudo apt update
sudo apt install flex bison gcc g++ make
```

### No Arch Linux / Manjaro:

```bash
sudo pacman -S flex bison gcc make
```

### No MacOS (com Homebrew):

```bash
brew install flex bison gcc make
```

---

## 🚀 Como Executar

1. Clone o repositório ou copie os arquivos para uma pasta local.
2. Compile o compilador com:

```bash
make
```

3. Execute o script de teste:

```bash
./run_faq.sh
```

Esse comando irá:
- Rodar o compilador (`./faquir`) com o código de `entrada.faq`
- Gerar o código traduzido em `saida.c`
- Compilar `saida.c` com `gcc`
- Executar o binário final (`./programa`)

---

## 🤝 Como Contribuir

1. Faça um fork do projeto
2. Crie uma nova branch:

```bash
git checkout -b minha-nova-feature
```

3. Faça suas alterações
4. Realize o commit:

```bash
git commit -m "Adiciona nova feature"
```

5. Envie para o repositório remoto:

```bash
git push origin minha-nova-feature
```

6. Abra um Pull Request e descreva sua contribuição

---

## 📚 Créditos

Este projeto foi desenvolvido como trabalho final da disciplina de Compiladores da **UFRRJ** – Universidade Federal Rural do Rio de Janeiro.

- 👨‍💻 Desenvolvido por: **Pedro Júlio Silva Sucupira** e **Rodrigo de Souza**
- 🎓 Orientador: **Prof. Filipe Braida**

