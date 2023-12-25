//
// Created by 35191 on 23/12/2023.
//

#include "sensorTemperatura.h"

SensorTemperatura::SensorTemperatura(Temperatura &temp) : propriedade(temp) {}

char SensorTemperatura::getLetraVisualizacao() const {
    return 't';
}

double SensorTemperatura::lerValor() const {
    return propriedade.getValor();
}
