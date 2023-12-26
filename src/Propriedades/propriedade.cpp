//
// Created by 35191 on 07/11/2023.
//

#include "propriedade.h"




const string &Propriedade::getNome() const {
    return nome;
}

const string &Propriedade::getUnidade() const {
    return unidade;
}

int Propriedade::getMin() const {
    return min;
}

int Propriedade::getMax() const {
    return max;
}

int Propriedade::getValor() const {
    return valor;
}

void Propriedade::setValor(int valor) {
    Propriedade::valor = valor;
}
