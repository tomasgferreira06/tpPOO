#include <sstream>
#include <iostream>
#include "zona.h"
#include "../Aparelhos/aparelho.h"
#include "../Sensores/sensorTemperatura.h"
#include "../Sensores/sensorMovimento.h"
#include "../Sensores/sensorLuminosidade.h"
#include "../Sensores/sensorRadiacao.h"
#include "../Sensores/sensorHumidade.h"
#include "../Sensores/sensorSom.h"
#include "../Sensores/sensorFumo.h"

using namespace std;


Zona::~Zona() {
    limparZona();
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

void Zona::adicionarSensor(char tipo) {
    switch (tipo) {
        case 't':
            sensores.push_back(new SensorTemperatura());
            break;
        case 'v':
            sensores.push_back(new SensorMovimento());
            break;
        case 'm':
            sensores.push_back(new SensorLuminosidade());
            break;
        case 'd':
            sensores.push_back(new SensorRadiacao());
            break;
        case 'h':
            sensores.push_back(new SensorHumidade());
            break;
        case 'o':
            sensores.push_back(new SensorSom());
            break;
        case 'f':
            sensores.push_back(new SensorFumo());
            break;
        default:
            break;
    }
}

int Zona::getSensoresNum() const {
    return sensores.size();
}

bool Zona::removerSensor(int idSensor) {
    for (auto it = sensores.begin(); it != sensores.end(); ++it) {
        if ((*it)->getIdSensor() == idSensor) {
            sensores.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Sensor *> &Zona::getSensores() const {
    return sensores;
}

/*std::string listarSensores() const {
    std::ostringstream ss;
    for (const auto& sensor : sensores) {
        ss << sensor->getInfo() << std::endl;
    return ss.str();
} */


