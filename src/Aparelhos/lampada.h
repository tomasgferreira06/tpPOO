
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
    void liga(term::Window & com_efetuadosWindow) override;
    void executar(term::Window & com_efetuadosWindow) override;
    void desliga(term::Window & com_efetuadosWindow) override;
    std::string getNome() const override;
};
#endif //TPPOO_LAMPADA_H
