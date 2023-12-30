

#include "IgualA.h"

RegraIgualA::RegraIgualA(Sensor *sensor, double valor) : Regra(sensor),valorComparacao(valor){}

bool RegraIgualA::avaliar() const {
    return getSensorAssociado()->getValor() == getValorComparacao();
}

void RegraIgualA::setValorComparacao(double valorComparacao) {
    RegraIgualA::valorComparacao = valorComparacao;
}
Regra* RegraIgualA::duplica() const {
    return new RegraIgualA(*this);
}


double RegraIgualA::getValorComparacao() const {
    return valorComparacao;
}

std::string RegraIgualA::getNomeRegra() const {
    return "igual_a";
}
