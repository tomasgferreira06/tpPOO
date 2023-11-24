

#ifndef TPPOO_INTERFACE_H
#define TPPOO_INTERFACE_H
#include "../lib/Terminal.h"


#include <string>

class Interface {
public:
    Interface();
   // ~Interface();
    void iniciar(); // Inicia o loop de interação com o usuário
private:
    term::Window mainWindow;
    term::Window com_efetuadosWindow; // Declare the additional window here
    void processarComando(const std::string& comando);
    void avancarTempo(int n);
    void executarArquivoComandos(const std::string& nomeArquivo);

};


#endif //TPPOO_INTERFACE_H
