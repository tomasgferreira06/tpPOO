//
// Created by 35191 on 23/12/2023.
//

#include "sensorTemperatura.h"

SensorTemperatura::SensorTemperatura() : Sensor(), temperatura(0.0){
}

double SensorTemperatura::getTemperatura() const {
    return temperatura;
}

void SensorTemperatura::setTemperatura(float temperatura) {
    SensorTemperatura::temperatura = temperatura;
}
