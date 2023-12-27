#ifndef TPPOO_APARELHO_H
#define TPPOO_APARELHO_H

#include <string>
#include "../Zonas/zona.h"

class Aparelho {
private:
   bool ligado;
   int idAparelho;
   static int nextIdAparelho;
   std::string ultimoComando;
public:
    Aparelho();
    virtual void liga() = 0;
    virtual void desliga() = 0;
    virtual void efeitoLigado(Zona& zona) = 0;
    virtual void efeitoDesligado(Zona& zona) = 0;


    bool estaLigado() const;
    void setLigado(bool estado);
    int getIdAparelho() const;
    //virtual std::string getNome() const = 0;
};

#endif //TPPOO_APARELHO_H
