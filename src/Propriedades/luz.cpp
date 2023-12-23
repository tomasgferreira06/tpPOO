

#include "luz.h"

Luz::Luz(double valor) : valor(valor) {}

double Luz::getValor() const {
    return valor;
}

void Luz::setValor(double novoValor){
    if(isValorValido(novoValor))
        valor = novoValor;
}

bool Luz::isValorValido(double novoValor) const {
    return novoValor >= 0; // valor mínimo de 0 lúmens
}






