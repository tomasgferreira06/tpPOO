#include "habitacao.h"
#include "../../lib/Terminal.h"

using namespace term;

Habitacao::Habitacao(int linhas, int colunas)
        : grelhaZonas(linhas, std::vector<Zona*>(colunas, nullptr)), contadorZona(0), instanteAtual(0) {}

Habitacao::~Habitacao() {
    removerHabitacao();
}

void Habitacao::criarHabitacao(int linhas, int colunas) {
    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            if (zona) {
                delete zona->getJanela(); // Primeiro, deleta a janela associada
                delete zona; // Depois, deleta a zona
                zona = nullptr; // Define como nullptr para evitar referências a memória desalocada
            }
        }
    }
    grelhaZonas.clear(); // Limpa o vetor de linhas
    // Configurações de tamanho e espaçamento para as janelas
    int larguraWindow = 23;
    int alturaWindow = 8;
    int espacoHorizontal = 2;
    int espacoVertical = 1;
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

    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            term::Window* windowAssociada = zona->getJanela();
            delete zona;
            delete windowAssociada;
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
        *windowAssociada << set_color(11)<< "ID:" << idZona;

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

void Habitacao::listarZonas(term::Window& com_efetuadosWindow){
    for (const auto& linha : grelhaZonas) {
        for (const auto& zona : linha) {
            if (zona->getId() != -1) { // Verifique se a zona não está vazia
                term::Window* windowAssociada = zona->getJanela();
                int idZona = zona->getId();
                int numSensores = zona->getSensoresNum();
                int numProcessadores = zona->getProcessadoresNum();
                int numAparelhos = zona->getAparelhosNum();


                // Exibir informações sobre a zona
                com_efetuadosWindow << set_color(2) << "ID da Zona: " << set_color(0)<< idZona << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                com_efetuadosWindow << "Sensores: " << numSensores << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                com_efetuadosWindow << "Processadores: " << numProcessadores << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                com_efetuadosWindow << "Aparelhos: " << numAparelhos << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        }
    }
}

bool Habitacao::adicionarSensor(int idZona, char tipoSensor) {
    // Encontrar a zona com o ID especificado
    Zona* zona = encontrarZonaPorId(idZona);
    if (zona) {
        // Chame a função adicionarSensor da classe Zona
        return zona->adicionarSensor(tipoSensor);
    }
    return false;
}

bool Habitacao::adicionarAparelho(int idZona, char tipoAparelho) {
    // Encontrar a zona com o ID especificado
    Zona* zona = encontrarZonaPorId(idZona);
    if (zona) {
        return zona->adicionarAparelho(zona,tipoAparelho);
    }
    return false;
}

bool Habitacao::adicionarProcessador(int idZona, string comando) {
    Zona* zona = encontrarZonaPorId(idZona);
    if(zona){
        Processador* novoProcessador = new Processador(zona,comando);
        zona->adicionarProcessador(novoProcessador);
        return true;
    }else{
        return false;
    }
}
bool Habitacao::processadorSalvoExiste(const std::string& nome) const {
    return processadoresSalvos.find(nome) != processadoresSalvos.end();
}
Processador* Habitacao::getProcessadorSalvo(const std::string& nome) const {
    auto it = processadoresSalvos.find(nome);
    if (it != processadoresSalvos.end()) {
        return it->second;
    }
    return nullptr;  // Retorna nullptr se o processador com o nome especificado não for encontrado
}


Zona* Habitacao::encontrarZonaPorId(int idZona) {
    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            if (zona && zona->getId() == idZona) {
                return zona;
            }
        }
    }
    return nullptr; // Retorna nullptr se a zona com o ID indicado não for encontrada
}

bool Habitacao::removerSensor(int idZona, int idSensor) {
    Zona *zona = encontrarZonaPorId(idZona);
    if(zona){
        return zona->removerSensor(idSensor);
    }
    return false;
}


