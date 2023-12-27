//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorMovimento.h"

SensorMovimento::SensorMovimento() : Sensor(), vibracao(0.0){}

double SensorMovimento::getVibracao() const {
    return vibracao;
}

void SensorMovimento::setVibracao(float vibracao) {
    SensorMovimento::vibracao = vibracao;
}

std::string SensorMovimento::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Movimento" << getVibracao();
    return ss.str();
}

double SensorMovimento::getValor() const {
    return getVibracao();
}
