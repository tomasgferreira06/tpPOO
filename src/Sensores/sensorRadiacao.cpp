//
// Created by 35191 on 23/12/2023.
//

#include "sensorRadiacao.h"

sensorRadiacao::sensorRadiacao(Radiacao &rad) : propriedade(rad){}

char sensorRadiacao::getLetraVisualizacao() const {
    return 'd';
}

double sensorRadiacao::lerValor() const {
    return propriedade.getValor();
}
