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
    }else if (acao == "exec") {
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



