//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_FORA_H
#define TPPOO_FORA_H

#include "regra.h"

class Fora : public Regra{
private:
    double valorInferior;
    double valorSuperior;

public:
    Fora(double inferior, double superior);
    bool avaliar(double valor) const override;

};

#endif //TPPOO_FORA_H
