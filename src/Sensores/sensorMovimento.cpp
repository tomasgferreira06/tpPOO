//
// Created by 35191 on 26/12/2023.
//

#include "sensorMovimento.h"

SensorMovimento::SensorMovimento() : Sensor(), vibracao(0.0){}

double SensorMovimento::getVibracao() const {
    return vibracao;
}

void SensorMovimento::setVibracao(float vibracao) {
    SensorMovimento::vibracao = vibracao;
}
