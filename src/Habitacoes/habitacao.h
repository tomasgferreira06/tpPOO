#ifndef TPPOO_HABITACAO_H
#define TPPOO_HABITACAO_H

#include <vector>
#include "../Zonas/zona.h"

class Habitacao {

private:
    std::vector<std::vector<Zona>> grelha; // Grelha para zonas

public:
    Habitacao();
    void criarHabitacao(int linhas, int colunas); // Cria uma nova habitação
};

#endif //TPPOO_HABITACAO_H

