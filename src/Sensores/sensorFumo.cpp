//
// Created by 35191 on 23/12/2023.
//

#include "sensorFumo.h"

sensorFumo::sensorFumo(Fumo &fum) : propriedade(fum) {}

char sensorFumo::getLetraVisualizacao() const {
    return 'f';
}

double sensorFumo::lerValor() const {
    return propriedade.getValor();
}
