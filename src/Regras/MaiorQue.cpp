//
// Created by 35191 on 23/12/2023.
//

#include "MaiorQue.h"

MaiorQue::MaiorQue(double valor) : valorCompararacao(valor){}

bool MaiorQue::avaliar(double valor) const {
    return valor > valorCompararacao;
}
