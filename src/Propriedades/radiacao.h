#ifndef TPPOO_RADIAÇÃO_H
#define TPPOO_RADIAÇÃO_H


#include "propriedade.h"

class Radiacao : public Propriedade{

private:
    double valor;

public:
    Radiacao(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;

};


#endif //TPPOO_RADIAÇÃO_H
