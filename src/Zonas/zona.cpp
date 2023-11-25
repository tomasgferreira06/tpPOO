#include "zona.h"

// Construtor
Zona::Zona(int id, int largura, int comprimento)
        : id(id), largura(largura), comprimento(comprimento) {}

// Getters
int Zona::getId() const {
    return id;
}

int Zona::getLargura() const {
    return largura;
}

int Zona::getComprimento() const {
    return comprimento;
}


void Zona::addAparelho(const std::shared_ptr<Aparelho>& aparelho) {
    aparelhos.push_back(aparelho);
}

void Zona::removerAparelho(int idAparelho) {
    // Implementar lógica para remover aparelho pelo ID
}


void Zona::addSensor(const std::shared_ptr<Sensor>& sensor) {
    sensores.push_back(sensor);
}

void Zona::removerSensor(int idSensor) {
    // Implementar lógica para remover sensor pelo ID
}


void Zona::addProcessador(const std::shared_ptr<Processador>& processador) {
    processadores.push_back(processador);
}

void Zona::removerProcessador(int idProcessador) {
    // Implementar lógica para remover processador pelo ID
}

