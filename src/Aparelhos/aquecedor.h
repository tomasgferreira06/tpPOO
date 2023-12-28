
#ifndef TPPOO_AQUECEDOR_H
#define TPPOO_AQUECEDOR_H


#include "aparelho.h"

class Aquecedor : public Aparelho {
private:
    int contador;
public:
    Aquecedor();
    void executar() override;
    void liga() override;
    void desliga() override;
    std::string getNome() const override;
};

#endif //TPPOO_AQUECEDOR_H
