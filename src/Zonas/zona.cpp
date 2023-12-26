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
#include "../Aparelhos/aquecedor.h"
#include "../Propriedades/luz.h"
#include "../Propriedades/Radiacao.h"
#include "../Propriedades/Vibracao.h"
#include "../Propriedades/Humidade.h"
#include "../Propriedades/Fumo.h"
#include "../Propriedades/som.h"

using namespace std;


Zona::Zona(int id, term::Window* win)
        : id(id), window(win) {

    Propriedade* temp = new Temperatura();
    propriedades[temp->getNome()] = temp;

    Propriedade* luz = new Luz();
    propriedades[luz->getNome()] = luz;

    Propriedade* rad = new Radiacao();
    propriedades[rad->getNome()] = rad;

    Propriedade* vib = new Vibracao();
    propriedades[vib->getNome()] = vib;

    Propriedade* hum = new Humidade();
    propriedades[hum->getNome()] = hum;

    Propriedade* fum = new Fumo();
    propriedades[fum->getNome()] = fum;

    Propriedade* som = new Som();
    propriedades[som->getNome()] = som;
}


Zona::~Zona() {
    limparZona();
}



void Zona::adicionarAparelho(Aparelho *aparelho) {
    aparelhos.push_back(aparelho);
}

void Zona::adicionarProcessador(Processador *processador) {

}

void Zona::adicionarPropriedade(Propriedade* propriedade) {
    propriedades[propriedade->getNome()] = propriedade;
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

    for (auto& entry : propriedades) {
        delete entry.second;
    }
    propriedades.clear();
}

int Zona::getId() const {
    return id;
}

/*void Zona::acionaAparelho(char id, bool ligar) {
    for (auto* aparelho : aparelhos) {
        if (aparelho->getIdAparelho() == id) {
            if (ligar) aparelho->liga();
            else aparelho->desliga();
            break; // Supondo que só há um aparelho com cada id
        }
    }
} */

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

void Zona::adicionarAparelho(char tipo) {
    switch (tipo) {
        case 'a':
            aparelhos.push_back(new Aquecedor());
            break;
        case 's':

            break;
        case 'r':

            break;
        case 'l':

            break;
        default:

            break;
    }
}

int Zona::getAparelhosNum() const {
    return aparelhos.size();
}

const vector<Aparelho *> &Zona::getAparelhos() const {
    return aparelhos;
}

bool Zona::removerAparelho(int idAparelho) {
    for (auto it = aparelhos.begin(); it != aparelhos.end(); ++it) {
        if ((*it)->getIdAparelho() == idAparelho) {
            aparelhos.erase(it);
            return true;
        }
    }
    return false;
}

Propriedade *Zona::getPropriedade(const string &nome) {
    auto it = propriedades.find(nome);
    if (it != propriedades.end()) {
        return it->second;
    }
    return nullptr; // Return null if property not found
}

const map<std::string, Propriedade *> &Zona::getPropriedades() const {
    return propriedades;
}

/*std::string listarSensores() const {
    std::ostringstream ss;
    for (const auto& sensor : sensores) {
        ss << sensor->getInfo() << std::endl;
    return ss.str();
} */


