#ifndef TPPOO_APARELHO_H
#define TPPOO_APARELHO_H

#include <string>

class Aparelho {
private:
   bool ligado;
   char id;
public:
    Aparelho(char id);
    virtual void liga() = 0;
    virtual void desliga() = 0;
    virtual ~Aparelho() {}

    bool estaLigado() const;
    void setLigado(bool estado);
    char getId() const;

};
#endif //TPPOO_APARELHO_H
