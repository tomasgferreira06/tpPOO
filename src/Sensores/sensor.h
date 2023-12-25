#ifndef TPPOO_SENSOR_H
#define TPPOO_SENSOR_H

#include <string>
#include "../Propriedades/propriedade.h"

class Sensor {

private:
    std::string id;

public:
    explicit Sensor(const std::string& Id) : id(Id) {}
    virtual ~Sensor() = 0;
    virtual char getLetraVisualizacao() const = 0;
    virtual double lerValor() const = 0;
    void setId(const std::string& newId) { id = newId; } // Setter
    std::string getId() const { return id; } // Getter
};

#endif //TPPOO_SENSOR_H
