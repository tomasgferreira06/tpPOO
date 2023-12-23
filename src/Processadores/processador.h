#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include "../Regras/regra.h"
#include "../Aparelhos/aparelho.h"
#include <string>

using namespace std;


class Processador {
private:
    vector<Regra *> regras;
    Aparelho * aparelhoAssociado;

public:
    Processador(Aparelho* aparelho);
    void adicionarRegra(Regra * regra);
    void processar(double valorSensor);
};

#endif // TPPOO_PROCESSADOR_H