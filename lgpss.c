#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int N = 0, aux1 = 0, aux2 = 0, qtnPalavras = 8, posLinha = 0, posColuna = 0, direcao = 0;
    // Matriz das palavras que vai colocar no caca palavras, o caca palavras em si, uma string auxiliar para ser intermediária da palavra e um ponto para servir como br
    char palavras[110][110] = {}, caca_palavras[110][110] = {}, aux_palavra[110] = {};
    // Matriz com a decomposição das direções/sentidos da rosa dos ventos(primeiro linha, depois coluna)
    char dir[8][2] = {{1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}};
    // Logica veio de um problema que ACM resolveu
    // 1 = l, 2 = se, 3 = s...
    scanf("%d", &N);
    do
    {
        // loop ate chegar no ponto e vai salvando as palavras digitadas
        scanf(" %s", aux_palavra);
        if (aux_palavra[0] == '.')
        {
            aux1 = 1;
        } else {
            strcpy(palavras[aux2], aux_palavra);
            aux2++;
        }
        for (int i = 0; i < strlen(aux_palavra); i++)
        {
            aux_palavra[i] = '\0';
        }
        
    } while (aux1 != 1);
    aux2 = 0;
    
    // A partir daqui todas as palavras foram pegas
    // Loop das palavras armazenadas
    for(int i = 0; i < qtnPalavras; i++){
        // Palavra atual é palavras[i]
        // Sorteia tudo oque tem de sortear para cada palavra digitada
        posLinha = rand() % (N - strlen(palavras[i]));
        posColuna = rand() % (N - strlen(palavras[i]));
        direcao = rand() % 8;
        // Colocar na matriz de caça palavras, na linha e na coluna correspondente, palavra por palavra
        for (int z = 0; z < strlen(palavras[i]); z++)
        {
            // loop das linhas de cada palavra armazenada
            if (posLinha < N && posColuna < N)
            {
                // Limites se ta ou não ultrapassando o tamanho da matriz
                if (posLinha + (strlen(palavras[i])*dir[direcao][0]) < N && posColuna + (strlen(palavras[i])*dir[direcao][0])  < N)
                {
                    // Se a palavra for esbarra em outra ja colocada basicamente ela apaga toda a palavra que esbarrou
                    if (caca_palavras[posColuna + (z*dir[direcao][1])][posLinha + (z*dir[direcao][0])] != '\0')
                    {
                        for (int x = strlen(palavras[i]); x > 0 ; x--)
                        {
                            caca_palavras[posColuna + (x*dir[direcao][1])][posLinha + (x*dir[direcao][0])] = '\0';
                        }
                    } else if (caca_palavras[posColuna + (z*dir[direcao][1])][posLinha + (z*dir[direcao][0])] == '\0'){
                        // Se o local do caca palavras estiver vazio ele coloca aletra
                        caca_palavras[posColuna + (z*dir[direcao][1])][posLinha + (z*dir[direcao][0])] = palavras[i][z];
                    }  
                }
            }
        }
        
    }
    // Codigo para popular os espaços vazios do caca palavra com letras aleatórias
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            if (caca_palavras[i][z] == '\0')
            {
                caca_palavras[i][z] = rand() % 26 + 65;
            }
        }   
    }
    // Printar tudo
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            printf(" %c", caca_palavras[i][z]);
        }
        printf("\n");
    }
    return 0;
}