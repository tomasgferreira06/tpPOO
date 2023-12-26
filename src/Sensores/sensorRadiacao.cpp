//
// Created by 35191 on 26/12/2023.
//

#include "sensorRadiacao.h"

SensorRadiacao::SensorRadiacao() : Sensor(), radiacao(0.0) {}

double SensorRadiacao::getRadiacao() const {
    return radiacao;
}

void SensorRadiacao::setRadiacao(float radiacao) {
    SensorRadiacao::radiacao = radiacao;
}
