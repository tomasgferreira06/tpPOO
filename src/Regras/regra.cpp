#include "Regra.h"
using namespace std;


Regra::Regra(const string& sensorId, const string& tipoComparacao, double valorComparacao)
        : sensorId(sensorId), tipoComparacao(tipoComparacao), valorComparacao(valorComparacao) {}

Regra::~Regra() {}

bool Regra::avaliar(double valorSensor) const {
    if (tipoComparacao == "igual_a") {
        return valorSensor == valorComparacao;
    } else if (tipoComparacao == "menor_que") {
        return valorSensor < valorComparacao;
    } else if (tipoComparacao == "maior_que") {
        return valorSensor > valorComparacao;
    } else if (tipoComparacao == "entre") {
        return (valorSensor >= valorComparacao) && (valorSensor <= valorComparacao);
    } else if (tipoComparacao == "fora") {
        return (valorSensor < valorComparacao) || (valorSensor > valorComparacao);
    } else {
        return false;
    }
}
