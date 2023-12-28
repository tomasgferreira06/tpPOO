//
// Created by User on 28/12/2023.
//

#ifndef TPPOO_ASPERSOR_H
#define TPPOO_ASPERSOR_H

#include "aparelho.h"

class Aspersor : public Aparelho {
private:
    int contador;
public:
    Aspersor();
    void liga() override;
    void desliga() override;
    void executar() override;
    std::string getNome() const override;
};

#endif //TPPOO_ASPERSOR_H
