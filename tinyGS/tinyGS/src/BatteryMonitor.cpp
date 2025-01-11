#include <Arduino.h>
#include <BatteryMonitor.h>

BatteryMonitor::BatteryMonitor(int analogPinIn, float volCoef)
{
    adcPin = analogPinIn;
    VOLTAGE_ADJUSTMENT_COEFFICIENT = volCoef;
    if (adcPin >= 0 and VOLTAGE_ADJUSTMENT_COEFFICIENT > 0)
    {
        batteryMonitorIsActiveFlag = true;
        pinMode(adcPin, INPUT);
    }
    else
    {
        batteryMonitorIsActiveFlag = false;
    }
}

int BatteryMonitor::getStatus()
{
    if (batteryMonitorIsActiveFlag)
    {
        return analogRead(adcPin);
    }
    else
    {
        return -1;
    }
}

float BatteryMonitor::getVoltage()
{
    if (batteryMonitorIsActiveFlag)
    {
        return 1.00001 * getStatus() * VOLTAGE_ADJUSTMENT_COEFFICIENT;
    }
    else
    {
        return -1.000;
    }
}

boolean BatteryMonitor::isActive()
{
    return batteryMonitorIsActiveFlag;
}