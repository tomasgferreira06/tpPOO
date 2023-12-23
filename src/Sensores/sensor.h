#ifndef TPPOO_SENSOR_H
#define TPPOO_SENSOR_H

#include <string>
#include "../Propriedades/propriedade.h"

class Sensor {
public:
    virtual ~Sensor() = 0;
    virtual char getLetraVisualizacao() const = 0;
    virtual double lerValor() const = 0;
};

#endif //TPPOO_SENSOR_H