void Habitacao::listarComponentesZona(int idZona, term::Window& com_efetuadosWindow){
    for (const auto& linha : grelhaZonas) {
        for (const auto& zona : linha) {
            if (zona->getId() == idZona) {
             //   term::Window* windowAssociada = zona->getJanela();
                com_efetuadosWindow << "Componentes na Zona ID:" << idZona <<term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                int componenteCount = 0;
                for (const auto& sensor : zona->getSensores()) {
                    com_efetuadosWindow <<term::set_color(3) << sensor->getInfo() << set_color(0) <<term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    componenteCount++;
                }
                for (const auto& aparelho : zona->getAparelhos()) {
                    std::string nomeAparelho = " a" + std::to_string(aparelho->getIdAparelho()) + " " + aparelho->getNome() + " ";

                    // Verifica se o aparelho está ligado e converte para maiúsculas ou minúsculas manualmente
                    if (aparelho->estaLigado()) {
                        for (char &c : nomeAparelho) {
                            c = std::toupper(c);
                        }
                    } else {
                        for (char &c : nomeAparelho) {
                            c = std::tolower(c);
                        }
                    }

                    com_efetuadosWindow << term::set_color(3) << nomeAparelho << term::set_color(0) << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    componenteCount++;
                }
                for (const auto& processador : zona->getProcessadores()) {
                   com_efetuadosWindow << term::set_color(3)<< " p" << processador->getIdProcessador() <<" Numero de Regras: " << processador->getRegrasNum();
                    componenteCount++;
                }
        }
    }
}
}

bool Habitacao::removerAparelho(int idZona, int idAparelho) {
    Zona *zona = encontrarZonaPorId(idZona);
    if(zona){
        return zona->removerAparelho(idAparelho);
    }
    return false;
}
bool Habitacao::removerProcessador(int idZona, int idProcessador) {
    Zona *zona = encontrarZonaPorId(idZona);
    if(zona){
        return zona->removerProcessador(idProcessador);
    }
    return false;
}

void Habitacao::avancarInstante() {
    instanteAtual++;
    for (auto& linha : grelhaZonas) {
        for (auto& zona : linha) {
            if (zona) {
                // Atualizar os estados dos aparelhos
                for (auto& processador : zona->getProcessadores()) {
                    processador->avaliarRegras();
                }
                for (auto& aparelho : zona->getAparelhos()) {
                    aparelho->executar();
                }
            }
        }
    }
}

int Habitacao::getInstanteAtual() const {
    return instanteAtual;
}
void Habitacao::salvarProcessador(const std::string& nome, Processador* processadorOriginal) {
    Processador* copiaProcessador = new Processador(*processadorOriginal);
    processadoresSalvos.insert(std::make_pair(nome, copiaProcessador));
}

void Habitacao::removerProcessadorSalvo(const std::string& nome) {
    auto it = processadoresSalvos.find(nome);
    if (it != processadoresSalvos.end()) {
        delete it->second;  // Eliminamos o objeto Processador
        processadoresSalvos.erase(it);  // Removemos a entrada do mapa
    }
}

bool Habitacao::nomeJaExiste(const std::string& nome) const {
    return processadoresSalvos.find(nome) != processadoresSalvos.end();
}
void Habitacao::listarProcessadoresSalvos(term::Window& com_efetuadosWindow) const {
    for (const auto& par : processadoresSalvos) {
        const string& nome = par.first;
        const Processador* processador = par.second;
        if (processador) {
            const Zona* zona = processador->getZona();
            if (zona && zonaExiste(zona->getId())) {
                int idZona = zona->getId();
                int idProcessador = processador->getIdProcessador();
                com_efetuadosWindow << "Nome: " << nome << ", ID do Processador: " << idProcessador << ", ID da Zona: " << idZona << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            } else {
                com_efetuadosWindow << "Zona associada ao processador '" << nome << "' ja nao existe." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        }
    }
}


bool Habitacao::zonaExiste(int idZona) const {
    for (const auto& linhaZonas : grelhaZonas) {
        for (const auto& zona : linhaZonas) {
            if (zona && zona->getId() == idZona) {
                return true;
            }
        }
    }
    return false;
}


