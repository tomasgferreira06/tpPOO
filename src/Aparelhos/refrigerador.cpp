
#include "refrigerador.h"
#include "aparelho.h"

#include <sstream>


Refrigerador::Refrigerador(Zona *pZona) : Aparelho(pZona), contador(0), somAumentado(false), desligadoRecentemente(false){}

void Refrigerador::liga(term::Window & com_efetuadosWindow) {
    if(!estaLigado()){
        setLigado(true);
        com_efetuadosWindow << "O refrigerador foi ligado." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Refrigerador::desliga(term::Window & com_efetuadosWindow) {
    if(estaLigado()){
        setLigado(false);
        com_efetuadosWindow << "O refrigerador foi desligado." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Refrigerador::executar(term::Window & com_efetuadosWindow) {
    Zona *zona = getZonaAssociada();
    if(zona){
        const vector<Sensor*>& sensores  = zona->getSensores();
        double temperaturaAtual = 0.0;
        double somAtual = 0.0;
        bool encontrouSensorTemperatura = false;
        bool encontrouSensorSom = false;

        for(Sensor *sensor : sensores){
            if(sensor->getTipoSensor() == "Temperatura"){
                temperaturaAtual = sensor->getValor();
                encontrouSensorTemperatura = true;
            }else if(sensor->getTipoSensor() == "Som"){
                somAtual = sensor->getValor();
                encontrouSensorSom = true;
            }
        }

        if(estaLigado()){
            // Adicionar 20 dB de ruído uma única vez ao ligar o refrigerador
            if(getContador() == 0 && encontrouSensorSom){
                Propriedade *propSom = zona->getPropriedade("Som");
                if(propSom){
                    propSom->setValor(somAtual + 20);
                    setSomAumentado(true);
                }
            }

            setContador(getContador() + 1);
            if(getContador() % 3 == 0 && encontrouSensorTemperatura){
                Propriedade *propTemp = zona->getPropriedade("Temperatura");
                if(propTemp){
                    propTemp->setValor(temperaturaAtual - 1);
                }
            }
        }else {
            setContador(0);
            // Remover 20 dB de ruído quando o refrigerador é desligado e esta é a primeira ação apos o desligarmos
            if (getContador() > 0 && encontrouSensorSom && !estaLigado()) {
                Propriedade* propSom = zona->getPropriedade("Som");
                if (propSom) {
                    propSom->setValor(std::max(0.0, somAtual - 20)); // Garantir que o som não fique negativo
                    setSomAumentado(false);
                }
            }
            setContador(0); // Resetar o contador quando o refrigerador é desligado
        }
    }
}



std::string Refrigerador::getNome() const{
    std::ostringstream ss;
    ss << "Refrigerador" << getUltimoComando();
    return ss.str();
}

int Refrigerador::getContador() const {
    return contador;
}

void Refrigerador::setContador(int contador) {
    Refrigerador::contador = contador;
}

bool Refrigerador::isSomAumentado() const {
    return somAumentado;
}

void Refrigerador::setSomAumentado(bool somAumentado) {
    Refrigerador::somAumentado = somAumentado;
}

bool Refrigerador::isDesligadoRecentemente() const {
    return desligadoRecentemente;
}

void Refrigerador::setDesligadoRecentemente(bool desligadoRecentemente) {
    Refrigerador::desligadoRecentemente = desligadoRecentemente;
}
