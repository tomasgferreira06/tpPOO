#include "Processador.h"

#include <iostream>

using namespace std;

Processador::Processador(const string& comando) : comando(comando) {}

Processador::~Processador() {}

void Processador::adicionarRegra(const Regra& regra) {
    regras.push_back(regra);
}

void Processador::removerRegra(int indice) {
    if (indice >= 0 && indice < regras.size()) {
        regras.erase(regras.begin() + indice);
    }
}

void Processador::listarRegras() const {
    cout << "Regras do Processador:" << endl;
    for (size_t i = 0; i < regras.size(); ++i) {
        cout << "[" << i << "] ";
    }
}

string Processador::acionarComando(double valorSensor) const {
    for (const Regra& regra : regras) {
        if (!regra.avaliar(valorSensor)) {
            // Se qualquer regra não for satisfeita, retorna comando vazio
            return "";
        }
    }
    // Se todas as regras são satisfeitas, retorna o comando associado ao processador
    return comando;
}
