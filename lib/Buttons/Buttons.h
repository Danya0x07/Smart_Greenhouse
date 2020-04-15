#pragma once

#include <Arduino.h>

/**
 * Тактовая кнопка.
 * Инкапсулирует инициализацию пинов, определение нажатий
 * и резисторную подтяжку/стяжку.
 */
class Button
{
private:
    const uint8_t pin;
    const bool inverted;
    bool lastState;

public:
    /** 
     * pin: нормер контакта кнопки в представлении Arduino;
     * inverted: логический уровень на пине в ненажатом состоянии. 
     */
    explicit Button(uint8_t pin, bool inverted);

    /** Возвращает true, если кнопка зажата в данный момент, иначе false. */
    bool isPressed();

    /** 
     * Возвращает true, если кнопка была переведена из ненажатого состояния в нажатое.
     * После первого срабатывания. вернувшего true, возвращает false до тех пор,
     * пока кнопка не будет отпущена и нажата снова.
     * Интересный факт: если перепутать атрибут inverted, то true будет возвращаться
     * при отпускании, а не при нажатии. 
     */
    bool hasBeenPressed();

    /** 
     * Возвращает true, если в течение небольшого промежутка времени 
     * hasBeenPressed() вернула true, иначе false.
     * Предназначена для обнаружения многократных нажатий. 
     */
    bool hasBeenPressedAgain();
};