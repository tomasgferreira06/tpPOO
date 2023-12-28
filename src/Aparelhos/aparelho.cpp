//
// Created by 35191 on 07/11/2023.
//

#include "aparelho.h"

int Aparelho::nextIdAparelho = 0;

Aparelho::Aparelho() : idAparelho(nextIdAparelho),ligado(false),ultimoComando("desligado") {
    nextIdAparelho++;

}

bool Aparelho::estaLigado() const {
    return ligado;
}
void Aparelho::receberComando(const std::string& comando) {
    if (comando == "liga") {
        setLigado(true);
    } else if (comando == "desliga") {
        setLigado(false);
    }
}

void Aparelho::setLigado(bool estado) {
    ligado = estado;
    ultimoComando = estado ? "ligado" : "desligado"; // Atualiza o último comando
}

int Aparelho::getIdAparelho() const {
    return idAparelho;
}

const std::string &Aparelho::getUltimoComando() const {
    return ultimoComando;
}

void Aparelho::setUltimoComando(const std::string &ultimoComando) {
    Aparelho::ultimoComando = ultimoComando;
}



