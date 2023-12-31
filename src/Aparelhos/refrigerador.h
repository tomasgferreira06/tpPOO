//
// Created by User on 28/12/2023.
//

#ifndef TPPOO_REFRIGERADOR_H
#define TPPOO_REFRIGERADOR_H

#include "..\Zonas\zona.h"
#include "aparelho.h"

class Refrigerador : public Aparelho {
private:
    int contador;
    bool somAumentado;
    bool desligadoRecentemente;
public:
    Refrigerador(Zona *pZona);
    void liga() override;
    void executar() override;
    void desliga() override;
    std::string getNome() const override;
};

#endif //TPPOO_REFRIGERADOR_H
