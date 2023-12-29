
#include "sensor.h"

int Sensor::nextIdSensor = 0;

Sensor::Sensor(Zona *z) : zonaAssociada_(z),idSensor(nextIdSensor) {
    nextIdSensor++; // Incrementa o próximo ID disponível
}

int Sensor::getIdSensor() const {
    return idSensor;
}

Zona *Sensor::getZonaAssociada() const {
    return zonaAssociada_;
}
