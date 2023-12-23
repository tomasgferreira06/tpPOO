//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_MENORQUE_H
#define TPPOO_MENORQUE_H

#include "regra.h"

class MenorQue : public Regra{

private:
    double valorComparacao;

public:
    MenorQue(double valor);
    bool avaliar(double valor) const override;
};

#endif //TPPOO_MENORQUE_H
