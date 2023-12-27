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

void Aparelho::setLigado(bool estado) {
    ligado = estado;
    ultimoComando = estado ? "ligado" : "desligado"; // Atualiza o último comando
}

int Aparelho::getIdAparelho() const {
    return idAparelho;
}



