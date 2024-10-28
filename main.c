#include <stdio.h>
#include <stdlib.h>
#include "programaclaudino.h"
#include <math.h>
#include <time.h>

const float g = 10;
// quantidade de movimento m1 * v1 = m2 * v2;

typedef struct carro{
    float velocidade;
    float massa;
}carro;

int main(){
    carro movimento;
    carro parado;
    float altura;

    printf("Digite a velocidade(m/s) de colisão, a massa do carro em movimento e a altura de partida respectivamente:\n");
    scanf("%f %f %f", &movimento.velocidade , &movimento.massa , &altura);

   // a massa do carro em repouso é 25% maior que o carro em movimento
    parado.massa = movimento.massa * 1.25;

    // (fórmula quantidade de movimento)descobrir a velocidade com que o carro em repouso saia
    parado.velocidade = (movimento.massa * movimento.velocidade) / parado.massa;
    printf("Velocidade com que o carro vai sair para o trajeto é %0.2f \n", parado.velocidade);

    float cineticon = cinetica(parado.massa , parado.velocidade);
    float potention = potencial(parado.massa , altura , g);
    float energia = potention + cineticon;

    // sabemos com que energia o carro em repouso ira sair
    printf("A energia potencial é: %0.2f e a energia cinetica é: %0.2f e suas somas é: %0.2f \n", potencial , cinetica , energia);

    //Próxima etapa--> partir da altura 0 , e chegar ate a 5/4 da altura, qual será a nova massa necessária para que ele atinja a nova altura
    // no ponto B ele chega com o valor da variavel energia
    // somente com a energia potencial, o carro nao consegue chegar ao topo, entao a massa tem que ser reduzida, amgicamnete


    // agora estamos calculando a massa que ele precisa atingir para consegeguir alcançar o topo do ponto C
    float massaNecessaria= energia / (g * (altura * 1.25));
    float porcentagem = parado.massa / massaNecessaria;
    printf("A porcentagem de massa necessária, em comparação com a antiga massa é: %f\n", porcentagem);

    //o usuário da a massa e precisamos calcular se ela é viável ou não para o veículo seguir o trejeto
    float massaUsuario;
    printf("Digite a nova massa:");
    scanf("%f", &massaUsuario);

    if((massaUsuario > massaNecessaria * 1.1)||(massaUsuario < massaNecessaria * 0.9)) {
        time(3);
        printf("Carro decolou nos topos\nGame Over");
        return 1;
    }

    printf("O veículo alcançou a ponto C com sucesso");

    // nesse ponto precisamos calcular a energia potencial de E, pois a cinética de D terá q ser igual
    // ent devemos calcular um freio para q haja perda de energia entre C e D

    // energia potencial em E, é m*g*h, considerando a nova massa digitada pelo usuário


    // energia potencial em E
    potention = potencial(massaUsuario , altura * 0.75 , g);

    // agora temos que igualar a energia cinética em D com a potencial em


    return 0;
}