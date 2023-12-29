    #ifndef TPPOO_SENSOR_H
    #define TPPOO_SENSOR_H

    #include <string>
    #include "../Propriedades/propriedade.h"

    class Sensor {
    private:
        int idSensor;
        static int nextIdSensor;

    public:


        Sensor();
        int getIdSensor() const;
        virtual std::string getInfo() const = 0;
        virtual double getValor() const = 0;





};

    #endif //TPPOO_SENSOR_H
