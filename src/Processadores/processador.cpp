#include "Processador.h"

using namespace std;

int Processador::nextIdProcessador = 0;

Processador::Processador(char _comando) : idProcessador(nextIdProcessador), comando(_comando){
    nextIdProcessador++;
}

void Processador::adicionarRegra(Regra *novaRegra) {
    regras.push_back(novaRegra);
}

void Processador::removerRegra(int idRegra) {
    // Encontre a regra com o ID especificado e a remova
    for (auto it = regras.begin(); it != regras.end(); ++it) {
        if ((*it)->getId() == idRegra) {
            // Encontrou a regra, remova-a
            delete *it; // Certifique-se de liberar a memória alocada pela regra
            regras.erase(it);
            break; // Apenas uma regra pode ter o mesmo ID, então podemos sair do loop
        }
    }
}
void Processador::desassociarAparelho(int idAparelho) {
    // Percorre a lista de aparelhos associados e remove o aparelho com o ID especificado
    for (auto it = aparelhosAssociados.begin(); it != aparelhosAssociados.end(); ++it) {
        if ((*it)->getIdAparelho() == idAparelho) {
            // Encontrou o aparelho, remova-o
            aparelhosAssociados.erase(it);
            // Não é necessário usar 'delete' se os aparelhos não forem alocados dinamicamente
            break; // Assumindo que cada aparelho tem um ID único
        }
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

Processador::~Processador() {

}

void Processador::mudarComando(const char &novoComando) {
    Processador::comando = novoComando;
}





