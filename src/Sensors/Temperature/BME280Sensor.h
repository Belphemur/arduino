#pragma once

#include <memory>
#include "Sensors/ISensor.h"
#include <Adafruit_BME280.h>

namespace AirGradient_Internal {
    class BME280Sensor : public ISensor {
    public:
        ~BME280Sensor() override = default;


        inline const char *getName() const override {
            return "BME 280";
        }

        bool begin() override;

        void getData(SensorData &data) const override;

        // /**
        //  *
        //  * @param accuracy Accuracy of the sensor (also define how fast does it take to do a reading)
        //  */
        // BME280Sensor(BME280Sensor::BMEAccuracy accuracy) : _accuracy(accuracy) {}
        // Todo : replace by setSampling

        // BME280Sensor() : BME280Sensor(BME280Sensor::BMEAccuracy::BME_ACCURACY_HIGH) {}

    protected:
        Measurement getAvailableMeasurement() const override;

    private:
        // BME280Sensor::BMEAccuracy _accuracy;
        std::unique_ptr<Adafruit_BME280> _sensor;
    };
}
