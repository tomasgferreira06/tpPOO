#include "Processador.h"

using namespace std;

int Processador::nextIdProcessador = 0;

Processador::Processador(char _comando) : idProcessador(nextIdProcessador), comando(_comando){
    nextIdProcessador++;
}

void Processador::adicionarRegra(Regra *novaRegra) {
    regras.push_back(novaRegra);
}

void Processador::listarRegras() const {
   // std::cout << "Lista de regras do processador de regras (ID: " << getIdProcessador() << "):";
    for (const auto& regra : regras) {
        //std::cout << "ID da regra: " << regra->getId() << std::endl;
       // std::cout << "Tipo de regra: " << regra->getNome() << std::endl;
       // std::cout << "Sensor associado: " << regra->getSensorAssociado()->getNome() << " (ID: " << regra->getSensorAssociado()->getId() << ")" << std::endl;
       // std::cout << "----" << std::endl;
    }
}

int Processador::getIdProcessador() const {
    return idProcessador;
}

char Processador::getComando() const {
    return comando;
}

void Processador::associarAparelho(Aparelho *aparelho) {
    aparelhosAssociados.push_back(aparelho);
}

const vector<Regra *> &Processador::getRegras() const {
    return regras;
}

int Processador::getRegrasNum() const {
    return regras.size();
}





