
#ifndef TPPOO_TEMPERATURA_H
#define TPPOO_TEMPERATURA_H


#include "propriedade.h"

class Temperatura : public Propriedade {
private:
    double valor;

public:
    Temperatura(double valor);
    double getValor() const override;
    void setValor(double novoValor) override;
    bool isValorValido(double novoValor) const override;


};


#endif //TPPOO_TEMPERATURA_H