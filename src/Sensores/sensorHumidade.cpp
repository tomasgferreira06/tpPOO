//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorHumidade.h"

SensorHumidade::SensorHumidade() : Sensor(), humidade(0.0) {}

double SensorHumidade::getHumidade() const {
    return humidade;
}

void SensorHumidade::setHumidade(float humidade) {
    SensorHumidade::humidade = humidade;
}

std::string SensorHumidade::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Humidade" << getHumidade();
    return ss.str();
}
