#ifndef TPPOO_HABITACAO_H
#define TPPOO_HABITACAO_H

#include <vector>
#include <memory>
#include "../Zonas/zona.h"
#include "../../lib/Terminal.h"

class Habitacao {

private:
    std::vector<std::vector<Zona*>> grelhaZonas;
    std::vector<term::Window*> windows;
    int contadorZona;
    int instanteAtual;






public:

    Habitacao(int linhas = 2, int colunas = 2);
    ~Habitacao();
    void criarHabitacao(int linhas, int colunas);
    void listarZonas(term::Window& com_efetuadosWindow);
    void adicionarSensor(int idZona, char tipoSensor);
    void adicionarAparelho(int idZona, char tipoAparelho);
    void adicionarProcessador(int idZona, string comando);
    bool removerSensor(int idZona, int idSensor);
    bool removerAparelho(int idZona, int idAparelho);
    bool removerProcessador(int idZona, int idProcessador);
    Zona* encontrarZonaPorId(int idZona);
    void listarComponentesZona(int idZona, term::Window& com_efetuadosWindow);
    bool removerZona(int idZona);
    bool criarZona(int linha, int coluna);
    void removerHabitacao();
   void avancarInstante();

    int getInstanteAtual() const;

};

#endif //TPPOO_HABITACAO_H

