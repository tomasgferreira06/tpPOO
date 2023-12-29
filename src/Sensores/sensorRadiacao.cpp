//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorRadiacao.h"

SensorRadiacao::SensorRadiacao(Zona *a) : Sensor(a), radiacao(0.0) {}

double SensorRadiacao::getRadiacao() const {
    return radiacao;
}

void SensorRadiacao::setRadiacao(float radiacao) {
    SensorRadiacao::radiacao = radiacao;
}

std::string SensorRadiacao::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Radiacao" << getRadiacao();
    return ss.str();
}

double SensorRadiacao::getValor() const {
    return getRadiacao();
}

std::string SensorRadiacao::getTipoSensor() const {
    return "Radiacao";
}
