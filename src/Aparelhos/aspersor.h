//
// Created by User on 28/12/2023.
//

#ifndef TPPOO_ASPERSOR_H
#define TPPOO_ASPERSOR_H

#include "..\Zonas\zona.h"
#include "aparelho.h"

class Aspersor : public Aparelho {
private:
    int contador;
public:
    Aspersor(Zona *pZona);
    void liga(term::Window & com_efetuadosWindow) override;
    void executar(term::Window & com_efetuadosWindow) override;
    void desliga(term::Window & com_efetuadosWindow) override;
    std::string getNome() const override;
};

#endif //TPPOO_ASPERSOR_H
