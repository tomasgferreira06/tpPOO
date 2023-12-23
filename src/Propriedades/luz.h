#ifndef TPPOO_LUZ_H
#define TPPOO_LUZ_H

#include "propriedade.h"


class Luz : public Propriedade{

private:
    double valor;

public:
    Luz(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;


};

#endif //TPPOO_LUZ_H
