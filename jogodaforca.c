#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_PALAVRA 50
#define MAX_TENTATIVAS 6
#define NUM_PALAVRAS 10

// Lista de palavras possíveis (pode ser expandida ou lida de um arquivo)
const char* palavras[NUM_PALAVRAS] = {
    "ABACAXI", "BANANA", "LARANJA", "MELANCIA", "MORANGO",
    "UVA", "PERA", "MACA", "CAJU", "ACEROLA"
};

// Função para escolher uma palavra aleatória
void escolherPalavra(char *palavraSecreta) {
    srand(time(NULL));
    int indice = rand() % NUM_PALAVRAS;
    strcpy(palavraSecreta, palavras[indice]);
}

// Função para inicializar o vetor de letras acertadas (todas como '_')
void inicializarAdivinhadas(const char *palavraSecreta, char *adivinhadas) {
    int tam = strlen(palavraSecreta);
    for (int i = 0; i < tam; i++) {
        adivinhadas[i] = '_';
    }
    adivinhadas[tam] = '\0';
}

// Função para desenhar a forca conforme o número de erros
void desenharForca(int erros) {
    printf("\n");
    printf("  +----+\n");
    printf("  |    |\n");
    printf("  |    %c\n", erros >= 1 ? 'O' : ' ');
    printf("  |   %c%c%c\n", erros >= 3 ? '/' : ' ', erros >= 2 ? '|' : ' ', erros >= 4 ? '\\' : ' ');
    printf("  |   %c %c\n", erros >= 5 ? '/' : ' ', erros >= 6 ? '\\' : ' ');
    printf("  |\n");
    printf("=====\n");
}

// Função para verificar se a letra está na palavra e atualizar o vetor adivinhadas
int atualizarAdivinhadas(char letra, const char *palavraSecreta, char *adivinhadas) {
    int acertou = 0;
    int tam = strlen(palavraSecreta);
    for (int i = 0; i < tam; i++) {
        if (palavraSecreta[i] == letra && adivinhadas[i] != letra) {
            adivinhadas[i] = letra;
            acertou = 1;
        }
    }
    return acertou;
}

// Função para verificar se o jogador venceu (todas as letras foram descobertas)
int verificarVitoria(const char *adivinhadas) {
    return strchr(adivinhadas, '_') == NULL;
}


int main() {
    char palavraSecreta[MAX_PALAVRA];
    char adivinhadas[MAX_PALAVRA];
    char letra;
    int erros = 0;
    char letrasUsadas[26] = {0}; // Marca letras já tentadas (A-Z)
    int letrasUsadasCount = 0;

    printf("\033[1;34m=====================================\n");
    printf("          JOGO DA FORCA\n");
    printf("=====================================\033[0m \n");

    escolherPalavra(palavraSecreta);
    inicializarAdivinhadas(palavraSecreta, adivinhadas);

    printf("A palavra tem %zu letras.\n", strlen(palavraSecreta));

    while (erros < MAX_TENTATIVAS) {
        printf("\n---------------------------\n");
        printf("Palavra: ");
        for (int i = 0; i < strlen(adivinhadas); i++) {
            printf("%c ", adivinhadas[i]);
        }
        printf("\n");
        desenharForca(erros);

        printf("Letras usadas: ");
        for (int i = 0; i < letrasUsadasCount; i++) {
            printf("%c ", letrasUsadas[i]);
        }
        printf("\n");

        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra); // Padroniza para maiúscula

        // Validação: deve ser uma letra
        if (!isalpha(letra)) {
            printf("Entrada inválida! Digite apenas letras.\n");
            continue;
        }

        // Verifica se a letra já foi usada
        int jaUsada = 0;
        for (int i = 0; i < letrasUsadasCount; i++) {
            if (letrasUsadas[i] == letra) {
                jaUsada = 1;
                break;
            }
        }
        if (jaUsada) {
            printf("Você já tentou essa letra. Tente outra.\n");
            continue;
        }

        // Registra a letra como usada
        letrasUsadas[letrasUsadasCount++] = letra;

        // Atualiza o jogo
        if (atualizarAdivinhadas(letra, palavraSecreta, adivinhadas)) {
            printf("Boa! A letra '%c' está na palavra.\n", letra);
            if (verificarVitoria(adivinhadas)) {
                system("cls");
                printf("\n\033[1;32mPARABÉNS! Você venceu! A palavra era:\033[0m %s\n", palavraSecreta);
                desenharForca(erros); // Mostra a forca final
                break;
            }
        } else {
            erros++;
            printf("Que pena! A letra '%c' não está na palavra. Erros: %d/%d\n", letra, erros, MAX_TENTATIVAS);
        }
    }

    if (erros == MAX_TENTATIVAS) {
        system("cls");
        printf("\033[1;31m \nVocê foi enforcado! A palavra era:\033[0m %s\n", palavraSecreta);
        desenharForca(erros);
    }

    printf("\nFim de jogo!\n");
    return 0;
}