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
    void liga(term::Window & com_efetuadosWindow) override;
    void executar(term::Window & com_efetuadosWindow) override;
    void desliga(term::Window & com_efetuadosWindow) override;
    std::string getNome() const override;
};

#endif //TPPOO_REFRIGERADOR_H
