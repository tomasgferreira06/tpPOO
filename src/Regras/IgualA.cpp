//
// Created by 35191 on 23/12/2023.
//

#include "IgualA.h"

IgualA::IgualA(double valor) : valorComparacao(valor) {}

bool IgualA::avaliar(double valor) const {
    return valor == valorComparacao;
}


