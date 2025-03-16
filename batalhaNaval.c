#include <stdio.h>

// Jogo de Batalha Naval
// 1. O jogo deve ter um tabuleiro 10x10
// 2. O jogo deve ter 2 navios de tamanhos iguais a 3.
// 3. As coordenadas dos navios são definidas diretamente no código, sem input do usuário.
// 4. Não é necesário implementar a lógica do jogo (ataques, acertos, etc) neste nível.
// 5. A validação de sobreposição de navios pode ser simplificada.
// Lucas Ferreira

int main() {

    // Tabuleiro 10x10
    char tabuleiro[10][10];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';  // Água
        }
    }

    // Navio 1 - Horizontal (na linha 3, colunas D, E, F)
    tabuleiro[2][3] = '3';
    tabuleiro[2][4] = '3';
    tabuleiro[2][5] = '3';

    // Navio 2 - Vertical (na coluna G, linhas 6, 7, 8)
    tabuleiro[5][6] = '3';
    tabuleiro[6][6] = '3';
    tabuleiro[7][6] = '3';

    // Imprime o cabeçalho das colunas
    printf("   A B C D E F G H I J\n");

    // Imprime o tabuleiro
    for (int i = 0; i < 10; i++) {
        if (i < 9) {
            printf("%2d ", i + 1);  // Para as linhas 1 a 9, usa 2 espaços
        } else {
            printf("%2d ", i + 1);   // Para a linha 10, usa 2 espaços também
        }
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);  // Imprime cada célula do tabuleiro
        }
        printf("\n");
    }

    return 0;
}
