#include "zona.h"
#include "../Aparelhos/aparelho.h"

using namespace std;


Zona::~Zona() {
    limparZona();
}

void Zona::adicionarSensor(Sensor *sensor) {
    string sensorID = "s" + to_string(id) + "-" + to_string(nextSensorId++);
    sensor->setId(sensorID);
    sensores.push_back(sensor);
}

void Zona::adicionarAparelho(Aparelho *aparelho) {
    aparelhos.push_back(aparelho);
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

int Zona::getId() const {
    return id;
}

void Zona::acionaAparelho(char id, bool ligar) {
    for (auto* aparelho : aparelhos) {
        if (aparelho->getId() == id) {
            if (ligar) aparelho->liga();
            else aparelho->desliga();
            break; // Supondo que só há um aparelho com cada id
        }
    }
}

void Zona::aumentarTemperatura(int graus) {
    setTemperatura( getTemperatura() +  graus);
}


int Zona::getTemperatura() const {
    return temperatura;
}

void Zona::setTemperatura(int novaTemperatura) {
    if (novaTemperatura > 50) {
        temperatura = 50;
    } else {
        temperatura = novaTemperatura;
    }
}

int Zona::getRuido() const {
    return ruido;
}

void Zona::aumentarRuido(int db) {
     setRuido( getRuido() +  db);
}

void Zona::reduzirRuido(int db) {
    setRuido( getRuido() -  db);
}

void Zona::setRuido(int novoRuido) {
    if(novoRuido < 0){
        ruido = 0;
    }else{
        ruido = novoRuido;
    }
}

const vector<Sensor *> &Zona::getSensores() const {
    return sensores;
}

const vector<Aparelho *> &Zona::getAparelhos() const {
    return aparelhos;
}

const vector<Processador *> &Zona::getProcessadores() const {
    return processadores;
}

const vector<Propriedade *> &Zona::getPropriedades() const {
    return propriedades;
}


