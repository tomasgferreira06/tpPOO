//
// Created by 35191 on 23/12/2023.
//

#include "som.h"

Som::Som(double valor) : valor(valor) {}

double Som::getValor() const {
    return valor;
}

void Som::setValor(double novoValor) {
    if(isValorValido(novoValor))
        valor = novoValor;
}

bool Som::isValorValido(double novoValor) const {
    return novoValor >= 0; // valor mínimo 0 Decibéis
}
