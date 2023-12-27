//
// Created by 35191 on 23/12/2023.
//

#include "Entre.h"



RegraEntre::RegraEntre(Sensor *sensor, double min, double max) : Regra(sensor), valorMin(min), valorMax(max){}

bool RegraEntre::avaliar() const {
    double valorSensor = getSensorAssociado()->getValor();
    return valorSensor > getValorMin() && valorSensor < getValorMax();
}

double RegraEntre::getValorMin() const {
    return valorMin;
}

void RegraEntre::setValorMin(double valorMin) {
    RegraEntre::valorMin = valorMin;
}

double RegraEntre::getValorMax() const {
    return valorMax;
}

void RegraEntre::setValorMax(double valorMax) {
    RegraEntre::valorMax = valorMax;
}


