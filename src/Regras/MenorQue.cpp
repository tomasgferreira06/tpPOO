//
// Created by 35191 on 23/12/2023.
//

#include "MenorQue.h"

RegraMenorQue::RegraMenorQue(Sensor *sensor, double valor) : Regra(sensor), valorComparacao(valor){}

bool RegraMenorQue::avaliar() const {
    return getSensorAssociado()->getValor() < getValorComparacao();
}

double RegraMenorQue::getValorComparacao() const {
    return valorComparacao;
}

void RegraMenorQue::setValorComparacao(double valorComparacao) {
    RegraMenorQue::valorComparacao = valorComparacao;
}
Regra* RegraMenorQue::duplica() const {
    return new RegraMenorQue(*this);
}

std::string RegraMenorQue::getNomeRegra() const {
    return "menor_que";
}



