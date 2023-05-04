/**
 * @file       BlynkWidgets.h
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
 * @date       Mar 2015
 * @brief
 */

#include <WidgetLED.h>
#include <WidgetLCD.h>
#include <WidgetTerminal.h>
#include <WidgetTimeInput.h>
#include <WidgetMap.h>

// Cannot auto-include as these have library dependencies
//#include <WidgetRTC.h>

template<class T_Blynk>
class VPinWriteOnChange {
    T_Blynk prev;
    const int vpin;
public:
    VPinWriteOnChange(int v)
        : vpin(v)
    {}

    VPinWriteOnChange<T_Blynk>& operator= (const T_Blynk& value) {
        update(value);
        return *this;
    }

    void set(const T_Blynk& value) {
        prev = value;
    }

    void update(const T_Blynk& value) {
        if (value != prev) {
            prev = value;
            report();
        }
    }

    void report() {
        Blynk.virtualWrite(vpin, prev);
    }
};
