//
// Created by User on 28/12/2023.
//

#ifndef TPPOO_ASPERSOR_H
#define TPPOO_ASPERSOR_H

#include "aparelho.h"

class Aspersor : public Aparelho {
public:
    Aspersor();
    void liga() override;
    void desliga() override;
    std::string getNome() const override;
};

#endif //TPPOO_ASPERSOR_H
