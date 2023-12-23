//
// Created by 35191 on 23/12/2023.
//

#include "Fora.h"

Fora::Fora(double inferior, double superior) : valorInferior(inferior), valorSuperior(superior){}

bool Fora::avaliar(double valor) const {
    return valor < valorInferior || valor > valorSuperior;
}
