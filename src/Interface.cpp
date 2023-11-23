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
    else if (acao == "hnova") {
        int linhas;
        int colunas;
        string s = "hnova com linhas , colunas";
        string extra;

        if (stream >> linhas >> colunas) {
            if(stream >> extra){
                mainWindow << "Parâmetro a mais\n";
            }
            else
            mainWindow << "Funcao hnova chamada com sucesso\n";
        }
        else {
            mainWindow << "Erro: o comando 'hnova' requer numero de linhas e colunas.\n";
        }
    }
    else if (acao == "znova") {
        int linhas;
        int colunas;
        string s = "hnova com linhas , colunas";
        string extra;

        if (stream >> linhas >> colunas) {
            if(stream >> extra){
                mainWindow << "Parâmetro a mais\n";
            }
            else
                mainWindow << "Funcao znova chamada com sucesso\n";
        }
        else {
            mainWindow << "Erro: o comando 'znova' requer numero de linhas e colunas.\n";
        }
    }
    else if (acao == "hrem") {
        string extra;
        string s = "Remover uma zona inteira";

        if (stream >> extra){
            mainWindow << "Parametro a mais\n";
        }
        else
            //Chamar a função hrem
            mainWindow << "Funcao hrem chamada com sucesso\n";

    }
    else if (acao == "zrem") {
        int idzona;
        string s = "Eliminar zona com o id";
        string extra;
        if (stream >> idzona) {
            if(stream >> extra){
                mainWindow << "Parametro a mais\n";
            }
            else
                mainWindow << "Funcao zrem chamada com sucesso\n";
        }
        else {
            mainWindow << "Erro: o comando 'zrem' requer id da zona passado como parametro\n";
        }
    }
    else if (acao == "zlista") {
        string extra;
        string s = "Listar todas as zonas de habitacao";

        if (stream >> extra){
            mainWindow << "Parametro a mais\n";
        }
        else
            //Chamar a função hrem
            mainWindow << "Funcao zlista chamada com sucesso\n";

    }

    //Comandos para gerir zonas para baixo, outros para cima

    else if (acao == "zcomp") {
        int idzona;
        string s = "listar os componentes da zona com o id indicado";
        string extra;
        if (stream >> idzona) {
            if(stream >> extra){
                mainWindow << "Parametro a mais\n";
            }
            else
                mainWindow << "Funcao zcomp chamada com sucesso\n";
        }
        else {
            mainWindow << "Erro: o comando 'zcomp' requer id da zona passado como parametro\n";
        }
    }
    else if (acao == "zprops") {
        int idzona;
        string s = "listar as propriedades  da zona com o id indicado";
        string extra;
        if (stream >> idzona) {
            if(stream >> extra){
                mainWindow << "Parametro a mais\n";
            }
            else
                mainWindow << "Funcao zprops chamada com sucesso\n";
        }
        else {
            mainWindow << "Erro: o comando 'zprops' requer id da zona passado como parametro\n";
        }
    }
    else if (acao == "pmod") {
        int idzona;
        int nome;
        int valor;

        string s = "modifica o valor da propriedade";
        string extra;

        if (stream >> idzona >> nome >> valor) {
            if(stream >> extra){
                mainWindow << "Parâmetro a mais\n";
            }
            else
                mainWindow << "Funcao pmod chamada com sucesso\n";
        }
        else {
            mainWindow << "Erro: o comando 'pmod' requer id da zona , nome e valor como parametros\n";
        }
    }
    else if (acao == "cnovo") {
        int idzona;
        char spa;
        string tipoComando;
        string s = "modifica o valor da propriedade";
        string extra;


        if (stream >> idzona >> spa >> tipoComando) {
          if (spa == 'p' ){
                if ( tipoComando != "liga"  || tipoComando != "desliga"){
                    mainWindow << "Erro de sintaxe\n";
                }
                else mainWindow << "Ligou ou desligou\n";
          }
            if (spa == 's' ){
                //aceita string
            }
            if (spa == 'a' ){
                //aceita string
            }
        }
        else {
            mainWindow << "Erro: o comando 'cnovo' requer id da zona , nome e valor como parametros\n";
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