#ifndef ZONA_H
#define ZONA_H

#include <vector>
#include "../../lib/Terminal.h"
#include <vector>
#include "../Sensores/sensor.h"
#include "../Aparelhos/aparelho.h"
#include "../Processadores/processador.h"
#include "../Propriedades/propriedade.h"




class Zona {

private:
    int id;
    term::Window* window;
    std::vector<Sensor*> sensores;
    std::vector<Aparelho*> aparelhos;
    std::vector<Processador*> processadores;
    std::vector<Propriedade*> propriedades;// Adicionando um ponteiro para Window
public:

    Zona(int id, term::Window* win)
            : id(id), window(win) {
    }


    ~Zona();
    int getId() const;
    void adicionarSensor(Sensor *sensor);
    void adicionarAparelho(Aparelho* aparelho);
    void adicionarProcessador(Processador* processador);
    void adicionarPropriedade(Propriedade* propriedade);
    term::Window* getJanela() const {
        return window;
    }


    void limparZona();




};

#endif // ZONA_H
