//
// Created by 35191 on 23/12/2023.
//

#include "MenorQue.h"

MenorQue::MenorQue(double valor) : valorComparacao(valor){}

bool MenorQue::avaliar(double valor) const {
    return valor < valorComparacao;
}
