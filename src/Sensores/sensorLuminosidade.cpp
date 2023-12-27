//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade() : Sensor(),luz(0.0) {

}

double SensorLuminosidade::getLuz() const {
    return luz;
}

void SensorLuminosidade::setLuz(float luz) {
    SensorLuminosidade::luz = luz;
}

std::string SensorLuminosidade::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Luz" << getLuz();
    return ss.str();
}

double SensorLuminosidade::getValor() const {
   return getLuz();
}
