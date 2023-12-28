//
// Created by User on 28/12/2023.
//

#ifndef TPPOO_REFRIGERADOR_H
#define TPPOO_REFRIGERADOR_H

#include "aparelho.h"

class Refrigerador : public Aparelho {
public:
    Refrigerador();
    void liga() override;
    void desliga() override;
    std::string getNome() const override;
};

#endif //TPPOO_REFRIGERADOR_H
