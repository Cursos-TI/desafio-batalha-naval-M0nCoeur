#include <stdio.h>

// Jogo de Batalha Naval
// 1. O jogo deve ter um tabuleiro 10x10
// 2. O jogo deve ter 4 navios de tamanhos iguais a 3.
// 3. Os dois novos navios precisam estar na diagonal.
// 4. As coordenadas dos navios são definidas diretamente no código, sem input do usuário.
// 5. Não é necessário implementar a lógica do jogo (ataques, acertos, etc) neste nível.
// 6. A validação de sobreposição de navios pode ser simplificada.
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

    // Função para verificar se a posição está disponível
    int posicaoValida(int x, int y) {
        return (x >= 0 && x < 10 && y >= 0 && y < 10 && tabuleiro[x][y] == '0');
    }

    // Função para posicionar um navio, verificando sobreposição
    void posicionarNavio(int x, int y, int dx, int dy) {
        for (int i = 0; i < 3; i++) {
            if (!posicaoValida(x + i*dx, y + i*dy)) {
                printf("Erro: Não é possível posicionar o navio na posição (%d, %d)\n", x + i*dx, y + i*dy);
                return;
            }
            tabuleiro[x + i*dx][y + i*dy] = '3';
        }
    }

    // Navio 1 - Horizontal (na linha 3, colunas D, E, F)
    posicionarNavio(2, 3, 0, 1);

    // Navio 2 - Vertical (na coluna G, linhas 6, 7, 8)
    posicionarNavio(5, 6, 1, 0);

    // Navio 3 - Diagonal (linhas 1, 2, 3, colunas 1, 2, 3)
    posicionarNavio(0, 0, 1, 1);

    // Navio 4 - Diagonal (linhas 4, 5, 6, colunas 4, 5, 6)
    posicionarNavio(3, 3, 1, 1);

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
