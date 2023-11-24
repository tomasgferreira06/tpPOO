#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include "../Regras/regra.h"
#include <string>

using namespace std;


class Processador {
private:
    vector<Regra> regras;
    string comando;

public:
    Processador(const string& comando);
    ~Processador();

    void adicionarRegra(const Regra& regra);
    void removerRegra(int indice);
    void listarRegras() const;

    string acionarComando(double valorSensor) const;
};

#endif // TPPOO_PROCESSADOR_H