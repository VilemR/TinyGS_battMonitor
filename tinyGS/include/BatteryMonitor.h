#ifndef BATMON_H
#define BATMON_H

#include <Arduino.h>

class BatteryMonitor
{
public:
    int adcPin;
    float VOLTAGE_ADJUSTMENT_COEFFICIENT = 1.0001;
    boolean batteryMonitorIsActiveFlag = false;

    // new BatteryMonitor(advancedConf.adcVoltIntPIN,advancedConf.volCoefInt);
    BatteryMonitor(int analogPinIn, float volCoef);
    int getStatus();
    float getVoltage();
    boolean isActive();
};

#endif // BATMON_H