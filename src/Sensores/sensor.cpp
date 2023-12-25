
#include "sensor.h"

int Sensor::nextIdSensor = -1;

Sensor::Sensor() : idSensor(nextIdSensor) {}

int Sensor::getIdSensor() const {
    return idSensor;
}
