

#include "IgualA.h"

RegraIgualA::RegraIgualA(Sensor *sensor, double valor) : Regra(sensor),valorComparacao(valor){}

bool RegraIgualA::avaliar() const {
    return getSensorAssociado()->getValor() == getValorComparacao();
}

void RegraIgualA::setValorComparacao(double valorComparacao) {
    RegraIgualA::valorComparacao = valorComparacao;
}

double RegraIgualA::getValorComparacao() const {
    return valorComparacao;
}
