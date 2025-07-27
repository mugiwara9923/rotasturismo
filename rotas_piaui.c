
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_NOME 30

typedef struct Nodo {
    int destino;
    struct Nodo* prox;
} Nodo;

typedef struct {
    Nodo* lista[MAX_VERTICES];
    char nomes[MAX_VERTICES][MAX_NOME];
} Grafo;

// Criando o grafo vazio
Grafo* criarGrafo() {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    for (int i = 0; i < MAX_VERTICES; i++)
        g->lista[i] = NULL;
    return g;
}

// Adicionando aresta
void inserirAresta(Grafo* g, int origem, int destino) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->destino = destino;
    novo->prox = g->lista[origem];
    g->lista[origem] = novo;
}

// Mostra o grafo
void imprimirGrafo(Grafo* g) {
    printf("Mapa de conexoes entre as cidades:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        Nodo* atual = g->lista[i];
        while (atual) {
            printf("%s -> %s\n", g->nomes[i], g->nomes[atual->destino]);
            atual = atual->prox;
        }
    }
}

// Busca todos os caminhos possíveis
void buscarCaminhos(Grafo* g, int atual, int destino, int visitado[], int caminho[], int nivel,
                    int* menor, int* maior, int* total, int* menorTam, int* maiorTam) {
    visitado[atual] = 1;
    caminho[nivel] = atual;
    nivel++;

    if (atual == destino) {
        (*total)++;
        printf("Caminho %d: ", *total);
        for (int i = 0; i < nivel; i++) {
            printf("%s", g->nomes[caminho[i]]);
            if (i < nivel - 1) printf(" -> ");
        }
        printf("\n");

        if (nivel < *menorTam) {
            *menorTam = nivel;
            *menor = *total;
        }
        if (nivel > *maiorTam) {
            *maiorTam = nivel;
            *maior = *total;
        }

    } else {
        Nodo* vizinho = g->lista[atual];
        while (vizinho) {
            if (!visitado[vizinho->destino])
                buscarCaminhos(g, vizinho->destino, destino, visitado, caminho, nivel,
                               menor, maior, total, menorTam, maiorTam);
            vizinho = vizinho->prox;
        }
    }

    nivel--;
    visitado[atual] = 0;
}

// Função principal
int main() {
    Grafo* g = criarGrafo();

    char* nomes[] = {
        "Corrente", "Gilbues", "Bom Jesus", "Floriano", "Oeiras",
        "Teresina", "Campo Maior", "Piripiri", "Luis Correia", "Parnaiba"
    };
    for (int i = 0; i < MAX_VERTICES; i++)
        strcpy(g->nomes[i], nomes[i]);

    inserirAresta(g,0,1);
    inserirAresta(g,1,2);
    inserirAresta(g,2,3);
    inserirAresta(g,3,4);
    inserirAresta(g,4,5);
    inserirAresta(g,5,6);
    inserirAresta(g,6,7);
    inserirAresta(g,7,8);
    inserirAresta(g,8,9);
    inserirAresta(g,5,9); // Teresina -> Parnaiba (alternativa)
    inserirAresta(g,2,5); // Bom Jesus -> Teresina (alternativa)

    imprimirGrafo(g);

    int visitado[MAX_VERTICES] = {0};
    int caminho[MAX_VERTICES];
    int menor = -1, maior = -1, total = 0, menorTam = 99, maiorTam = 0;

    printf("\nCaminhos de Corrente ate Parnaiba:\n");
    buscarCaminhos(g, 0, 9, visitado, caminho, 0, &menor, &maior, &total, &menorTam, &maiorTam);

    printf("\n-> Caminho mais curto (%d cidades)\n", menorTam);
    printf("-> Caminho mais longo (%d cidades)\n", maiorTam);

    free(g);
    return 0;
}
