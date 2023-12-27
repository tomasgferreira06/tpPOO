//
// Created by 35191 on 23/12/2023.
//

#include "Fora.h"



RegraFora::RegraFora(Sensor *sensor, double min, double max) : Regra(sensor), valorMin(min), valorMax(max) {}

bool RegraFora::avaliar() const {
    double valorSensor = getSensorAssociado()->getValor();
    return valorSensor < getValorMin() || valorSensor > getValorMax();
}

double RegraFora::getValorMin() const {
    return valorMin;
}

double RegraFora::getValorMax() const {
    return valorMax;
}

void RegraFora::setValorMin(double valorMin) {
    RegraFora::valorMin = valorMin;
}

void RegraFora::setValorMax(double valorMax) {
    RegraFora::valorMax = valorMax;
}

std::string RegraFora::getNomeRegra() const {
    return "fora";
}



