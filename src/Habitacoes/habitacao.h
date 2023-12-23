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




public:

    Habitacao(int linhas = 2, int colunas = 2);
    ~Habitacao();
    void criarHabitacao(int linhas, int colunas);
    bool criarZona(int linha, int coluna);
    void removerHabitacao();

};

#endif //TPPOO_HABITACAO_H

