//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_MAIORQUE_H
#define TPPOO_MAIORQUE_H

#include "regra.h"

class MaiorQue : public Regra{

private:
    double valorCompararacao;

public:
    MaiorQue(double valor);
    bool avaliar(double valor) const override;


};

#endif //TPPOO_MAIORQUE_H
