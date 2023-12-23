//
// Created by 35191 on 23/12/2023.
//

#include "sensorSom.h"

sensorSom::sensorSom(Som &som) : propriedade(som){}

char sensorSom::getLetraVisualizacao() const {
    return 'o';
}

double sensorSom::lerValor() const {
    return propriedade.getValor();
}
