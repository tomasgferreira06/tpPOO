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
    std::vector<Sensor*> sensores;
    std::vector<Aparelho*> aparelhos;
    std::vector<Processador*> processadores;
    std::vector<Propriedade*> propriedades;

public:
    Zona();
    ~Zona();
    void adicionarSensor(Sensor *sensor);
    void adicionarAparelho(Aparelho* aparelho);
    void adicionarProcessador(Processador* processador);
    void adicionarPropriedade(Propriedade* propriedade);



    void limparZona();




};

#endif // ZONA_H
