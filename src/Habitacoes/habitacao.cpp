#include "habitacao.h"
#include "../../lib/Terminal.h"

using namespace term;



Habitacao::Habitacao(int linhas , int colunas )
        : grelhaZonas(linhas, std::vector<Zona*>(colunas, nullptr)),
          contadorZona(0) {

}


Habitacao::~Habitacao() {
    removerHabitacao();
}


void Habitacao::criarHabitacao(int linhas, int colunas) {

    for (auto* window : windows) {
        delete window;
    }
    windows.clear();


    int larguraWindow = 23;
    int alturaWindow = 7;


    int espacoHorizontal = 5;
    int espacoVertical = 2;


    int offsetY = 5;

    for (int i = 0; i < linhas * colunas; ++i) {
        int x = (i % colunas) * (larguraWindow + espacoHorizontal);
        int y = offsetY + (i / colunas) * (alturaWindow + espacoVertical);


        auto* novaWindow = new term::Window(
                term::Terminal::instance().create_window(x, y, larguraWindow, alturaWindow, true)
        );


        windows.push_back(novaWindow);
    }
}

void Habitacao::removerHabitacao() {

    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            delete zona;
            zona = nullptr;
        }
        linha.clear();
    }
    grelhaZonas.clear();


    for (auto* window : windows) {
        delete window;
    }
    windows.clear();
}



bool Habitacao::criarZona(int linha, int coluna) {
    if (linha >= 0 && linha < grelhaZonas.size() && coluna >= 0 && coluna < grelhaZonas[linha].size() && grelhaZonas[linha][coluna] == nullptr) {
        Zona* novaZona = new Zona();
        grelhaZonas[linha][coluna] = novaZona;
        int index = linha * grelhaZonas[0].size() + coluna;
        if (index < windows.size()) {
            windows[index]->clear();
            *windows[index] << term::move_to(1, 1) << "ID:" << contadorZona;
        }
        contadorZona++;
        return true;
    }
    return false;
}









