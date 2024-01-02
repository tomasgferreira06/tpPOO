
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
    void executar(term::Window & com_efetuadosWindow) override;
    void liga(term::Window & com_efetuadosWindow) override;
    void desliga(term::Window & com_efetuadosWindow) override;
    std::string getNome() const override;
    bool isAdicionouRuido() const;

    void setAdicionouRuido(bool adicionouRuido);

    int getContador() const;

    void setContador(int contador);
};

#endif //TPPOO_AQUECEDOR_H
