#include "Regra.h"
using namespace std;


int Regra::nextID= -1;


Regra::Regra(Sensor* sensor) : sensorAssociado(sensor), id(nextID++) {}


int Regra::getId() const {
    return id;
}




Sensor *Regra::getSensorAssociado() const {
    return sensorAssociado;
}

