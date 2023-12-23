#include "Processador.h"

#include <iostream>

using namespace std;


Processador::Processador(Aparelho *aparelho) : aparelhoAssociado(aparelho){}

void Processador::adicionarRegra(Regra *regra) {
    regras.push_back(regra);
}

void Processador::processar(double valorSensor) {

    for(const auto &regra : regras){
        if( regra->avaliar(valorSensor) ){
            //Acionar o aparelho
        }
    }
}

