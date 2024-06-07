# Trabalho Prático 05 - Árvore Binária

## Descrição

Este projeto implementa um TAD (Tipo Abstrato de Dados) de Árvore Binária em C. O programa permite criar e manipular árvores binárias através de uma série de comandos, conforme especificado no trabalho prático da disciplina de Estrutura de Dados.

## Funcionalidades

O programa suporta as seguintes operações:

- `create <tree>`: Cria uma árvore a partir de uma representação textual em parênteses. Por exemplo, `create (A,(B,(),()),(C,(F,(),()),()))` cria uma árvore com raiz `A`, filhos `B` e `C`, e neto `F` sob `C`.
- `pre`: Imprime a ordem de visitação dos nós da árvore em pré-ordem.
- `in`: Imprime a ordem de visitação dos nós da árvore em ordem.
- `post`: Imprime a ordem de visitação dos nós da árvore em pós-ordem.
- `height <n>`: Imprime a altura do nó `n`.
- `print`: Imprime a estrutura hierárquica da árvore em modo texto.
- `exit`: Sai do programa.

## Exemplo de Uso

### Comandos

1. Criar uma árvore:
    ```
    create (A,(B,(),()),(C,(F,(),()),()))
    ```
    Estrutura criada:
    ```
       C
     F

    A
    B
    ```

2. Imprimir em pré-ordem:
    ```
    pre
    ```
    Saída:
    ```
    A B C F
    ```

3. Imprimir em ordem:
    ```
    in
    ```
    Saída:
    ```
    B A F C
    ```

4. Imprimir em pós-ordem:
    ```
    post
    ```
    Saída:
    ```
    B F C A
    ```

5. Imprimir altura do nó `C`:
    ```
    height C
    ```
    Saída:
    ```
    2
    ```

6. Sair do programa:
    ```
    exit
    ```

## Estrutura do Projeto

- `main.c`: Contém a função principal e o loop de interação com o usuário.
- `binary_tree.h`: Contém as declarações das funções e do tipo de dado `t_binary_tree`.
- `binary_tree.c`: Contém as implementações das funções do TAD Árvore Binária.

## Compilação e Execução

Para compilar o programa, use o `makefile` incluído no projeto. Certifique-se de ter o `make` instalado em seu sistema.

### Compilação

No terminal, navegue até o diretório do projeto e execute:
```sh
make
