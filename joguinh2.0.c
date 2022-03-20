#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //mensagens iniciais do jogo
    printf("**************************************************\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhacao!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("* adivinhe o numero de 0 a 99                    *\n");
    printf("**************************************************\n\n");

    //gerador de numero aleatorio
    int segundos = time(0);
    srand(segundos);

    int rng = rand(),
        numerosecreto = rng % 100,
        chute,
        acertou;

    float pontos = 1000;

    int tentativas,
        nivel;

    printf("selecione o nivel de dificuldade\n");
    printf("(1)facil (2)medio (3)dificil: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            tentativas = 15;
            break;
        case 2:
            tentativas = 10;
            break;
        default:
            tentativas = 5;
            break;
    }
    
    printf("voce tem %d tentativas", tentativas);

    //loop de tentativas infinitas
    for(int i = 1; i <= tentativas; i++){
        printf("\n\n************************************\n\n");
        printf("qual o seu chute? ");
        scanf("%d", &chute);
        printf("seu chute foi %d\n", chute);
        printf("tentativa %d de %d\n",i , tentativas);

//autenticacao de entrada de dados do usuario
        int numnegativo = chute < 0;

        if(numnegativo) {
            printf("voce nao pode chutar numeros negativos >:(\n\n");
            continue;
        }

        //tomada de decisao com a entrada de dado do usuario
        int maior = chute > numerosecreto;
        acertou = chute == numerosecreto;

        if(acertou) {
            break;
        }

        else if(maior) {
            printf("voce errou, o numero secreto e menor do que seu chute\n");
        }

        else{
            printf("voce errou, o numero secreto e maior do que seu chute\n");
        }

        //calculo da pontuacao
        float pontosperdidos = abs(chute - numerosecreto) / (float)2;
        pontos = pontos - pontosperdidos;
    }

    //mensagem final
    if(acertou) {
        printf("parabens voce acertou!\n\n");
        printf("voce ganhou %.1f pontos\n", pontos);
    } else {
        printf("voce perdeu, mas continue tentando :D\n\n");
    }
    system("PAUSE");
}