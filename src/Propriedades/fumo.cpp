//
// Created by 35191 on 23/12/2023.
//

#include "fumo.h"

Fumo::Fumo(double valor) : valor(valor){}

double Fumo::getValor() const {
    return valor;
}

void Fumo::setValor(double novoValor) {

}

bool Fumo::isValorValido(double novoValor) const {
    if(novoValor >= 0 && novoValor <= 100){
        return true;
    }else{
        return false;
    }
}
