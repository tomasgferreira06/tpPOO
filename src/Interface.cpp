#include "Interface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Habitacoes/habitacao.h"

using namespace std;


Interface::Interface()
        : mainWindow(term::Terminal::instance().create_window(0, 0, term::Terminal::getNumCols(), term::Terminal::getNumRows() - 37, true)),
          com_efetuadosWindow(term::Terminal::instance().create_window(127, 3, 29, term::Terminal::getNumRows()-3, true)),
          flagHabitacao(false)
          {

    mainWindow << "Escreva comando ou 'sair' para terminar: ";


    com_efetuadosWindow << "Comandos efetuados:";
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
        mainWindow << "Escreva comando ou 'sair' para terminar (help ou help2 para lista de comandos): " << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
            avancarTempo(1);
        }
    }else if (acao == "avanca") {
        int n;
        string extra;
        if (stream >> n) {
            if (stream >> extra) {
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'avanca' requer apenas um argumento." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            } else {
                mainWindow.clear();
                avancarTempo(n);
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
            com_efetuadosWindow << "Erro: o comando 'help' não requer argumentos para mostrar os comandos"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    com_efetuadosWindow << "Erro: o comando 'zrem' requer um ID de zona válido." << term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                com_efetuadosWindow << "Comando valido, ainda nao implementado"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);

            }
        } else if (acao == "zcomp") {
            int idZona;
            if (stream >> idZona) {
                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'zcomp' requer apenas o ID da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Listagem de componentes para a zona " << idZona << " ainda nao foi implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    mainWindow.clear();
                    com_efetuadosWindow << "Listagem de Propriedades para a zona " << idZona << " ainda nao foi implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else {
                // Falta ID ou não é um inteiro
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'zcomp' requer um ID numérico(inteiro) da zona."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    mainWindow.clear();
                    com_efetuadosWindow << "Modificacao de uma propriedade ainda nao foi implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
            std::string tipoOuComando;

            if (stream >> idZona >> tipoComponente >> tipoOuComando) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow
                            << "Erro: o comando 'cnovo' requer apenas ID da zona, tipo de componente (s, p, a) e tipo/comando."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {

                    if (tipoComponente == 's' || tipoComponente == 'p' || tipoComponente == 'a') {
                        //Comando válido
                        if(tipoComponente == 's'){
                            minhaHabitacao.adicionarSensor(idZona,tipoOuComando);
                        }
                        mainWindow.clear();
                        com_efetuadosWindow << "Adicao de um novo componente ainda nao foi implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Tipo de componente invalido (deve ser 's', 'p' ou 'a')."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                        //Comando válido
                        mainWindow.clear();
                        com_efetuadosWindow << "Remocao de componente ainda não implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: Tipo de componente invalido (deve ser 's', 'p' ou 'a')."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                //Faltam parâmetros ou são a mais
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'crem' requer um ID numerico da zona, um tipo de componente (s, p, a) e um ID do componente."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "rnova") {
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
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: o comando 'rnova' para a regra '" << regra << "' requer um parametro numérico."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        return;
                    }
                } else if (regra == "entre" || regra == "fora") {
                    precisaSegundoParam = true;
                    if (!(stream >> param1 >> param2)) {
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: o comando 'rnova' para a regra '" << regra<< "' requer dois parametros numericos."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        return;
                    }
                    temSegundoParam = true;
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: Tipo de regra '" << regra << "' nao reconhecido."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    return;
                }

                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'rnova' possui parametros extras nao reconhecidos."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    return;
                }
                mainWindow.clear();
                //Comando válido
                com_efetuadosWindow << "Criação de nova regra ainda não implementada.";
            } else {
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'rnova' nao possui os parametros corretos ou estao em formato invalido."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    if (novoComando.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o novo comando deve ser uma unica palavra."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        //Comando válido
                        com_efetuadosWindow << "Mudança de comando do processador ainda nao implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    mainWindow.clear();
                    com_efetuadosWindow << "Listagem de regras ainda nao implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    com_efetuadosWindow
                            << "Erro: o comando 'rrem' requer apenas o ID da zona, o ID do processador de regras e o ID da regra."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    com_efetuadosWindow << "Remoção da regra ainda nao implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    com_efetuadosWindow
                            << "Erro: o comando 'asoc' requer apenas o ID da zona, o ID do processador de regras e o ID do aparelho."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    com_efetuadosWindow << "Associacao entre processador de regras e aparelho ainda nao implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    com_efetuadosWindow
                            << "Erro: o comando 'ades' requer apenas o ID da zona, o ID do processador de regras e o ID do aparelho."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    // Comando válido
                    com_efetuadosWindow
                            << "Remocao de associacao entre processador de regras e aparelho ainda nao implementada."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'ades' requer um ID numerico da zona, um ID numerico do processador de regras e um ID numerico do aparelho."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "acom") {
            int idZona;
            int idAparelho;
            string com;

            if (stream >> idZona >> idAparelho >> com) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow
                            << "Erro: o comando 'acom' requer apenas o ID da zona, o ID do aparelho e o comando a ser enviado."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    if (com.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o comando para o aparelho deve ser uma unica palavra."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        // Comando válido
                        com_efetuadosWindow << "Envio de comando para aparelho ainda nao implementado."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'acom' requer um ID numerico da zona, um ID numerico do aparelho e um comando."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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
                    com_efetuadosWindow
                            << "Erro: o comando 'psalva' requer apenas o ID da zona, o ID do processador de regras e um nome único."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    if (nome.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o nome deve ser uma unica palavra sem espacos."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        // Comando válido
                        com_efetuadosWindow << "Save do estado do processador de regras ainda nao foi implementado."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow
                        << "Erro: o comando 'psalva' requer um ID numerico da zona, um ID numerico do processador de regras e um nome unico."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else if (acao == "prepoe") {
            string nome;

            if (stream >> nome) {
                string extra;
                if (stream >> extra) {
                    // Parâmetros a mais
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'prepoe' requer apenas um nome unico."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    if (nome.find(' ') != string::npos) {
                        com_efetuadosWindow << "Erro: o nome deve ser uma unica palavra sem espacos."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        // Comando válido
                        com_efetuadosWindow << "Restauro do processador de regras ainda nao implementado."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    }
                }
            } else {
                // Parâmetros em falta ou não estão no formato pretendido
                mainWindow.clear();
                com_efetuadosWindow << "Erro: o comando 'prepoe' requer um nome único para o estado salvo."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
            }
        } else {
            if (acao == "prem") {
                string nome;

                if (stream >> nome) {
                    string extra;
                    if (stream >> extra) {
                        // Parâmetros a mais
                        mainWindow.clear();
                        com_efetuadosWindow << "Erro: o comando 'prem' requer apenas um nome unico."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                    } else {
                        if (nome.find(' ') != string::npos) {
                            com_efetuadosWindow << "Erro: o nome deve ser uma unica palavra sem espacos."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        } else {
                            // Comando válido
                            com_efetuadosWindow << "Apaga uma cópia do processador de regras armazenado em memória."<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                        }
                    }
                }
            } else if (acao == "plista") {
                string extra;
                if (stream >> extra) {
                    mainWindow.clear();
                    com_efetuadosWindow << "Erro: o comando 'plista', nao requer parametros adicionais"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
                } else {
                    mainWindow.clear();
                    com_efetuadosWindow << "Comando válido:"<< term::move_to(0, com_efetuadosWindow.get_current_row() + 1);
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





