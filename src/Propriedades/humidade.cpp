//
// Created by 35191 on 23/12/2023.
//

#include "humidade.h"

Humidade::Humidade(double valor) : valor(valor) {}


double Humidade::getValor() const {
    return valor;
}

void Humidade::setValor(double novoValor) {
    if(isValorValido(novoValor))
        valor = novoValor;
}


bool Humidade::isValorValido(double novoValor) const {
    if(novoValor >= 0 && novoValor <= 100) {
        return true;
    } else{
        return false;
    }
}
