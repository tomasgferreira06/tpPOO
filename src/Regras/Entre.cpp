//
// Created by 35191 on 23/12/2023.
//

#include "Entre.h"

Entre::Entre(double inferior, double superior) : valorInferior(inferior), valorSuperior(superior){}

bool Entre::avaliar(double valor) const {
    return valor >= valorInferior && valor <= valorSuperior;
}
