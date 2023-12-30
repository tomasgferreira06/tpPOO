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
#include "../Aparelhos/aspersor.h"
#include "../Aparelhos/refrigerador.h"
#include "../Aparelhos/lampada.h"

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




void Zona::adicionarProcessador(Processador *processador) {
    processadores.push_back(processador);
    atualizarJanela();
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









void Zona::adicionarSensor(char tipo) {
    switch (tipo) {
        case 't':
            sensores.push_back(new SensorTemperatura(this));
            break;
        case 'v':
            sensores.push_back(new SensorMovimento(this));
            break;
        case 'm':
            sensores.push_back(new SensorLuminosidade(this));
            break;
        case 'd':
            sensores.push_back(new SensorRadiacao(this));
            break;
        case 'h':
            sensores.push_back(new SensorHumidade(this));
            break;
        case 'o':
            sensores.push_back(new SensorSom(this));
            break;
        case 'f':
            sensores.push_back(new SensorFumo(this));
            break;
        default:
            break;
    }
    atualizarJanela();
}

int Zona::getSensoresNum() const {
    return sensores.size();
}

bool Zona::removerSensor(int idSensor) {
    for (auto it = sensores.begin(); it != sensores.end(); ++it) {
        if ((*it)->getIdSensor() == idSensor) {
            sensores.erase(it);
            return true;
            atualizarJanela();
        }
    }

    return false;
}



const vector<Sensor *> &Zona::getSensores() const {
    return sensores;
}

void Zona::adicionarAparelho(Zona* zona,char tipo) {
    switch (tipo) {
        case 'a':
            aparelhos.push_back(new Aquecedor(zona));
            break;
        case 's':
            aparelhos.push_back(new Aspersor(zona));
            break;
        case 'r':
            aparelhos.push_back(new Refrigerador(zona));
            break;
        case 'l':
            aparelhos.push_back(new Lampada(zona));
            break;
        default:
            break;
    }
    atualizarJanela();
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
            atualizarJanela();
        }
    }
    return false;
}

bool Zona::removerProcessador(int idProcessador) {
    for (auto it = processadores.begin(); it != processadores.end(); ++it) {
        if ((*it)->getIdProcessador() == idProcessador) {
           processadores.erase(it);
            return true;
            atualizarJanela();
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

int Zona::getProcessadoresNum() const {
    return processadores.size();
}

Processador *Zona::encontrarProcessadorPorId(int idProcRegras) {
    for (Processador* processador : processadores) {
        if (processador->getIdProcessador() == idProcRegras) {
            return processador;
        }
    }
    return nullptr; // Retorna nullptr se o processador não for encontrado
}
Aparelho *Zona::encontrarAparelhoPorId(int idAparelho) {
    for (Aparelho* aparelho : aparelhos) {
        if (aparelho->getIdAparelho() == idAparelho) {
            return aparelho;
        }
    }
    return nullptr; // Retorna nullptr se o processador não for encontrado
}

Sensor *Zona::encontrarSensorPorId(int idSensor) {
    for (Sensor* sensor : sensores) {
        if (sensor->getIdSensor() == idSensor) {
            return sensor;
        }
    }
    return nullptr; // Retorna nullptr se o sensor não for encontrado
}
void Zona::atualizarJanela() const {
    term::Window* window = this->getJanela();
    window->clear();
    *window << term::set_color(11) << "ID:" << this->getId()
            << term::move_to(0, 1) << "S:" << this->getSensoresNum()
            << term::move_to(0, 2) << "P:" << this->getProcessadoresNum()
            << term::move_to(0, 3) << "A:" << this->getAparelhosNum();
}

const vector<Processador *> &Zona::getProcessadores() const {
    return processadores;
}




