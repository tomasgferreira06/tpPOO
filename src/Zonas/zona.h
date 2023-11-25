#ifndef TPPOO_ZONA_H
#define TPPOO_ZONA_H

#include <vector>
#include <memory>


#include "../Sensores/sensor.h"
#include "../Aparelhos/aparelho.h"
#include "../Processadores/processador.h"
#include <vector>

using namespace std;

class Zona {

private:
    int id;
    int largura;
    int comprimento;
    vector<shared_ptr<Aparelho>> aparelhos; // Vetor de aparelhos
    vector<shared_ptr<Sensor>> sensores;   // Vetor de sensores
    vector<shared_ptr<Processador>> processadores; // Vetor de processadores




public:
    Zona(int id, int largura, int comprimento);

    // Getters and setters
    int getId() const;
    int getLargura() const;
    int getComprimento() const;

    // Métodos para gerenciar componentes
    void addAparelho(const shared_ptr<Aparelho>& aparelho);
    void addSensor(const shared_ptr<Sensor>& sensor);
    void addProcessador(const shared_ptr<Processador>& processador);

    void removerAparelho(int idAparelho);
    void removerSensor(int idSensor);
    void removerProcessador(int idProcessador);
};

#endif //TPPOO_ZONA_H

