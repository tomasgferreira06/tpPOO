
#include "refrigerador.h"
#include "aparelho.h"

#include <sstream>


Refrigerador::Refrigerador(Zona *pZona) : Aparelho(pZona), contador(0) {}

void Refrigerador::liga() {
    if(!estaLigado()){
        setLigado(true);
    }
}

void Refrigerador::desliga() {
    if(estaLigado()){
        setLigado(false);
    }
}

void Refrigerador::executar() {
    Zona *zona = getZonaAssociada();
    if(zona){
        const vector<Sensor*>& sensores  = zona->getSensores();
        double temperaturaAtual = 0.0;
        double somAtual = 0.0;
        bool encontrouSensorTemperatura = false;
        bool encontrouSensorSom = false;

        for(Sensor *sensor : sensores){
            if(sensor->getTipoSensor() == "Temeperatura"){
                temperaturaAtual = sensor->getValor();
                encontrouSensorTemperatura = true;
            }else if(sensor->getTipoSensor() == "Som"){
                somAtual = sensor->getValor();
                encontrouSensorSom = true;
            }
        }

        if(estaLigado()){
            // Adicionar 20 dB de ruído uma única vez ao ligar o refrigerador
            if(contador == 0 && encontrouSensorSom){
                Propriedade *propSom = zona->getPropriedade("Som");
                if(propSom){
                    propSom->setValor(somAtual + 20);
                }
            }

            contador++;
            if(contador % 3 == 0 && encontrouSensorTemperatura){
                Propriedade *propTemp = zona->getPropriedade("Temperatura");
                if(propTemp){
                    propTemp->setValor(temperaturaAtual - 1);
                }
            }
        }else {
            // Remover 20 dB de ruído quando o refrigerador é desligado e esta é a primeira ação pós desligamento
            if (contador == 0 && encontrouSensorSom && !estaLigado()) {
                Propriedade* propSom = zona->getPropriedade("Som");
                if (propSom) {
                    propSom->setValor(std::max(0.0, somAtual - 20)); // Garante que o som não fique negativo
                }
            }
            contador = 0; // Resetar o contador quando o refrigerador é desligado
        }
    }
}



std::string Refrigerador::getNome() const{
    std::ostringstream ss;
    ss << "Refrigerador" << getUltimoComando();
    return ss.str();
}
