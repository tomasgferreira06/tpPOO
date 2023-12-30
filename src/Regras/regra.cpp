#include "Regra.h"
using namespace std;


int Regra::nextID = 0;

Regra::Regra(Sensor* sensor) : sensorAssociado(sensor), id(nextID) {
    nextID++;
}

int Regra::getId() const {
    return id;
}

Sensor *Regra::getSensorAssociado() const {
    return sensorAssociado;
}

