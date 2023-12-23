//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_VIBRACAO_H
#define TPPOO_VIBRACAO_H

#include "propriedade.h"

class Vibracao : public Propriedade{

private:
    double valor;

public:
    Vibracao(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;


};



#endif //TPPOO_VIBRACAO_H
