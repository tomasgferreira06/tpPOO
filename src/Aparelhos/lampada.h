
#ifndef TPPOO_LAMPADA_H
#define TPPOO_LAMPADA_H


#include "aparelho.h"

class Lampada : public Aparelho {
public:
    Lampada();
    void liga() override;
    void desliga() override;
    std::string getNome() const override;
};
#endif //TPPOO_LAMPADA_H
