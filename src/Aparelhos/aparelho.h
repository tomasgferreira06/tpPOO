#ifndef TPPOO_APARELHO_H
#define TPPOO_APARELHO_H

#include <string>

class Aparelho {
private:
   bool ligado;
   int idAparelho;
   static int nextIdAparelho;
public:
    Aparelho();
    virtual void liga() = 0;
    virtual void desliga() = 0;


    bool estaLigado() const;
    void setLigado(bool estado);
    int getIdAparelho() const;

};
#endif //TPPOO_APARELHO_H
