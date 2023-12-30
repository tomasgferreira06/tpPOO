
#ifndef TPPOO_AQUECEDOR_H
#define TPPOO_AQUECEDOR_H

#include "..\Zonas\zona.h"
#include "aparelho.h"

class Aquecedor : public Aparelho {
private:
    int contador;
    bool adicionouRuido;


public:
    Aquecedor(Zona *pZona);
    void executar() override;
    void liga() override;
    void desliga() override;
    std::string getNome() const override;
    bool isAdicionouRuido() const;

    void setAdicionouRuido(bool adicionouRuido);
};

#endif //TPPOO_AQUECEDOR_H
