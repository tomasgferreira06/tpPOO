//
// Created by 35191 on 24/12/2023.
//

#ifndef TPPOO_AQUECEDOR_H
#define TPPOO_AQUECEDOR_H


#include "aparelho.h"

class Aquecedor : public Aparelho {
public:
    Aquecedor();
    void liga() override;
    void desliga() override;
};

#endif //TPPOO_AQUECEDOR_H
