#include "habitacao.h"
#include "../../lib/Terminal.h"

using namespace term;

Habitacao::Habitacao(int linhas, int colunas)
        : grelhaZonas(linhas, std::vector<Zona*>(colunas, nullptr)), contadorZona(0) {}

Habitacao::~Habitacao() {
    removerHabitacao();
}

void Habitacao::criarHabitacao(int linhas, int colunas) {
    // Primeiro, limpe as zonas existentes
    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            delete zona;
        }
        linha.clear();
    }
    grelhaZonas.clear();

    // Configurações de tamanho e espaçamento para as janelas
    int larguraWindow = 23;
    int alturaWindow = 7;
    int espacoHorizontal = 5;
    int espacoVertical = 2;
    int offsetY = 5;

    // Criar as janelas e adicionar à grelha
    for (int i = 0; i < linhas; i++) {
        std::vector<Zona*> linhaZonas;
        for (int j = 0; j < colunas; j++) {
            int x = j * (larguraWindow + espacoHorizontal);
            int y = offsetY + i * (alturaWindow + espacoVertical);

            // Criar e adicionar a janela à grelha
            term::Window* novaWindow = new term::Window(
                    term::Terminal::instance().create_window(x, y, larguraWindow, alturaWindow, true)
            );
            linhaZonas.push_back(new Zona(-1, novaWindow)); // Criar uma Zona vazia
        }
        grelhaZonas.push_back(linhaZonas);
    }
}

void Habitacao::removerHabitacao() {
    // Deletar todas as zonas alocadas na grelha
    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            delete zona;
        }
        linha.clear();
    }
    grelhaZonas.clear();
}

bool Habitacao::criarZona(int linha, int coluna) {
    if (linha >= 0 && linha < grelhaZonas.size() &&
        coluna >= 0 && coluna < grelhaZonas[linha].size() &&
        grelhaZonas[linha][coluna]->getId() == -1) {

        int idZona = contadorZona++; // Novo ID de Zona
        // Criar uma nova Zona associada à janela correspondente
        Zona* novaZona = new Zona(idZona, grelhaZonas[linha][coluna]->getJanela());
        grelhaZonas[linha][coluna] = novaZona;
        term::Window* windowAssociada = grelhaZonas[linha][coluna]->getJanela();
        windowAssociada->clear();
        *windowAssociada << term::move_to(1, 1) << "ID:" << idZona;

        return true;
    }
    return false;
}

bool Habitacao::removerZona(int idZona) {
    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            if (zona->getId() == idZona) {
                // Encontrou a zona com o ID correspondente, agora pode removê-la
                term::Window* windowAssociada = zona->getJanela();
                delete zona;
                zona = new Zona(-1, windowAssociada); // Criar uma Zona vazia no lugar
                windowAssociada->clear();
                return true;
            }
        }
    }
    return false; // Não encontrou uma zona com o ID especificado
}
