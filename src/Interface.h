

#ifndef TPPOO_INTERFACE_H
#define TPPOO_INTERFACE_H
#include "../lib/Terminal.h"


#include <string>

class Interface {
public:
    Interface();
   // ~Interface();
    void iniciar();
private:
    term::Window mainWindow;
    term::Window com_efetuadosWindow;
    term::Window janela_habitacaoWindow;
    void processarComando(const std::string& comando);
    void avancarTempo(int n);
    void executarArquivoComandos(const std::string& nomeArquivo);

};


#endif //TPPOO_INTERFACE_H
