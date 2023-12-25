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
    int temperatura;
    int ruido;
    term::Window* window;
    std::vector<Sensor*> sensores;
    std::vector<Aparelho*> aparelhos;
    std::vector<Processador*> processadores;
    std::vector<Propriedade*> propriedades;

public:

    Zona(int id, term::Window* win)
            : id(id), window(win) {
    }


    ~Zona();
    int getId() const;

    void aumentarTemperatura(int graus);



    void adicionarSensor(string tipo);
    void adicionarAparelho(Aparelho* aparelho);
    void adicionarProcessador(Processador* processador);
    void adicionarPropriedade(Propriedade* propriedade);
    void acionaAparelho(char id, bool ligar);
    term::Window* getJanela() const {
        return window;
    }


    void limparZona();

    int getTemperatura() const;
    int getRuido() const;
    void aumentarRuido(int db);
    void reduzirRuido(int db);
    void setRuido(int novoRuido);
    void setTemperatura(int novaTemperatura);

    int getSensoresNum() const;


};

#endif // ZONA_H
