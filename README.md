
# Projeto: Rotas entre Cidades do Piaui (Grafos em C)

Este projeto modela um mapa rodoviário entre cidades do estado do Piauí utilizando a estrutura de **grafos direcionados** com **lista de adjacência**. Ele percorre todos os caminhos possíveis entre **Corrente** e **Parnaíba**, identificando o **caminho mais curto**, o **mais longo** e exibindo todos eles.

## 👨‍💻 Estrutura do Grafo

- Cada cidade é representada como um **vértice** (0 a 9)
- Cada estrada entre cidades é uma **aresta direcionada**
- Foi utilizado **lista de adjacência**, com alocação dinâmica via ponteiros

## 🗺️ Cidades e seus índices

| Índice | Cidade        |
|--------|----------------|
| 0      | Corrente       |
| 1      | Gilbues        |
| 2      | Bom Jesus      |
| 3      | Floriano       |
| 4      | Oeiras         |
| 5      | Teresina       |
| 6      | Campo Maior    |
| 7      | Piripiri       |
| 8      | Luis Correia   |
| 9      | Parnaiba       |

## 🔗 Conexões (arestas)

```
Corrente -> Gilbues
Gilbues -> Bom Jesus
Bom Jesus -> Floriano
Floriano -> Oeiras
Oeiras -> Teresina
Teresina -> Campo Maior
Campo Maior -> Piripiri
Piripiri -> Luis Correia
Luis Correia -> Parnaiba
Teresina -> Parnaiba (rota alternativa)
Bom Jesus -> Teresina (rota alternativa)
```

## ⚙️ Funcionalidades

- Construção do grafo
- Impressão das conexões
- Busca de **todos os caminhos** entre Corrente e Parnaiba
- Identificação do:
  - Caminho mais curto
  - Caminho mais longo

## 🧠 Lógica da função de busca

A função `buscarCaminhos` utiliza **recursão e backtracking**:

1. Marca o vértice atual como visitado
2. Se chegou no destino, imprime o caminho e compara tamanhos
3. Senão, chama recursivamente para os vizinhos
4. Ao voltar, **desmarca o vértice atual** para permitir novos caminhos

