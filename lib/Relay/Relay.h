#pragma once

#include <Arduino.h>

#include <PinDevice.h>

/**
 * Обёртка над реле для инкапсуляции инициализации пинов
 * и удобного переключения с учётом возможной инверсности управления.
 */
class Relay : private DigitalOnePinDevice
{
public:
    explicit Relay(uint8_t pin_, bool inverted_);

    void setState(bool state);
    bool getState() { return getLogicLevel();}
    void switchState() { setState(!getState());}
};

