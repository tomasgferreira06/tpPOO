#include "temperatura.h"
#include "propriedade.h"


Temperatura::Temperatura(double valor) : valor(valor) {}

double Temperatura::getValor() const {
    return valor;
}

void Temperatura::setValor(double novoValor) {
    if(isValorValido(novoValor))
        valor=novoValor;
}

bool Temperatura::isValorValido(double novoValor) const {
    return novoValor >= -273; // temperatura mínima
}
