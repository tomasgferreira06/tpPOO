

#ifndef TPPOO_SOM_H
#define TPPOO_SOM_H


#include "propriedade.h"

class Som : public Propriedade{

private:
    double valor;

public:

    Som(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;
};

#endif //TPPOO_SOM_H
