

#ifndef TPPOO_INTERFACE_H
#define TPPOO_INTERFACE_H
#include "../lib/Terminal.h"
#include "Habitacoes/habitacao.h"


#include <string>

class Interface {
public:
    Interface();
   // ~Interface();
    void iniciar();



    void setFlagHabitacao(bool flagHabitacao);

private:
    term::Window mainWindow;
    term::Window com_efetuadosWindow;
    //term::Window janela_habitacaoWindow;
    Habitacao minhaHabitacao;
    bool flagHabitacao;

public:


    void processarComando(const std::string& comando);
    void avancarTempo(int n);
    void executarFicheiroComandos(const std::string& nomeFicheiro);

    bool isFlagHabitacao() const;
};


#endif //TPPOO_INTERFACE_H
