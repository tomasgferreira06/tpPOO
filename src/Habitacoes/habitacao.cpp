#include "habitacao.h"
#include "../../lib/Terminal.h"


Habitacao::Habitacao() {}


void Habitacao::criarHabitacao(int linhas, int colunas) {
    int larguraJanela = 10;
    int alturaJanela = 10;
    int espaco = 2;  // Espaço entre as janelas
    int xInicial = 4, yInicial = 4;  // Posição inicial

    grelhaWindows.resize(linhas);
    for (int i = 0; i < linhas; ++i) {
        grelhaWindows[i].reserve(colunas); // Reserve espaço para colunas
        for (int j = 0; j < colunas; ++j) {
            int x = xInicial + j * (larguraJanela + espaco);
            int y = yInicial + i * (alturaJanela + espaco);
            grelhaWindows[i].push_back(term::Terminal::instance().create_window(x, y, larguraJanela, alturaJanela, true));
        }
    }
}





