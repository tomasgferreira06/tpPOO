//
// Created by 35191 on 25/11/2023.
//

#include "temperatura.h"
#include "propriedade.h"

Temperatura::Temperatura() : valorTemp(0.0) {}

void Temperatura::setValor(double valor) {

    if (valor >= -273.15) {
        valorTemp = valor;
    } else {
        valorTemp = -273.15;
    }
}

double Temperatura::getValor() const {
    return valorTemp;
}