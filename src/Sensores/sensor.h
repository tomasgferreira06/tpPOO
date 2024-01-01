    #ifndef TPPOO_SENSOR_H
    #define TPPOO_SENSOR_H

    #include <string>
    #include "../Propriedades/propriedade.h"

    class Zona;

    class Sensor {
    private:
        Zona* zonaAssociada_;
        int idSensor;
        static int nextIdSensor;



    public:


        Sensor(Zona *z);
        int getIdSensor() const;
        virtual std::string getInfo() const = 0;
        virtual double getValor() const = 0;
        Zona *getZonaAssociada() const;
        virtual std::string getTipoSensor() const = 0;
        virtual ~Sensor() = default;






    };

    #endif //TPPOO_SENSOR_H
