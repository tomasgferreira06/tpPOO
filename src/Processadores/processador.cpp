#include "processador.h"

Processador::Processador() {}

void Processador::addRegra(const std::shared_ptr<Regra>& regra) {
    regras.push_back(regra);
}

void Processador::processarRegras() {
    // Logic to process each rule
    // This will depend on how rules are defined and how they interact with sensors and devices
}
