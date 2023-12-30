
#include "lampada.h"
#include <sstream>


Lampada::Lampada(Zona *pZona) : Aparelho(pZona), contador(0),adicionouLumens(false) {}

void Lampada::liga() {
    if(!estaLigado()){
        setLigado(true);
    }
}

void Lampada::desliga() {
    if(estaLigado()){
        setLigado(false);
    }
}
void Lampada::executar() {
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
            // Verifica se os lúmens já foram adicionados
            if (!adicionouLumens && encontrouSensorLuminosidade) {
                Propriedade* propLuminosidade = zona->getPropriedade("Luminosidade");
                if (propLuminosidade) {
                    propLuminosidade->setValor(luminosidadeAtual + 900);
                    adicionouLumens = true; // Seta a flag para indicar que os lúmens foram adicionados
                }
            }
        }else{
            if(adicionouLumens && encontrouSensorLuminosidade){
                // Remove os lúmens adicionados
                Propriedade* propLuminosidade = zona->getPropriedade("Luminosidade");
                if (propLuminosidade) {
                    propLuminosidade->setValor(std::max(0.0, luminosidadeAtual - 900));
                    adicionouLumens = false; // Reseta a flag
                }
            }
        }
    }
}
std::string Lampada::getNome() const{
    std::ostringstream ss;
    ss << "Lampada" << getUltimoComando();
    return ss.str();
}
