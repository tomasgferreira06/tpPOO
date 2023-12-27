//
// Created by 35191 on 23/12/2023.
//

#include <sstream>
#include "sensorTemperatura.h"

SensorTemperatura::SensorTemperatura() : Sensor(), temperatura(0.0){
}

double SensorTemperatura::getTemperatura() const {
    return temperatura;
}

void SensorTemperatura::setTemperatura(float temperatura) {
    SensorTemperatura::temperatura = temperatura;
}

std::string SensorTemperatura::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Temperatura" << getTemperatura();
    return ss.str();
}

double SensorTemperatura::getValor() const {
    return getTemperatura();
}
