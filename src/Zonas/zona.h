#ifndef TPPOO_ZONA_H
#define TPPOO_ZONA_H

#include <vector>
#include <memory>


#include "../Sensores/sensor.h"
#include "../Aparelhos/aparelho.h"
#include <vector>

class Zona {

private:
    int id;
    int largura;
    int comprimento;
    std::vector<std::shared_ptr<Aparelho>> componentes;  // Array de componentes


public:
    Zona(int id, int largura, int comprimento);

    // Getters and setters
    int getId() const;
    int getLargura() const;
    int getComprimento() const;
    void addComponente(const std::shared_ptr<Aparelho>& componente);
    void removerComponente(int componenteId);

    // Additional methods and attributes will be added later.
};

#endif //TPPOO_ZONA_H

