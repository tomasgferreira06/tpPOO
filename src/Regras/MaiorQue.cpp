//
// Created by 35191 on 23/12/2023.
//

#include "MaiorQue.h"



RegraMaiorQue::RegraMaiorQue(Sensor *sensor, double valor) : Regra(sensor), valorComparacao(valor) {}

bool RegraMaiorQue::avaliar() const {
    return getSensorAssociado()->getValor() > getValorComparacao();
}

void RegraMaiorQue::setValorComparacao(double valorComparacao) {
    RegraMaiorQue::valorComparacao = valorComparacao;
}
Regra* RegraMaiorQue::duplica() const {
    return new RegraMaiorQue(*this);
}

double RegraMaiorQue::getValorComparacao() const {
    return valorComparacao;
}

std::string RegraMaiorQue::getNomeRegra() const {
    return "maior_que";
}

