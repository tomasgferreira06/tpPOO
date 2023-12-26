//
// Created by 35191 on 26/12/2023.
//

#include "sensorFumo.h"

SensorFumo::SensorFumo() : Sensor(), fumo(0.0){}

double SensorFumo::getFumo() const {
    return fumo;
}

void SensorFumo::setFumo(float fumo) {
    SensorFumo::fumo = fumo;
}
