#include "Interface.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


Interface::Interface()
        : mainWindow(term::Terminal::instance().create_window(0, 0, term::Terminal::getNumCols(), term::Terminal::getNumRows() - 37, true)),
          com_efetuadosWindow(term::Terminal::instance().create_window(0, 20, 156, 20, true)) {

    mainWindow << "Escreva comando ou 'sair' para terminar: ";

    com_efetuadosWindow << "Comandos efetuados:";
}


void Interface::iniciar() {
    string comando;
    while (true) {
        mainWindow >> comando;  // Recebendo entrada do usuário

        if (comando == "sair") {
            break;
        }

        processarComando(comando);
        mainWindow << "Escreva comando ou 'sair' para terminar: ";
    }
}


void Interface::processarComando(const string& comando) {
    std::istringstream stream(comando);
    std::string acao;
    stream >> acao;

    if (acao == "prox") {
        mainWindow.clear();
        avancarTempo(1);
    } else if (acao == "avanca") {
        int n;
        if (stream >> n) {
            mainWindow.clear();
            avancarTempo(n);
        } else {
            mainWindow.clear();
            com_efetuadosWindow << "Erro: o comando 'avanca' requer um numero inteiro como argumento.\n";
        }
    }
      else if(acao == "hnova"){
            int numLinhas, numColunas;
            if(stream >> numLinhas >> numColunas){
                string extra;
                if(stream >> extra){
                    // parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'hnova' requer apenas numero de linhas e colunas.";
                }else{
                    //comando válido
                    mainWindow.clear();

                    com_efetuadosWindow << "Habitacao criada com " << numLinhas << " linhas e " << numColunas << " colunas.";
                }
            }else{
                // parâmetros não são inteiros
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'hnova' requer numeros inteiros para linhas e colunas";
            }
      }
      else if(acao == "hrem"){
                string extra;
                if(stream >> extra){
                    //Argumentos a mais
                    com_efetuadosWindow << "Erro: o comando 'hrem' nao requer parametros adicionais";
                }else{

                    com_efetuadosWindow << "Habitacao removida.";
                }
        }
        else if(acao == "znova"){
                int nLinhasZona, nColunasZona;
                if(stream >> nLinhasZona >> nColunasZona){
                    string extra;
                    if(stream >> extra){
                        // parâmetros a mais
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: o comando 'znova' requer apenas numero de linhas e colunas.";
                    }else{
                        //comando válido
                        mainWindow.clear();

                        com_efetuadosWindow << "Zona criada com " << nLinhasZona << " linhas e " << nColunasZona << " colunas.";
                    }
                }else{
                    // parâmetros não são inteiros
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'znova' requer numeros inteiros para linhas e colunas";
                }
        }
        else if(acao == "zrem"){
                int idZona;
                if (stream >> idZona) {
                    string extra;
                    if (stream >> extra) {
                        // Parâmetros a mais
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: o comando 'zrem' requer apenas o ID da zona.";
                    } else {
                        mainWindow.clear();

                        com_efetuadosWindow << "Zona " << idZona << " removida.";
                    }
                } else {
                    // Falta ID ou não é um inteiro
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zrem' requer um ID numérico(inteiro) da zona.";
                }
        }
        else if(acao == "zlista"){
            string extra;
            if(stream >> extra){
                //Parâmetros a mais
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zlista, nao requer parametros adicionais";
            }else{
                mainWindow.clear();

            }
        }
        else if(acao == "zcomp"){
            int idZona;
            if(stream >> idZona){
                string extra;
                if(stream >> extra){
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zcomp' requer apenas o ID da zona.";
                }else{

                    com_efetuadosWindow << "Listagem de componentes para a zona " << idZona << " ainda nao foi implementada.";
                }
            }else{
                // Falta ID ou não é um inteiro
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zcomp' requer um ID numérico(inteiro) da zona.";
            }
        }
        else if(acao == "zprops"){
            int idZona;
            if(stream >> idZona){
                string extra;
                if(stream >> extra){
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zprops' requer apenas o ID da zona.";
                }else{

                    com_efetuadosWindow << "Listagem de Propriedades para a zona " << idZona << " ainda nao foi implementada.";
                }
            }else{
                // Falta ID ou não é um inteiro
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zcomp' requer um ID numérico(inteiro) da zona.";
            }
        }
        else if(acao == "pmod"){
            int idZona, valorPropriedade;
            string nomePropriedade;
            if(stream >> idZona >> nomePropriedade >> valorPropriedade){
                string extra;
                if(stream >> extra){
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'pmod' requer apenas o ID da zona, nome e valor da propriedade.";
                }else{
                    //Comando válido
                    com_efetuadosWindow << "Modificação de uma propriedade ainda não foi implementada.";
                }
            }else{
                // Falta parâmetros ou não estão no formato correto
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'pmod' requer um ID numérico(inteiro) da zona, um nome de uma propriedade e um valor.";
            }
        }
        else if (acao == "cnovo") {
            int idZona;
            char tipoComponente;
            std::string tipoOuComando;

            if (stream >> idZona >> tipoComponente >> tipoOuComando) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'cnovo' requer apenas ID da zona, tipo de componente (s, p, a) e tipo/comando.";
                } else {

                    if (tipoComponente == 's' || tipoComponente == 'p' || tipoComponente == 'a') {
                        //Comando válido
                        com_efetuadosWindow << "Adição de um novo componente ainda nao foi implementada.";
                    } else {
                        com_efetuadosWindow << "Erro: Tipo de componente inválido (deve ser 's', 'p' ou 'a').";
                    }
                }
            } else {
                // Faltam parâmetros ou são inválidos
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'cnovo' requer um ID numerico(inteiro) da zona, um tipo de componente (s, p, a) e um tipo/comando.";
            }
        }
        else if (acao == "crem") {
            int idZona;
            char tipoComponente;
            int idComponente;

            if (stream >> idZona >> tipoComponente >> idComponente) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'crem' requer apenas o ID da zona, tipo de componente (s, p, a) e ID do componente.";
                } else {
                    if (tipoComponente == 's' || tipoComponente == 'p' || tipoComponente == 'a') {
                        //Comando válido
                        com_efetuadosWindow << "Remocao de componente ainda não implementada.";
                    } else {
                        com_efetuadosWindow << "Erro: Tipo de componente invalido (deve ser 's', 'p' ou 'a').";
                    }
                }
            } else {
                //Faltam parâmetros ou são a mais
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'crem' requer um ID numerico da zona, um tipo de componente (s, p, a) e um ID do componente.";
            }
        }
        else if (acao == "rnova") {
            int idZona;
            int idProcRegras;
            string regra;
            int idSensor;
            double param1, param2;
            bool precisaSegundoParam = false;
            bool temSegundoParam = false;

            if (stream >> idZona >> idProcRegras >> regra >> idSensor) {
                // Analisar qual é a regra
                if (regra == "igual_a" || regra == "menor_que" || regra == "maior_que") {
                    if (!(stream >> param1)) {
                        com_efetuadosWindow << "Erro: o comando 'rnova' para a regra '" << regra << "' requer um parametro numérico.";
                        return;
                    }
                } else if (regra == "entre" || regra == "fora") {
                    precisaSegundoParam = true;
                    if (!(stream >> param1 >> param2)) {
                        com_efetuadosWindow << "Erro: o comando 'rnova' para a regra '" << regra << "' requer dois parametros numericos.";
                        return;
                    }
                    temSegundoParam = true;
                } else {
                    com_efetuadosWindow << "Erro: Tipo de regra '" << regra << "' nao reconhecido.";
                    return;
                }

                string extra;
                if (stream >> extra) {
                    com_efetuadosWindow << "Erro: o comando 'rnova' possui parametros extras nao reconhecidos.";
                    return;
                }

                //Comando válido
                com_efetuadosWindow << "Criação de nova regra ainda não implementada.";
            } else {
                com_efetuadosWindow << "Erro: o comando 'rnova' nao possui os parametros corretos ou estao em formato invalido.";
            }
        }
        else if (acao == "pmuda") {
            int idZona;
            int idProcRegras;
            string novoComando;

            if (stream >> idZona >> idProcRegras >> novoComando) {
                std::string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'pmuda' requer apenas o ID da zona, ID do processador de regras e o novo comando.";
                } else {
                    if (novoComando.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o novo comando deve ser uma unica palavra.";
                    } else {
                        //Comando válido
                        com_efetuadosWindow << "Mudança de comando do processador ainda nao implementada.";
                    }
                }
            } else {
                // Faltam parâmetros ou estão no formato incorreto
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'pmuda' requer um ID numerico da zona, um ID do processador de regras e um novo comando.";
            }
        }
        else if (acao == "rlista") {
            int idZona;
            int idProcRegras;

            if (stream >> idZona >> idProcRegras) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'rlista' requer apenas o ID da zona e o ID do processador de regras.";
                } else {
                    // Comando válido
                    com_efetuadosWindow << "Listagem de regras ainda nao implementada.";
                }
            } else {
                // Parâmetros a menos ou inválidos
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'rlista' requer um ID numerico da zona e um ID numerico do processador de regras.";
            }
        }
        else if (acao == "rrem") {
            int idZona;
            int idProcRegras;
            int idRegra;

            if (stream >> idZona >> idProcRegras >> idRegra) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'rrem' requer apenas o ID da zona, o ID do processador de regras e o ID da regra.";
                } else {
                    // Comando válido
                    com_efetuadosWindow << "Remoção da regra ainda nao implementada.";
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'rrem' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico da regra.";
            }
        }
        else if (acao == "asoc") {
            int idZona;
            int idProcRegras;
            int idAparelho;

            if (stream >> idZona >> idProcRegras >> idAparelho) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'asoc' requer apenas o ID da zona, o ID do processador de regras e o ID do aparelho.";
                } else {
                    // Comando válido
                    com_efetuadosWindow << "Associacao entre processador de regras e aparelho ainda nao implementada.";
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'asoc' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico do aparelho.";
            }
        }
        else if (acao == "ades") {
            int idZona;
            int idProcRegras;
            int idAparelho;

            if (stream >> idZona >> idProcRegras >> idAparelho) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'ades' requer apenas o ID da zona, o ID do processador de regras e o ID do aparelho.";
                } else {
                    // Comando válido
                    com_efetuadosWindow << "Remocao de associacao entre processador de regras e aparelho ainda nao implementada.";
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'ades' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico do aparelho.";
            }
        }
        else if (acao == "acom") {
            int idZona;
            int idAparelho;
            string comando;

            if (stream >> idZona >> idAparelho >> comando) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'acom' requer apenas o ID da zona, o ID do aparelho e o comando a ser enviado.";
                } else {
                    if (comando.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o comando para o aparelho deve ser uma unica palavra.";
                    } else {
                        // Comando válido
                        com_efetuadosWindow << "Envio de comando para aparelho ainda nao implementado.";
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'acom' requer um ID numerico da zona, um ID numerico do aparelho e um comando.";
            }
        }
        else if (acao == "psalva") {
            int idZona;
            int idProcRegras;
            string nome;

            if (stream >> idZona >> idProcRegras >> nome) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'psalva' requer apenas o ID da zona, o ID do processador de regras e um nome único.";
                } else {
                    if (nome.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o nome deve ser uma unica palavra sem espacos.";
                    } else {
                        // Comando válido
                        com_efetuadosWindow << "Save do estado do processador de regras ainda nao foi implementado.";
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'psalva' requer um ID numerico da zona, um ID numerico do processador de regras e um nome unico.";
            }
        }
        else if (acao == "prepoe") {
            string nome;

            if (stream >> nome) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'prepoe' requer apenas um nome unico.";
                } else {
                    if (nome.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o nome deve ser uma unica palavra sem espacos.";
                    } else {
                        // Comando válido
                        com_efetuadosWindow << "Restauro do processador de regras ainda nao implementado.";
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'prepoe' requer um nome único para o estado salvo.\n";
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
        mainWindow.clear();
        com_efetuadosWindow << "Erro: Comando invalido.\n";
    }

}


void Interface::avancarTempo(int n) {
    // Implemente a lógica para avançar o tempo aqui
    com_efetuadosWindow << "Tempo avancado em " << n << " instantes.\n";
}



void Interface::executarArquivoComandos(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        mainWindow << "Erro ao abrir o arquivo: " << nomeArquivo << "\n";
        mainWindow << "Verifique se o caminho está correto e se você tem permissão de leitura.\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (!linha.empty()) {
            processarComando(linha);
        }
    }
}





//Interface::~Interface() {
  //  term::Terminal::instance().~Terminal();
//}


