#include <stdio.h>
#include "programaclaudino.h"
#include <math.h>


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
    printf("A energia potencial é: %0.2f e a energia cinetica é: %0.2f e suas somas é: %0.2f \n", potention , cineticon , energia);

    //Próxima etapa--> partir da altura 0 , e chegar ate a 5/4 da altura, qual será a nova massa necessária para que ele atinja a nova altura
    // no ponto B ele chega com o valor da variavel energia
    // somente com a energia potencial, o carro nao consegue chegar ao topo, entao a massa tem que ser reduzida, amgicamnete


    // agora estamos calculando a massa que ele precisa atingir para consegeguir alcançar o topo do ponto C
    float massaNecessaria= energia / (g * (altura * 1.25));
    float porcentagem = ceil(100*(parado.massa / massaNecessaria));
    printf("A porcentagem de massa necessária, em comparação com a antiga massa é: %0.2f\n", porcentagem);

    //o usuário da a massa e precisamos calcular se ela é viável ou não para o veículo seguir o trejeto
    printf("Digite a nova massa:");
    scanf("%f", &parado.massa);

    if((parado.massa > massaNecessaria * 1.1)||(parado.massa < massaNecessaria * 0.9)) {

        printf("Carro decolou nos topos\nGame Over");
        return 0;
    }

    printf("O veículo alcançou a ponto C com sucesso\n");

    // nesse ponto precisamos calcular a energia potencial de E, pois a cinética de D terá q ser igual
    // ent devemos calcular um freio para q haja perda de energia entre C e D
    // energia potencial em E, é m*g*h, considerando a nova massa digitada pelo usuário


    // energia potencial em E
    float potentialE = potencial(parado.massa , altura * 0.75 , g);
    float potentialC = potencial(parado.massa , altura * 1.25 , g);
    // a energia cinetica de D precisa ser a energia potencial em E, para isso precisamos aplicar uma força contrária ao movimento
    // agora para achar o trabalho da força freio, temos que a (energia potencial de C) - (enegia potencial de E)

    // depois temos que usar a segunda lei de newton para descobrir qual a aceleração que ela age no carro

    // resumindo o calculo do freio seria (energia potencia em C) - (energia potencial em E)

    float aceleracaofr = aceleracaofreio(potentialC , potentialE , altura * 1.25 , massaNecessaria);

    /*printf("A aceleração do freio que o carro terá que de ser é de %f\n : " , aceleracaofr); */

    // o usuário tem que informar qual aceleração (que ele achar) que o carrinho deverá ter
    float freioUsuario;
    printf("Digite o freio que será necessário (em m/s²):\n");
    scanf("%d", &freioUsuario);

    if((freioUsuario < aceleracaofr * 0.9) || (freioUsuario > aceleracaofr * 1.1)){
        printf("Errou otário\n");
        return 0;
    }

    printf("O veículo alcançou ao ponto E com sucesso\n");

    // agora temos que saber da energia total envolvida no ponto E, que seria o potencial nessa altura, que ja foi calculado = potencialE.
    // a energia que tem no ponto F é  = potencialE.

    energia = potentialE;

    // para calcular a massa necessaria, deveremos fazer o mesmo método que fizemso no momento anterior
    // a altura ser á metade dela
    float massa = massaNecessaria;
    massaNecessaria = energia / (g * (altura * 0.5));
    porcentagem = ceil(100*(massa/ massaNecessaria));
    printf("A porcentagem de massa necessária, em comparação com a antiga massa é %0.2f:\n", porcentagem);

    printf("Digite a nova massa:\n");
    scanf("%f", &parado.massa);

    if((parado.massa > massaNecessaria * 1.1) || (parado.massa < massaNecessaria * 0.9)) {
        printf("Carro decolou nos topos\nGameover");
        return 0;
    }

    printf("O veículo alcançou o ponto G com sucesso");
    // ele chega no ponto G com enegia = potentialE
    // temos que descombrir a energia potencial relacionada ao trajeto GH --> parado.massa * g * (1/8)*h

    int energiadescida = potencial(parado.massa , altura/8 , g);
    energia -= energiadescida;

    // agora essa energia será toda convertida em cinética, para descobrir sua velocidade, é somente igualar a energia cinética a variavel energia, isolando o a velociade;
    float velocidadeDescida = sqrt((energia * 2) / parado.massa);

    // agora aplicamos a fórmula de torricheli, para descobrir quantos m/s² terá que ter o freio

    //aqui estou meio que otimizando o codigo, poupando bytes
    aceleracaofr = (-1)*(pow(velocidadeDescida , 2)) / (2 * (3 * altura));
    printf("Digite o freio que será necessário (em m/s²): \n");
    scanf("%d", freioUsuario);

    if((freioUsuario < aceleracaofr * 0.9) || (freioUsuario > aceleracaofr * 1.1)){
        printf("Errou otário\n");
        return 0;
    }
    printf("O veículo conseguiu frear com sucesso até o ponto I \n parábens jogador vosmicê ganhou nessa bosta");
    return 0;

    //PEDRO, ALTEREI ACHO QUE A VARIAVEL "MASSA USUARIO" PAARA "PARADO.MASSA" PRA FICAR MAIS OTIMIZADO
}