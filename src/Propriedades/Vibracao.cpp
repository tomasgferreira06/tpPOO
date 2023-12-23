//
// Created by 35191 on 23/12/2023.
//

#include "Vibracao.h"

Vibracao::Vibracao(double valor) : valor(valor) {}

double Vibracao::getValor() const {
    return valor;
}

void Vibracao::setValor(double novoValor) {
    if(isValorValido(novoValor))
        valor = novoValor;
}

bool Vibracao::isValorValido(double novoValor) const {
    return novoValor >= 0; // valor mínimo 0 hertz
}
