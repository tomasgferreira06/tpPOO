
#ifndef TPPOO_LAMPADA_H
#define TPPOO_LAMPADA_H

#include "..\Zonas\zona.h"
#include "aparelho.h"

class Lampada : public Aparelho {
private:
    int contador;
    bool adicionouLumens;
public:
    Lampada(Zona *pZona);
    void liga() override;
    void executar() override;
    void desliga() override;
    std::string getNome() const override;
};
#endif //TPPOO_LAMPADA_H
