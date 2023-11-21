#ifndef TPPOO_REGRA_H
#define TPPOO_REGRA_H

class Regra {
public:
    Regra();
    virtual void aplicarRegra() = 0;  // Pure virtual function for applying the rule
    // Additional methods and attributes will be added later
};

#endif //TPPOO_REGRA_H