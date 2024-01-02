
#include "lampada.h"
#include <sstream>


Lampada::Lampada(Zona *pZona) : Aparelho(pZona), contador(0),adicionouLumens(false) {}

void Lampada::liga(term::Window & com_efetuadosWindow) {
    if(!estaLigado()){
        setLigado(true);
        com_efetuadosWindow << "A lampada "<< getIdAparelho() <<" foi ligada." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Lampada::desliga(term::Window & com_efetuadosWindow) {
    if(estaLigado()){
        setLigado(false);
        com_efetuadosWindow << "A lampada "<< getIdAparelho() <<" foi desligada." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Lampada::executar(term::Window & com_efetuadosWindow) {
    Zona* zona = getZonaAssociada();
    if(zona){
        const std::vector<Sensor*>& sensores = zona->getSensores();
        double luminosidadeAtual = 0.0;
        bool encontrouSensorLuminosidade = false;

        // Procurar pelo sensor de luminosidade
        for (Sensor* sensor : sensores) {
            if (sensor->getTipoSensor() == "Luminosidade") {
                luminosidadeAtual = sensor->getValor();
                encontrouSensorLuminosidade = true;
                break;
            }
        }
        if(estaLigado()){

            com_efetuadosWindow << term::set_color(12)<< "A lampada da zona "<< zona->getId() << " com o id: "<< getIdAparelho() <<" esta ligada." << term::set_color(0) << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
            // Verificar se os lúmens já foram adicionados
            if (!isAdicionouLumens() && encontrouSensorLuminosidade) {
                Propriedade* propLuminosidade = zona->getPropriedade("Luz");
                if (propLuminosidade) {
                    propLuminosidade->setValor(luminosidadeAtual + 900);
                    setAdicionouLumens(true); // dar set a flag para indicar que os lúmens foram adicionados
                }
            }
        }else{
            com_efetuadosWindow << term::set_color(12) << "A lampada da zona " << zona->getId() << " com o id: " << getIdAparelho() <<" esta desligada." <<term::set_color(0) << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
            if(isAdicionouLumens() && encontrouSensorLuminosidade){
                // Remove os lúmens adicionados
                Propriedade* propLuminosidade = zona->getPropriedade("Luz");
                if (propLuminosidade) {
                    propLuminosidade->setValor(std::max(0.0, luminosidadeAtual - 900));
                    setAdicionouLumens(false); // Reseta a flag
                }
            }
        }
    }
}
std::string Lampada::getNome() const{
    std::ostringstream ss;
    ss << "Lampada " << getUltimoComando();
    return ss.str();
}

int Lampada::getContador() const {
    return contador;
}

void Lampada::setContador(int contador) {
    Lampada::contador = contador;
}

bool Lampada::isAdicionouLumens() const {
    return adicionouLumens;
}

void Lampada::setAdicionouLumens(bool adicionouLumens) {
    Lampada::adicionouLumens = adicionouLumens;
}
