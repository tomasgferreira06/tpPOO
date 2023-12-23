//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_FUMO_H
#define TPPOO_FUMO_H


#include "propriedade.h"

class Fumo : public Propriedade{

private:
    double valor;

public:
    Fumo(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;

};

#endif //TPPOO_FUMO_H
