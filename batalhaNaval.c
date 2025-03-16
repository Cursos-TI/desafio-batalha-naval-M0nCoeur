#include <stdio.h>

// Jogo de Batalha Naval
// 1. O jogo possui formas representadas pelas habilidades especiais:
//    - Cruz: Representada pela matriz com valor 1.
//    - Cone: Representada pela matriz com valor 4.
//    - Octaedro: Representada pela matriz com valor 5.
// 2. O jogo possui 4 navios de tamanho 3.
// 3. Os dois novos navios precisam estar na diagonal.
// Lucas Ferreira

// Função para sobrepor as áreas de efeito no tabuleiro
void sobreporHabilidade(int habilidade[5][5], int origemX, int origemY, char valor, char tabuleiro[10][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX - 2 + i;
            int y = origemY - 2 + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && habilidade[i][j] == 3) {
                tabuleiro[x][y] = valor;
            }
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int origemX, int origemY, int direcaoX, int direcaoY, char tabuleiro[10][10]) {
    for (int i = 0; i < 3; i++) {
        int x = origemX + i * direcaoX;
        int y = origemY + i * direcaoY;
        tabuleiro[x][y] = '3';  // Marca a posição do navio no tabuleiro
    }
}    

int main() {
    // Tabuleiro 10x10
    char tabuleiro[10][10];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';  // Água
        }
    }

    // Definição das áreas de habilidade (Cruza, Cone, Octaedro)
    // Cruz (valor 3)
    int cruz[5][5] = {
        {0, 0, 3, 0, 0},
        {3, 3, 3, 3, 3},
        {0, 0, 3, 0, 0}
    };
    // Cone (valor 3)
    int cone[5][5] = {
        {0, 0, 3, 0, 0},
        {0, 3, 3, 3, 0},
        {3, 3, 3, 3, 3}
    };
    // Octaedro (valor 3)
    int octaedro[5][5] = {
        {0, 0, 3, 0, 0},
        {0, 3, 3, 3, 0},
        {0, 0, 3, 0, 0}
    };

    // Posicionamento das áreas de habilidades (com base no centro do tabuleiro)
    // Cruz na posição (5,5)
    sobreporHabilidade(cruz, 5, 5, '1', tabuleiro);
    // Cone na posição (7,7)
    sobreporHabilidade(cone, 7, 7, '4', tabuleiro);
    // Octaedro na posição (3,3)
    sobreporHabilidade(octaedro, 3, 3, '5', tabuleiro);

    // Posicionamento dos navios
    // Navio 1: Posição (0,0) na diagonal
    posicionarNavio(0, 0, 1, 1, tabuleiro);
    // Navio 2: Posição (9,0) na diagonal
    posicionarNavio(9, 0, -1, 1, tabuleiro);
    // Navio 3: Posição (0,9) na diagonal
    posicionarNavio(0, 9, 1, -1, tabuleiro);
    // Navio 4: Posição (9,9) na diagonal
    posicionarNavio(9, 9, -1, -1, tabuleiro);

    // Imprime o cabeçalho das colunas
    printf("   A B C D E F G H I J\n");

    // Imprime o tabuleiro
    for (int i = 0; i < 10; i++) {
        // Imprime o número da linha (alinhado)
        printf("%2d ", i + 1);

        // Imprime cada célula do tabuleiro
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);  // Imprime cada célula do tabuleiro
        }
        printf("\n");
    }

    return 0;
}
