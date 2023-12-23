//
// Created by 35191 on 23/12/2023.
//

#include "sensorMovimento.h"

SensorMovimento::SensorMovimento(Vibracao &mov) : propriedade(mov) {}

char SensorMovimento::getLetraVisualizacao() const {
    return 'v';
}

double SensorMovimento::lerValor() const {
    return propriedade.getValor();
}
