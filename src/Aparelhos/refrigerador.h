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

    int getContador() const;

    void setContador(int contador);

    bool isSomAumentado() const;

    void setSomAumentado(bool somAumentado);

    bool isDesligadoRecentemente() const;

    void setDesligadoRecentemente(bool desligadoRecentemente);
};

#endif //TPPOO_REFRIGERADOR_H
