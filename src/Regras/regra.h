#ifndef TPPOO_REGRA_H
#define TPPOO_REGRA_H

#include <string>
#include "../Sensores/sensor.h"

using namespace std;

class Regra {
private:
    int id;
    static int nextID;
    Sensor *sensorAssociado;
public:
    Regra(Sensor *sensor);
    //virtual ~Regra();
    virtual Regra* duplica() const = 0 ;
    virtual bool avaliar() const = 0;
    int getId() const;
    Sensor *getSensorAssociado() const;

    virtual std::string getNomeRegra() const = 0;
};

#endif // TPPOO_REGRA_H
