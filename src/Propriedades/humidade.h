//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_HUMIDADE_H
#define TPPOO_HUMIDADE_H

#include "propriedade.h"

class Humidade : public Propriedade{

private:
    double valor;

public:
    Humidade(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;

};


#endif //TPPOO_HUMIDADE_H
