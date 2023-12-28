#ifndef ZONA_H
#define ZONA_H

#include <vector>
#include "../../lib/Terminal.h"
#include <vector>
#include <map>
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
    std::map<std::string, Propriedade*> propriedades;  // Map to store property name and pointer





public:

    Zona(int id, term::Window* win);


    ~Zona();
    int getId() const;



    Processador* encontrarProcessadorPorId(int idProcRegras);
    Sensor* encontrarSensorPorId(int idSensor);
    Aparelho* encontrarAparelhoPorId(int idAparelho);
    bool removerProcessador(int idProcessador);
    void adicionarSensor(char tipo);
    void adicionarAparelho(Zona* zona,char tipo);
    bool removerSensor(int idSensor);
    bool removerAparelho(int idAparelho);
    void adicionarProcessador(Processador* processador);
    void adicionarPropriedade(Propriedade* propriedade);
    Propriedade* getPropriedade(const std::string& nome);
    void acionaAparelho(char id, bool ligar);
    term::Window* getJanela() const {
        return window;
    }

    string listarSensores() const;

    void limparZona();


    int getSensoresNum() const;
    int getAparelhosNum() const;
    int getProcessadoresNum() const;

    const vector<Sensor *> &getSensores() const;
    const vector<Aparelho *> &getAparelhos() const;

    const map<std::string, Propriedade *> &getPropriedades() const;
    const vector<Processador *> &getProcessadores() const;


};

#endif // ZONA_H
