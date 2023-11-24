#ifndef ZONA_H
#define ZONA_H

#include <vector>
#include <memory>  // Add this for std::shared_ptr

// Forward declarations
class Aparelho;
class Sensor;
class Processador;

class Zona {
public:
    Zona(int id, int largura, int comprimento);

    int getId() const;
    int getLargura() const;
    int getComprimento() const;

    void addComponente(const std::shared_ptr<Aparelho> &componente);
    void removerComponente(int componenteId);

private:
    int id;
    int largura;
    int comprimento;
    std::vector<std::shared_ptr<Aparelho>> componentes;
};

#endif // ZONA_H
