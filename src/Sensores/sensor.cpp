
#include "sensor.h"

int Sensor::nextIdSensor = 0;

Sensor::Sensor() : idSensor(nextIdSensor) {
    nextIdSensor++; // Incrementa o próximo ID disponível
}

int Sensor::getIdSensor() const {
    return idSensor;
}
