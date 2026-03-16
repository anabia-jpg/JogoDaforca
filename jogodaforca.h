#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_PALAVRAS 50
#define NUM_PALAVRAS 10
#define MAX_TENTATIVAS 6

//lista palavras possiveis
const char* palavras[MAX_PALAVRAS] = {
    "ABACAXI", "BANANA", "LARANJA", "MELANCIA", "MORANGO", "UVA", "PERA", "MACA", "CAJU", "ACEROLA"
};

void escolherPalavra(char *palavraSecreta){
    srand(time(NULL));
    int indice = rand() % NUM_PALAVRAS;
    strcpy(palavraSecreta, palavras[indice]);
}

// Função para inicializar o vetor de letras acertadas
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

// Função para verificar se o jogador venceu
int verificarVitoria(const char *adivinhadas) {
    return strchr(adivinhadas, '_') == NULL;
}

int main(){
    
    return 0;
}