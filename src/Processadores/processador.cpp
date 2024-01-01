#include "Processador.h"

using namespace std;

int Processador::nextIdProcessador = 0;

Processador::Processador(Zona *zona ,string _comando) :zona(zona), idProcessador(nextIdProcessador), comando(_comando){
    nextIdProcessador++;

}

Processador::Processador(const Processador& ori) :zona(ori.zona), idProcessador(ori.idProcessador), comando(ori.comando){
    *this = ori;
}

Processador& Processador::operator=(const Processador& outro) {
    if (this != &outro) {
        // Primeiro, limpa as regras existentes
        for (auto& regra : regras) {
            delete regra;
        }
        regras.clear();

        // Agora, duplica as regras do outro processador
        for (const auto& regra : outro.regras) {
            regras.push_back(regra->duplica());
        }
    }
    return *this;
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

string Processador::getComando() const {
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
    for (Regra* regra : regras) {
        delete regra;
    }
    for (Aparelho* aparelho : aparelhosAssociados) {
        delete aparelho;
    }
}

void Processador::mudarComando(const string &novoComando) {
    Processador::comando = novoComando;
}

void Processador::avaliarRegras(term::Window & com_efetuadosWindow) {
    bool todasRegrasCumpridas = true;
    for (auto& regra : regras) {
        if (!regra->avaliar()) { // Supondo que Regra::avaliar retorna true se a regra for cumprida
            todasRegrasCumpridas = false;
            break;
        }
    }

    // Emitir comando para cada aparelho associado
    for (auto& aparelho : aparelhosAssociados) {
        if (todasRegrasCumpridas) {
            aparelho->receberComando("liga", com_efetuadosWindow);
        } else {
            aparelho->receberComando("desliga", com_efetuadosWindow);
        }
    }
}

Zona *Processador::getZona() const {
    return zona;
}


void Processador::removerTodasRegras() {
    for (auto& regra : regras) {
        delete regra; // Libera a memória alocada para a regra
    }
    regras.clear(); // Limpa a lista de regras
}


