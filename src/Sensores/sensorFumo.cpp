//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorFumo.h"

SensorFumo::SensorFumo() : Sensor(), fumo(0.0){}

double SensorFumo::getFumo() const {
    return fumo;
}

void SensorFumo::setFumo(float fumo) {
    SensorFumo::fumo = fumo;
}

std::string SensorFumo::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Fumo" << getFumo();
    return ss.str();
}
