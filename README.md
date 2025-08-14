# Compilador uChuck

Este é um repositório para um compilador simples da linguagem "uChuck". O compilador processa código-fonte escrito em uChuck e o traduz para a linguagem C.

O projeto é dividido em várias fases, cada uma contida em seu próprio módulo Python.

## Arquitetura do Compilador

O processo de compilação segue as etapas clássicas:

### 1\. Análise Léxica (Lexer)

  * Responsável por ler o código-fonte uChuck e dividi-lo em uma sequência de **tokens**. Ele reconhece palavras-chave (`if`, `while`), tipos (`int`, `float`), operadores (`+`, `=>`), literais e identificadores.

### 2\. Análise Sintática (Parser) e AST

  * O **parser** recebe os tokens do lexer e verifica se eles formam uma estrutura gramatical válida. Conforme analisa a gramática, ele constrói uma **Árvore de Sintaxe Abstrata (AST)**, que é uma representação hierárquica do código.

### 3\. Análise Semântica (Semantic)

  * Esta fase percorre a AST para verificar a correção semântica do programa. Suas principais responsabilidades são:
      * **Checagem de Tipos:** Garante que operações sejam feitas com tipos compatíveis (ex: não somar uma string com um float).
      * **Tabela de Símbolos:** Verifica se as variáveis foram declaradas antes do uso e gerencia os escopos.
      * **Anotação da AST:** Adiciona informações de tipo aos nós da árvore, que serão usadas na próxima fase.

### 4\. Geração de Código (CodeGeneration)

  * A fase final. O gerador de código percorre a AST, que já foi validada e anotada pela análise semântica, e traduz cada nó em código C equivalente. O resultado é um programa em C funcional que é salvo em um arquivo de saída.
