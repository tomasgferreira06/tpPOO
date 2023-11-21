#include "Interface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>

using namespace std;

Interface::Interface()
        : mainWindow(term::Terminal::instance().create_window(0, 0, 156, 20, true)) {
    // Aqui você pode configurar a janela se necessário
}


void Interface::iniciar() {
    string comando;
    while (true) {
        mainWindow << "Escreva um comando ou 'sair' para terminar: ";
        mainWindow >> comando;  // Recebendo entrada do usuário

        if (comando == "sair") {
            break;
        }

        processarComando(comando);
    }
}


void Interface::processarComando(const string& comando) {
    istringstream stream(comando);
    string acao;
    stream >> acao;

    if (acao == "prox") {
        avancarTempo(1);
    } else if (acao == "avanca") {
        int n;
        if (stream >> n) {
            avancarTempo(n);
        } else {
            mainWindow << "Erro: o comando 'avanca' requer um numero inteiro como argumento.";
        }
    } else if (acao == "hnova") {
        int linhas, colunas;
        if (stream >> linhas >> colunas) {
            criarHabitacao(linhas, colunas);
        } else {
            mainWindow << "Erro: o comando 'hnova' requer dois números inteiros como argumentos.";
        }
    } else if (acao == "hrem") {
        removerHabitacao();
    } else if (acao == "znova") {
        int linha, coluna;
        if (stream >> linha >> coluna) {
            criarZona(linha, coluna);
        } else {
            mainWindow << "Erro: o comando 'znova' requer dois números inteiros como argumentos.\n";
        }
    } else if (acao == "zrem") {
        int idZona;
        if (stream >> idZona) {
            removerZona(idZona);
        } else {
            mainWindow << "Erro: o comando 'zrem' requer um número inteiro como argumento.\n";
        }
    } else if (acao == "zlista") {
        listarZonas();
    } else if (acao == "zcomp") {
        int idZona;
        if (stream >> idZona) {
          //  listarComponentes(idZona);
        } else {
            mainWindow << "Erro: o comando 'zcomp' requer um número inteiro como argumento.\n";
        }
    } else if (acao == "zprops") {
        int idZona;
        if (stream >> idZona) {
          //  listarPropriedades(idZona);
        } else {
            mainWindow << "Erro: o comando 'zprops' requer um número inteiro como argumento.\n";
        }
    } else if (acao == "pmod") {
        int idZona;
        string nome;
        double valor;
        if (stream >> idZona >> nome >> valor) {
            //modificarPropriedade(idZona, nome, valor);
        } else {
            mainWindow << "Erro: o comando 'pmod' requer um número inteiro e um valor como argumentos.\n";
        }
    } else if (acao == "cnovo") {
        int idZona;
        char tipo;
        string especificacao;
        if (stream >> idZona >> tipo >> especificacao) {
           // adicionarComponente(idZona, tipo, especificacao);
        } else {
            mainWindow << "Erro: o comando 'cnovo' requer um número inteiro, um caractere e uma string como argumentos.\n";
        }
    } else if (acao == "crem") {
        int idZona, idComponente;
        char tipo;
        if (stream >> idZona >> tipo >> idComponente) {
           // removerComponente(idZona, tipo, idComponente);
        } else {
            mainWindow << "Erro: o comando 'crem' requer um número inteiro, um caractere e um número inteiro como argumentos.\n";
        }
    }
      else if (acao == "exec") {
        string nomeArquivo;
        if (stream >> nomeArquivo) {
            executarArquivoComandos(nomeArquivo);
        } else {
            mainWindow << "Erro: o comando 'exec' requer o nome de um arquivo como argumento.\n";
        }
    }
    else {
        mainWindow << "Erro: Comando invalido.\n";
    }
}

void Interface::avancarTempo(int n) {
    // Implemente a lógica para avançar o tempo aqui
    mainWindow << "Tempo avancado em " << n << " instantes.\n";
}

// ... (resto do código)

void Interface::criarHabitacao(int linhas, int colunas) {
    // Implemente a lógica para criar uma nova habitação aqui
    mainWindow << "Habitacao criada com " << linhas << " linhas e " << colunas << " colunas.\n";
}

void Interface::removerHabitacao() {
    // Implemente a lógica para remover a habitação aqui
    mainWindow << "Habitacao removida.\n";
}

void Interface::criarZona(int linha, int coluna) {
    // Implemente a lógica para criar uma nova zona aqui
    mainWindow << "Zona criada na posicao [" << linha << ", " << coluna << "].\n";
}

void Interface::removerZona(int idZona) {
    // Implemente a lógica para remover uma zona aqui
    mainWindow << "Zona " << idZona << " removida.\n";
}

void Interface::listarZonas() {
    // Implemente a lógica para listar todas as zonas aqui
    mainWindow << "Listagem de zonas:\n";
    // Aqui você iria iterar sobre a estrutura de dados que contém as zonas e imprimi-las
}



void Interface::executarArquivoComandos(const std::string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        mainWindow << "Erro ao abrir o arquivo: " << nomeArquivo << "\n";
        mainWindow << "Verifique se o caminho está correto e se você tem permissão de leitura.\n";
        return;
    }

    string linha;
    while (std::getline(arquivo, linha)) {
        if (!linha.empty()) {
            processarComando(linha);
        }
    }
}

//Interface::~Interface() {
  //  term::Terminal::instance().~Terminal();
//}



