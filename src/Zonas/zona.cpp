
#include "zona.h"
#include "../Aparelhos/aparelho.h"

using namespace std;

Zona::Zona(int id, int largura, int comprimento) : id(id), largura(largura), comprimento(comprimento) {}

int Zona::getId() const {
    return id;
}

int Zona::getLargura() const {
    return largura;
}

int Zona::getComprimento() const {
    return comprimento;
}

void Zona::addComponente(const std::shared_ptr<Aparelho> &componente) {
    componentes.push_back(componente);
}

void Zona::removerComponente(int componenteId) {
    // Logic to remove a component based on its ID
    // This will depend on how you identify each Aparelho
}
