
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

A função buscarCaminhos é responsável por encontrar todos os caminhos possíveis entre duas cidades no grafo. Ela usa recursão junto com uma técnica chamada backtracking, que basicamente permite "explorar e voltar atrás" para testar outros caminhos possíveis. A ideia é a seguinte: a cada chamada da função, ela visita uma cidade, marca essa cidade como visitada, e adiciona ao caminho atual. Em seguida, ela verifica se essa cidade é o destino final. Se for, imprime o caminho encontrado e já aproveita pra verificar se ele é o menor ou o maior até agora, comparando os tamanhos. Se a cidade atual ainda não for o destino, a função continua tentando seguir por todas as cidades vizinhas conectadas a ela, chamando a si mesma de forma recursiva para cada possibilidade. Esse processo vai acontecendo até que o caminho leve até Parnaiba. Quando termina de testar um caminho, a função precisa voltar atrás, por isso ela desmarca a cidade atual como visitada e remove ela do caminho atual. Isso é importante porque permite tentar outros caminhos que passem por ela mais tarde, sem confundir com os anteriores. Esse mecanismo de marcar, testar, e depois desmarcar é o que caracteriza o backtracking, e garante que todos os caminhos possíveis serão testados, um por um.
