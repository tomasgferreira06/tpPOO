#ifndef TPPOO_REGRA_H
#define TPPOO_REGRA_H

#include <string>
using namespace std;

class Regra {
private:
    string sensorId;
    string tipoComparacao;
    double valorComparacao;

public:
    Regra(const string& sensorId, const string& tipoComparacao, double valorComparacao);
    ~Regra();

    bool avaliar(double valorSensor) const;
};

#endif // TPPOO_REGRA_H
