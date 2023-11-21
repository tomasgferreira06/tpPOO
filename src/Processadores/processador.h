#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include <memory>

#include "../Regras/regra.h"

class Processador {


private:

    std::vector<std::shared_ptr<Regra>> regras;  // List of rules



public:
    Processador();
    void addRegra(const std::shared_ptr<Regra>& regra);
    void processarRegras();  // Process all rules
    // Additional methods and attributes will be added later.
};

#endif //TPPOO_PROCESSADOR_H

