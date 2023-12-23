//
// Created by 35191 on 23/12/2023.
//

#include "radiacao.h"

Radiacao::Radiacao(double valor) : valor(valor) {}

double Radiacao::getValor() const {
    return valor;
}

void Radiacao::setValor(double novoValor) {
    if(isValorValido(novoValor))
        valor = novoValor;
}

bool Radiacao::isValorValido(double novoValor) const {
    return novoValor >= 0; // valor mínimo 0 Becquerel
}
