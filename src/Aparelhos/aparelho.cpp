//
// Created by 35191 on 07/11/2023.
//

#include "aparelho.h"

Aparelho::Aparelho(char id) : id(id),ligado(false) {}

bool Aparelho::estaLigado() const {
    return ligado;
}

void Aparelho::setLigado(bool estado) {
    ligado = estado;
}

char Aparelho::getId() const {
    return id;
}
