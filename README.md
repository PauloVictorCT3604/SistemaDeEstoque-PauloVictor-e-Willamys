# 📦 Sistema de Gerenciamento de Estoque

Este é um sistema de gerenciamento de estoque desenvolvido em C. O objetivo do sistema é permitir que os usuários gerenciem produtos em um estoque de forma simples e eficiente. Com este sistema, é possível adicionar, remover, buscar e listar produtos. 

## 🎥 Demonstração

Assista à demonstração do funcionamento do programa no YouTube:

https://youtu.be/toMHH-z09Jc

> _Clique na link acima para assistir ao vídeo._


## Funcionalidades ✨

- **🆕 Inserir Produto**: Adicione novos produtos ao estoque, especificando o nome, código, quantidade e preço.
- **🗑️ Remover Produto**: Remova produtos do estoque utilizando o código do produto.
- **🔍 Buscar Produto**: Busque um produto no estoque pelo código e visualize suas informações.
- **📋 Imprimir Lista de Produtos**: Exiba todos os produtos cadastrados no estoque, mostrando nome, código, quantidade e preço.

## Como Usar 🛠️

Para usar o sistema, siga os passos abaixo:

1. **📥 Compilar o Código**: Utilize um compilador de C (como `gcc`) para compilar o código fonte:
   
   ```bash
   
   gcc -o sistemaEstoque.c

2. **▶️ Executar o Programa:** Após a compilação, execute o programa gerado:

     ```bash

    ./sistemaEstoque

3. **📜 Interagir com o Sistema:** O programa apresentará um menu com as seguintes opções:

- 1 - Inserir produto
- 2 - Remover produto
- 3 - Buscar produto
- 4 - Imprimir lista de produtos
- 5 - Sair
  
Escolha uma opção digitando o número correspondente e siga as instruções na tela.

## Estrutura do Código 🏗️

O sistema utiliza uma lista duplamente encadeada para armazenar os produtos. Cada produto é representado pela estrutura produto, que contém os seguintes campos:

- `nome:` Nome do produto (string).
- `cod:` Código do produto (inteiro).
- `quant:` Quantidade do produto em estoque (inteiro).
- `preco:` Preço do produto (float).
- `ante:` Ponteiro para o produto anterior na lista.
- `prox:` Ponteiro para o próximo produto na lista.

**Funções do Código ⚙️**

- ``inserirProduto:`` Esta função aloca memória para um novo produto, preenche seus dados (nome, código, quantidade e preço) e insere o produto na lista. Se a lista estiver vazia, o produto se torna o primeiro elemento; caso contrário, ele é adicionado ao final da lista.

- ``removerProduto:`` Esta função busca um produto na lista pelo código. Se o produto for encontrado, ele é removido da lista e a memória alocada para ele é liberada. A função também ajusta os ponteiros para manter a integridade da lista.

- ``buscarProduto:`` Esta função percorre a lista de produtos em busca de um produto específico pelo código. Se encontrado, ela retorna um ponteiro para o produto; caso contrário, retorna `NULL`.

- ``imprimirListaProdutos:`` Esta função percorre a lista e imprime as informações de todos os produtos cadastrados, incluindo nome, código, quantidade e preço. Se a lista estiver vazia, uma mensagem apropriada é exibida.

## Objetivo 🎯
O objetivo deste sistema é facilitar o gerenciamento de um estoque de produtos, proporcionando uma interface simples para usuários que desejam acompanhar e organizar seu inventário. É uma solução prática para pequenos negócios que precisam controlar seu estoque de forma eficiente.

## Informações de Contato 📇

- **Nome:** Paulo Victor Bezerra Brito
- **Nome:** Willamys Carneiro
