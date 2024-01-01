#include "Interface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Habitacoes/habitacao.h"
#include "Regras/IgualA.h"
#include "Regras/MenorQue.h"

using namespace std;
using namespace term;


Interface::Interface()
        : mainWindow(term::Terminal::instance().create_window(0, 0, term::Terminal::getNumCols(), term::Terminal::getNumRows() - 37, true)),
          com_efetuadosWindow(term::Terminal::instance().create_window(110, 3, 46, term::Terminal::getNumRows()-3, true)),
          habitacaoWindow(term::Terminal::instance().create_window(0, 3, 17, term::Terminal::getNumRows() - 39, false)),
          flagHabitacao(false)
          {



    for(int i=1; i<20; i++) {
        term::Terminal::instance().init_color(i, i, 0);
    }




    mainWindow << set_color(10) << "Escreva comando ou 'sair' para terminar: " << no_color();;
    habitacaoWindow << "Instantes : ";
}

bool Interface::isFlagHabitacao() const {
    return flagHabitacao;
}

void Interface::setFlagHabitacao(bool flagHabitacao) {
    Interface::flagHabitacao = flagHabitacao;
}


void Interface::iniciar() {
    string comando;
    while (true) {;
        mainWindow >> comando;
        if (comando == "sair") {
            break;
        }
        processarComando(comando);
        mainWindow << set_color(10) << "Escreva comando ou 'sair' para terminar (help ou help2 para lista de comandos): " << term::move_to(0, com_efetuadosWindow.get_current_row() + 1) << set_color(0);
    }
}


