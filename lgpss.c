#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
        srand(time(NULL));
        int N = 10, aux1 = 0, aux2 = 0, qtnPalavras = 9, posLinha = 0, posColuna = 0, direcao = 0, tem_palavra = 0;
        // Matriz das palavras que vai colocar no caca palavras, o caca palavras em si, uma string auxiliar para ser intermediária da palavra e um ponto para servir como br
        char palavras[110][110] = {}, caca_palavras[110][110] = {}, aux_palavra[110] = {};
        // Matriz com a decomposição das direções/sentidos da rosa dos ventos(primeiro linha, depois coluna)
        char dir[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
        // 1 = l, 2 = se, 3 = s...(posições numa rosa dos ventos)
        scanf("%d", & N);
        do {
                // loop ate chegar no ponto e vai salvando as palavras digitadas
                scanf(" %s", aux_palavra);
                if (aux_palavra[0] == '.') {
                        aux1 = 1;
                } else {
                        strcpy(palavras[aux2], aux_palavra);
                        qtnPalavras++;
                        aux2++;
                }
                for (int i = 0; i < strlen(aux_palavra); i++) {
                        aux_palavra[i] = '\0';
                }

        } while (aux1 != 1);
        aux2 = 0;
        // A partir daqui todas as palavras foram pegas
        // Loop das palavras armazenadas
        for (int i = 0; i < qtnPalavras; i++) {
                // Palavra atual é palavras[i]
                do {
                        // Ficar sorteando a posicaoe e direação até ter algo que caiba dentro do N
                        tem_palavra = 0;
                        posLinha = rand() % (N - strlen(palavras[i]));
                        posColuna = rand() % (N - strlen(palavras[i]));
                        direcao = rand() % 8;
                        for (int z = 0; z < strlen(palavras[i]) && tem_palavra == 0; z++) { // Loop para verificar se tem alguma palavra no local
                                if (caca_palavras[posColuna + (z * dir[direcao][1])][posLinha + (z * dir[direcao][0])] != '\0') { // Verifica se tem palavra em uma das posições que vai ser colocada as letras da palavra, se sim ele sorteia denovo
                                        tem_palavra = 1;
                                }
                        }
                        // Faltaria uma condição para ele não colocar menor que zero(ultrapassando o lado esquerdo e superior)
                        // Por alguma lógica que me foge tova vez que eu tento alguma lógica de um if para tentar limitar isso ele da sempre as colunas com zero

                } while (
                        (posLinha + (strlen(palavras[i]) * dir[direcao][0]) > N || posColuna + (strlen(palavras[i]) * dir[direcao][1] > N)) &&
                        tem_palavra == 1
                );

                // Colocar na matriz de caça palavras, na linha e na coluna correspondente, letra por letra
                for (int z = 0; z < strlen(palavras[i]) && tem_palavra == 0; z++) {
                        if (caca_palavras[posColuna + (z * dir[direcao][1])][posLinha + (z * dir[direcao][0])] == '\0') {
                                // Nao coloca letra onde ja tem letra so para ter ctz, mesmo ja tendo verificado antes
                                caca_palavras[posColuna + (z * dir[direcao][1])][posLinha + (z * dir[direcao][0])] = palavras[i][z];
                        }
                }
        }
        // Codigo para popular os espaços vazios do caca palavra com letras aleatórias
        for (int i = 0; i < N; i++) {
                for (int z = 0; z < N; z++) {
                        if (caca_palavras[i][z] == '\0') {
                                caca_palavras[i][z] =  rand() % 26 + 65;
                        }
                }
        }
        // Printar tudo
        for (int i = 0; i < N; i++) {
                for (int z = 0; z < N; z++) {
                        printf(" %c", caca_palavras[i][z]);
                }
                printf("\n");
        }
        return 0;
}