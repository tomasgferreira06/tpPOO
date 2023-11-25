#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include <memory>

#include "../Regras/regra.h"

class Processador {

private:
    std::vector<std::shared_ptr<Regra>> regras;  // Lista de regras

public:
    Processador();
    void addRegra(const std::shared_ptr<Regra>& regra);
    void processarRegras();

};

#endif //TPPOO_PROCESSADOR_H

