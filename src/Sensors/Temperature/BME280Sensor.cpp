#include <HardwareSerial.h>
#include "BME280Sensor.h"

AirGradient_Internal::Measurement AirGradient_Internal::BME280Sensor::getAvailableMeasurement() const
{
    return Measurement::Temperature | Measurement::Humidity | Measurement::Pressure;
}

bool AirGradient_Internal::BME280Sensor::begin()
{
    _sensor = std::make_unique<Adafruit_BME280>();

    // _sensor->setAccuracy(_accuracy);
    _sensor->begin();
    return _sensor->init();
}

void AirGradient_Internal::BME280Sensor::getData(AirGradient_Internal::SensorData &data) const
{
    // if (!_sensor->readSample())
    // {
    //     Serial.println("Can't read BME sensor data");
    //     return;
    // }
    auto measurement = getCurrentMeasurement();

    // Check if sensor is supposed to provide the Temperature reading
    if (!(measurement & Measurement::Temperature))
    {
        data.TMP = _sensor->readTemperature();
    }

    // Check if sensor is supposed to provide the humidity reading
    if (!(measurement & Measurement::Humidity))
    {
        data.HUM = _sensor->readHumidity();
    }

    // Check if sensor is supposed to provide the presure reading
    if (!(measurement & Measurement::Pressure))
    {
        data.PRE = _sensor->readPressure() / 100;
    }
}