void Interface::processarComando(const string& comando) {
    std::istringstream stream(comando);
    std::string acao;
    stream >> acao;


    if (!isFlagHabitacao() && acao != "hnova") {
        mainWindow.clear();
        com_efetuadosWindow << "Erro: O primeiro comando a ser executado deve ser: hnova <num linhas> <num colunas>."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        return;
    }


    if (acao == "prox") {
        string extra;

        if(stream >> extra){
            mainWindow.clear();
            com_efetuadosWindow << "Erro: o comando 'prox' nao quer nenhum parametro."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        }else{
            mainWindow.clear();
            minhaHabitacao.avancarInstante();
            com_efetuadosWindow << "Instante avancado para: " << minhaHabitacao.getInstanteAtual() << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            habitacaoWindow.clear();
            habitacaoWindow << "Instantes : " << minhaHabitacao.getInstanteAtual();
        }
    }else if (acao == "avanca") {
        int n;
        string extra;
        if (stream >> n) {
            if (stream >> extra) {
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'avanca' requer apenas um argumento." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            } else {
                for (int i = 0; i < n; ++i) {
                    minhaHabitacao.avancarInstante();
                }
                habitacaoWindow.clear();
                habitacaoWindow << "Instantes : " << minhaHabitacao.getInstanteAtual();
                com_efetuadosWindow << "Instante avancado " << n << " vezes, instante atual: " << minhaHabitacao.getInstanteAtual() << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                mainWindow.clear();

            }
        } else {
            mainWindow.clear();
            com_efetuadosWindow << "Erro: o comando 'avanca' requer um numero inteiro como argumento." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        }
    }

    else if (acao == "help") {
        string extra;
        if (stream >> extra) {
            mainWindow.clear();
            com_efetuadosWindow << "Erro: o comando 'help' nao requer argumentos para mostrar os comandos"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        } else {
            mainWindow.clear();
            com_efetuadosWindow <<"-prox" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-avanca <inteiro>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-hnova <num linhas> <num colunas>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-hrem" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-znova <linha> <coluna>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-zrem <Id da zona >" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-zlista>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-zcomp <ID zona>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-zprops <ID zona>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-pmod <ID zona> <nome> <valor>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-cnovo <idZona> <s ou p ou a> <tipo de comando>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-crem <idZona> <s ou p ou a> <ID>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-rnova <idZona> <ID procedimento de regras> <regra> <ID sensor> [parametros]" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-pmuda <idZona> <ID procedimento de regras> <novo comando>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-rlista <idZona> <ID procedimento de regras>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-rrem <idZona> <ID procedimento de regras> <ID da regra>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-asoc <idZona> <ID procedimento de regras> <ID aparelho>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-ades <idZona> <ID procedimento de regras> <ID aparelho>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        }

    }
    else if (acao == "help2") {
        string extra;
        if (stream >> extra) {
            mainWindow.clear();
            com_efetuadosWindow << "Erro: o comando 'help' não requer argumentos para mostrar os comandos"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        } else {
            mainWindow.clear();
            com_efetuadosWindow <<"-acom <idZona> <ID aparelho> <comando>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-psalva <idZona> <ID procedimento de regras> <nome>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-prepoe <nome>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-prem <nome>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-plista" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-exec <nome do ficheiro>" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-clear" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            com_efetuadosWindow <<"-sair" << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);

        }
    }
    else {
        if (acao == "hnova") {
            int numLinhas, numColunas;
            if (stream >> numLinhas >> numColunas) {
                string extra;
                if (stream >> extra) {
                    // parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'hnova' requer apenas numero de linhas e colunas."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }else if (numLinhas < 2 || numLinhas > 4 || numColunas < 2 || numColunas > 4) {
                    // fora dos limites permitidos
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'hnova' requer que linhas e colunas estejam entre 2 e 4."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    //comando válido
                    mainWindow.clear();
                    setFlagHabitacao(true);
                    minhaHabitacao.criarHabitacao(numLinhas, numColunas);
                    com_efetuadosWindow << "Habitacao criada com " << numLinhas << " linhas e " << numColunas << " colunas."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else {
                // parâmetros não são inteiros
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'hnova' requer numeros inteiros para linhas e colunas"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "hrem") {
            string extra;
            if (stream >> extra) {
                //Argumentos a mais
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'hrem' nao requer parametros adicionais"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            } else {
                minhaHabitacao.removerHabitacao();
                mainWindow.clear();
                com_efetuadosWindow << "Habitacao removida."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                setFlagHabitacao(false);
            }
        } else if (acao == "znova") {
            int LinhaZona, ColunaZona;
            if (stream >> LinhaZona >> ColunaZona) {
                string extra;
                if (stream >> extra) {
                    // parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'znova' requer apenas numero de linhas e colunas."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }else if (LinhaZona < 1 ||LinhaZona > 4 || ColunaZona < 1 || ColunaZona > 4) {
                    // fora dos limites permitidos
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'znova' requer que linhas e colunas estejam entre 2 e 4."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    mainWindow.clear();//comando válido
                    bool sucesso = minhaHabitacao.criarZona(LinhaZona -1, ColunaZona-1 );
                    if (sucesso)
                        com_efetuadosWindow << "Zona criada na " << LinhaZona << " linha e na " << ColunaZona
                                            << " coluna."
                                            << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    else {
                        com_efetuadosWindow << "Falha na criacao da zona "
                                            << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // parâmetros não são inteiros
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'znova' requer numeros inteiros para linhas e colunas"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "zrem") {
            int idZona;
            if (stream >> idZona) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zrem' requer apenas o ID da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    //comando válido
                    mainWindow.clear();
                bool sucesso1 = minhaHabitacao.removerZona(idZona);
                if(sucesso1){
                    com_efetuadosWindow << "Zona " << idZona << " removida."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
                else {
                    com_efetuadosWindow << "Erro: o comando 'zrem' requer um ID de zona valido." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }}
            } else {
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zrem' requer um ID numerico(inteiro) da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "zlista") {
            string extra;
            if (stream >> extra) {
                //Parâmetros a mais
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zlista, nao requer parametros adicionais"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            } else {
                mainWindow.clear();
                minhaHabitacao.listarZonas(com_efetuadosWindow);
            }
        } else if (acao == "zcomp") {
            int idZona;
            if (stream >> idZona) {
                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zcomp' requer apenas o ID da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    minhaHabitacao.listarComponentesZona(idZona,com_efetuadosWindow);
                    mainWindow.clear();
                }
            } else {
                // Falta ID ou não é um inteiro
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zcomp' requer um ID numerico(inteiro) da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "zprops") {
            int idZona;
            if (stream >> idZona) {
                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zprops' requer apenas o ID da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if (zona) {
                        // Itera e exibe as propriedades
                        for (const auto& par : zona->getPropriedades()) {
                            com_efetuadosWindow << par.first << ": " << par.second->getValor()<< " " << par.second->getUnidade() << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        // Zona com o ID fornecido não foi encontrada
                        com_efetuadosWindow << "Erro: Zona com ID " << idZona << " nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }

                    mainWindow.clear();

                }
            } else {
                // Falta ID ou não é um inteiro
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zcomp' requer um ID numerico(inteiro) da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "pmod") {
            int idZona, valorPropriedade;
            string nomePropriedade;
            if (stream >> idZona >> nomePropriedade >> valorPropriedade) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow
                            << "Erro: o comando 'pmod' requer apenas o ID da zona, nome e valor da propriedade."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    //Comando válido
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if (zona) {
                        Propriedade* propriedade = zona->getPropriedade(nomePropriedade);
                        if (propriedade) {
                            if (valorPropriedade >= propriedade->getMin() && (propriedade->getMax() == std::numeric_limits<int>::max() || valorPropriedade <= propriedade->getMax())) {
                                propriedade->setValor(valorPropriedade);
                                com_efetuadosWindow
                                        << "Propriedade " << nomePropriedade << " modificada com sucesso para o valor " << valorPropriedade << "."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                            } else {
                                // Value is not acceptable
                                com_efetuadosWindow
                                        << "Erro: Valor " << valorPropriedade << " nao e aceitavel para a propriedade " << nomePropriedade << "."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                            }
                        } else {
                            // Property does not exist
                            com_efetuadosWindow
                                    << "Erro: Propriedade " << nomePropriedade << " nao existe na zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        // Zona does not exist
                        com_efetuadosWindow
                                << "Erro: Zona com ID " << idZona << " nao encontrada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }

                    mainWindow.clear();
                }
            } else {
                // Falta parâmetros ou não estão no formato correto
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'pmod' requer um ID numerico(inteiro) da zona, um nome de uma propriedade e um valor."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "cnovo") {
            int idZona;
            char tipoComponente;
            string tipoOuComandoStr;

            if (stream >> idZona >> tipoComponente >> tipoOuComandoStr) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'cnovo' requer apenas ID da zona, tipo de componente (s, p, a) e tipo/comando." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    if (tipoComponente == 's' || tipoComponente == 'p' || tipoComponente == 'a') {
                        if ((tipoComponente == 's' || tipoComponente == 'a') && tipoOuComandoStr.length() == 1) {
                            char tipoOuComandoChar = tipoOuComandoStr[0];
                            // Agora você tem um char para 's' e 'p'
                            switch (tipoComponente) {
                                case 's':
                                    if (minhaHabitacao.adicionarSensor(idZona, tipoOuComandoChar)) {
                                        com_efetuadosWindow << "Sensor adicionado com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                    }else{
                                        com_efetuadosWindow << "Erro ao adicionar sensor. Verifique se o tipo e valido e se a zona existe." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                    }
                                    break;
                                case 'a':
                                    if ( minhaHabitacao.adicionarAparelho(idZona, tipoOuComandoChar)) {
                                        com_efetuadosWindow << "Aparelho adicionado com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                    }else{
                                        com_efetuadosWindow << "Erro ao adicionar aparelho. Verifique se o tipo e valido e se a zona existe." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                    }
                                    break;
                                    // Não é necessário um case para 'a', pois já é uma string
                            }
                        } else if (tipoComponente == 'p') {
                            // Para 'a', tipoOuComandoStr já é uma string
                            minhaHabitacao.adicionarProcessador(idZona, tipoOuComandoStr);
                        } else {
                            mainWindow.clear();
                            com_efetuadosWindow << "Erro: o comando para 's' ou 'p' deve ser um unico caractere." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                        mainWindow.clear();
                      //  com_efetuadosWindow << "Adicionado um novo componente." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Tipo de componente invalido (deve ser 's', 'p' ou 'a')." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Faltam parâmetros ou são inválidos
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'cnovo' requer um ID numerico(inteiro) da zona, um tipo de componente (s, p, a) e um tipo/comando."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "crem") {
            int idZona;
            char tipoComponente;
            int idComponente;

            if (stream >> idZona >> tipoComponente >> idComponente) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow
                            << "Erro: o comando 'crem' requer apenas o ID da zona, tipo de componente (s, p, a) e ID do componente."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    if (tipoComponente == 's' || tipoComponente == 'p' || tipoComponente == 'a') {
                        switch(tipoComponente){
                            case 's':
                                    if(minhaHabitacao.removerSensor(idZona, idComponente)){
                                    com_efetuadosWindow << "Sensor removido com sucesso."
                                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                }else{
                                    com_efetuadosWindow << "Sensor nao encontrado."
                                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                }
                                break;
                            case 'a':
                                if(minhaHabitacao.removerAparelho(idZona, idComponente)){
                                    com_efetuadosWindow << "Aparelho removido com sucesso."
                                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                }else{
                                    com_efetuadosWindow << "Aparelho nao encontrado."
                                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                }
                                break;
                            case 'p' :
                                if(minhaHabitacao.removerProcessador(idZona, idComponente)){
                                    com_efetuadosWindow << "Processador removido com sucesso."
                                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                }else{
                                    com_efetuadosWindow << "Processador nao encontrado."
                                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                                }
                                break;


                            default:
                                break;
                        }
                        mainWindow.clear();
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Tipo de componente invalido (deve ser 's', 'p' ou 'a')."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                //Faltam parâmetros ou são a mais
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erros: o comando 'crem' requer um ID numerico da zona, um tipo de componente (s, p, a) e um ID do componente."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        }else if (acao == "rnova") {
            int idZona, idProcRegras, idSensor;
            string regra;
            double param1 = 0, param2 = 0;

            if (stream >> idZona >> idProcRegras >> regra >> idSensor) {
                Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                if (!zona) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Zona nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    return;
                }

                Processador* processador = zona->encontrarProcessadorPorId(idProcRegras);
                Sensor* sensor = zona->encontrarSensorPorId(idSensor);
                if (!processador || !sensor) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Processador ou sensor nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    return;
                }

                Regra* novaRegra = nullptr;
                bool erroParam = false;

                if (regra == "igual_a" || regra == "menor_que" || regra == "maior_que") {
                    if (!(stream >> param1)) {
                        erroParam = true;
                    }
                    if (regra == "igual_a") {
                        novaRegra = new RegraIgualA(sensor, param1);
                    }else if (regra == "menor_que"){
                        novaRegra = new RegraMenorQue(sensor, param1);
                    }
                    // Implemente aqui para "menor_que" e "maior_que"
                } else if (regra == "entre" || regra == "fora") {
                    if (!(stream >> param1 >> param2)) {
                        erroParam = true;
                    }

                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Tipo de regra '" << regra << "' nao reconhecido." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    return;
                }

                if (erroParam) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Parametros incorretos para a regra." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    return;
                }

                if (novaRegra) {
                    processador->adicionarRegra(novaRegra);
                    mainWindow.clear();
                    com_efetuadosWindow << "Regra adicionada com ID: " << novaRegra->getId() << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro ao criar a regra." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else {
                mainWindow.clear();
                com_efetuadosWindow << "Erro: Formato do comando 'rnova' incorreto." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "pmuda") {
            int idZona;
            int idProcRegras;
            string novoComando;

            if (stream >> idZona >> idProcRegras >> novoComando) {
                std::string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow
                            << "Erro: o comando 'pmuda' requer apenas o ID da zona, ID do processador de regras e o novo comando."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    //Comando válido
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if(zona){
                        Processador *processador = zona->encontrarProcessadorPorId(idZona);
                        if(processador){
                            processador->mudarComando(novoComando);
                            mainWindow.clear();
                            com_efetuadosWindow << "Comando do processador mudado para " << novoComando << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }else{
                            mainWindow.clear();
                            com_efetuadosWindow << "Erro: Processador de regras com o ID especificado nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    }else{
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Zona com o id especeficado,nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Faltam parâmetros ou estão no formato incorreto
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'pmuda' requer um ID numerico da zona, um ID do processador de regras e um novo comando."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "rlista") {
            int idZona;
            int idProcRegras;

            if (stream >> idZona >> idProcRegras) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow
                            << "Erro: o comando 'rlista' requer apenas o ID da zona e o ID do processador de regras."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    Processador* processador = nullptr;
                    if (zona) {
                        processador = zona->encontrarProcessadorPorId(idProcRegras);
                    }
                    if (processador) {
                        const auto& regras = processador->getRegras();
                        for (const Regra* regra : regras) {
                            const Sensor* sensor = regra->getSensorAssociado();
                            com_efetuadosWindow << "Regra ID: " << regra->getId() << ", Nome: " << regra->getNomeRegra() << ", Sensor ID: " << sensor->getIdSensor() << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        com_efetuadosWindow << "Erro: Processador de regras nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                    mainWindow.clear();
                }
            } else {
                // Parâmetros a menos ou inválidos
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'rlista' requer um ID numerico da zona e um ID numerico do processador de regras."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "rrem") {
            int idZona;
            int idProcRegras;
            int idRegra;

            if (stream >> idZona >> idProcRegras >> idRegra) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'rrem' requer apenas o ID da zona, o ID do processador de regras e o ID da regra." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if (zona) {
                        Processador* processador = zona->encontrarProcessadorPorId(idProcRegras);
                        if (processador) {
                            processador->removerRegra(idRegra);
                            mainWindow.clear();
                            com_efetuadosWindow << "Regra removida com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        } else {
                            mainWindow.clear();
                            com_efetuadosWindow << "Erro: Processador de regras com o ID especificado nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Zona com o ID especificado não encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'rrem' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico da regra."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "asoc") {
            int idZona;
            int idProcRegras;
            int idAparelho;

            if (stream >> idZona >> idProcRegras >> idAparelho) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'asoc' requer apenas o ID da zona, o ID do processador de regras e o ID do aparelho." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if (zona) {
                        Processador* processador = zona->encontrarProcessadorPorId(idProcRegras);
                        if (processador) {
                            Aparelho* aparelho = zona->encontrarAparelhoPorId(idAparelho);  // Supondo que esta função existe
                            if (aparelho) {
                                processador->associarAparelho(aparelho);
                                mainWindow.clear();
                                com_efetuadosWindow << "Associacao realizada com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                            } else {
                                mainWindow.clear();
                                com_efetuadosWindow << "Erro: Aparelho com o ID especificado nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                            }
                        } else {
                            mainWindow.clear();
                            com_efetuadosWindow << "Erro: Processador de regras com o ID especificado nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Zona com o ID especificado nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'asoc' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico do aparelho."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "ades") {
            int idZona;
            int idProcRegras;
            int idAparelho;

            if (stream >> idZona >> idProcRegras >> idAparelho) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'ades' requer apenas o ID da zona, o ID do processador de regras e o ID do aparelho." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if (zona) {
                        Processador* processador = zona->encontrarProcessadorPorId(idProcRegras);
                        if (processador) {
                            processador->desassociarAparelho(idAparelho);
                            mainWindow.clear();
                            com_efetuadosWindow << "Associacao removida com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        } else {
                            mainWindow.clear();
                            com_efetuadosWindow << "Erro: Processador de regras com o ID especificado não encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Zona com o ID especificado nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'ades' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico do aparelho."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "acom") {
            int idZona, idAparelho;
            string com;

            if (stream >> idZona >> idAparelho >> com) {
                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'acom' requer apenas o ID da zona, o ID do aparelho e o comando a ser enviado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                    if (zona) {
                        Aparelho* aparelho = zona->encontrarAparelhoPorId(idAparelho);
                        if (aparelho) {
                            aparelho->receberComando(com);
                            mainWindow.clear();
                            com_efetuadosWindow << "Comando '" << com << "' enviado para aparelho ID " << idAparelho << " na zona ID " << idZona << "." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        } else {
                            com_efetuadosWindow << "Erro: aparelho com ID " << idAparelho << " nao encontrado na zona ID " << idZona << "." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    } else {
                        com_efetuadosWindow << "Erro: zona com ID " << idZona << " nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                com_efetuadosWindow << "Erro: formato incorreto do comando 'acom'." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "psalva") {
            int idZona;
            int idProcRegras;
            string nome;

            if (stream >> idZona >> idProcRegras >> nome) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'psalva' requer apenas o ID da zona, o ID do processador de regras e um nome unico." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    if (nome.find(' ') != string::npos) {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: o nome deve ser uma unica palavra sem espaços." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else if (minhaHabitacao.nomeJaExiste(nome)) {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Ja existe uma copia salva com o nome '" << nome << "'." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        // Encontre a zona e o processador
                        Zona* zona = minhaHabitacao.encontrarZonaPorId(idZona);
                        if (zona) {
                            Processador* processador = zona->encontrarProcessadorPorId(idProcRegras);
                            if (processador) {
                                minhaHabitacao.salvarProcessador(nome, processador);
                                mainWindow.clear();
                                com_efetuadosWindow << "Estado do processador salvo com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                            } else {
                                mainWindow.clear();
                                com_efetuadosWindow << "Erro: Processador nao encontrado." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                            }
                        } else {
                            mainWindow.clear();
                            com_efetuadosWindow << "Erro: Zona nao encontrada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'psalva' requer um ID numérico da zona, um ID numerico do processador de regras e um nome unico." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        }
        else if (acao == "prepoe") {
            string nome;
            if (stream >> nome) {
                if (minhaHabitacao.processadorSalvoExiste(nome)) {
                    Processador* processadorSalvo = minhaHabitacao.getProcessadorSalvo(nome);
                    Zona* zonaOriginal = processadorSalvo->getZona();

                    if (zonaOriginal && minhaHabitacao.encontrarZonaPorId(zonaOriginal->getId())) {
                        Processador* processadorExistente = zonaOriginal->encontrarProcessadorPorId(processadorSalvo->getIdProcessador());

                        if (processadorExistente) {
                            // Remova todas as regras do processador existente antes de substituí-lo
                            processadorExistente->removerTodasRegras();
                            zonaOriginal->removerProcessador(processadorExistente->getIdProcessador());
                        }

                        // Crie uma cópia profunda do processador salvo e adicione na zona
                        Processador* processadorRestaurado = new Processador(*processadorSalvo);
                        zonaOriginal->adicionarProcessador(processadorRestaurado);
                        mainWindow.clear();
                        com_efetuadosWindow << "Processador restaurado com sucesso na Zona ID: " << zonaOriginal->getId() << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: A zona onde a copia foi criada ja foi eliminada." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Nao existe um processador salvo com o nome '" << nome << "'." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else {
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'prepoe' requer um nome como parametro." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "prem") {
            string nome;
            if (stream >> nome) {
                mainWindow.clear();
                minhaHabitacao.removerProcessadorSalvo(nome);
                com_efetuadosWindow << "Processador removido com sucesso." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            } else {
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'prem' requer um nome como parametro." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "plista") {
                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'plista', nao requer parametros adicionais"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else if (acao == "plista") {
                    mainWindow.clear();
                    minhaHabitacao.listarProcessadoresSalvos(com_efetuadosWindow);
                }
            } else if (acao == "exec") {
                string nomeArquivo;
                if (stream >> nomeArquivo) {
                    executarFicheiroComandos(nomeArquivo);
                } else {
                    mainWindow << "Erro: o comando 'exec' requer o nome de um arquivo como argumento."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else if (acao == "clear") {
                string extra;
                if (stream >> extra) {
                    //Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'clear', nao requer parametros adicionais"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    com_efetuadosWindow.clear();
                    mainWindow.clear();
                    com_efetuadosWindow << "Comandos efetuados:"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else if (acao == "exit") {
                string extra;
                if (stream >> extra) {
                    //Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'exit', nao requer parametros adicionais"
                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Comando validado com sucesso"
                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else {
                if (acao == "exec") {
                    string nomeFicheiro;
                    if (stream >> nomeFicheiro) {
                        executarFicheiroComandos(nomeFicheiro);
                    } else {
                        mainWindow << "Erro: o comando 'exec' requer o nome de um arquivo como argumento."
                                   << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Comando invalido."
                                        << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            }

            }
        }

void Interface::avancarTempo(int n) {
    com_efetuadosWindow << "Tempo avancado em " << n << " instantes."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
}


void Interface::executarFicheiroComandos(const std::string& nomeFicheiro) {
    std::ifstream ficheiro(nomeFicheiro);
    if (!ficheiro) {
        com_efetuadosWindow << "Erro ao abrir o arquivo: " << nomeFicheiro << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        com_efetuadosWindow << "Verifique se o caminho está correto e se você tem permissão de leitura."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
        return;
    }

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        if (!linha.empty()) {
            processarComando(linha);
        }
    }
}





