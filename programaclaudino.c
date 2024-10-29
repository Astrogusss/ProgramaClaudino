#include <stdio.h>
#include "programaclaudino.h"
#include <math.h>
#include <stdlib.h>

float cinetica(float massa, float velocidade) {
    return (massa * (pow(velocidade,2))) / 2;
}

float potencial (float massa , float altura , float gravidade) {
    return massa * altura * gravidade;
}

float energia(float cinetica , float potencial) {
    return cinetica + potencial;
}

float aceleracaofreio(float energiamaior , float energiamenor , float altura , float massa){
    return ((energiamaior - energiamenor) / altura) / massa;
}