#ifndef TPPOO_HABITACAO_H
#define TPPOO_HABITACAO_H

#include <vector>
#include "../Zonas/zona.h"
#include "../../lib/Terminal.h"

class Habitacao {

private:
    std::vector<std::vector<term::Window>> grelhaWindows;
    std::vector<std::vector<Zona>> grelha; // Grelha para zonas


public:
    Habitacao();
    void criarHabitacao(int linhas, int colunas);

};

#endif //TPPOO_HABITACAO_H

