
#include "zona.h"
#include "../Aparelhos/aparelho.h"

using namespace std;


Zona::Zona() {}

Zona::~Zona() {
    limparZona();
}

void Zona::adicionarSensor(Sensor *sensor) {

}

void Zona::adicionarAparelho(Aparelho *aparelho) {

}

void Zona::adicionarProcessador(Processador *processador) {

}

void Zona::adicionarPropriedade(Propriedade *propriedade) {

}

void Zona::limparZona() {

    for (Sensor* sensor : sensores) {
        delete sensor;
    }
    sensores.clear();

    for (Aparelho* aparelho : aparelhos) {
        delete aparelho;
    }
    aparelhos.clear();

    for (Processador* processador : processadores) {
        delete processador;
    }
    processadores.clear();

    for (Propriedade* propriedade : propriedades) {
        delete propriedade;
    }
    propriedades.clear();
}



