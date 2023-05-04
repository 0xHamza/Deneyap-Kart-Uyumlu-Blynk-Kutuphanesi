/**
 * @file       WidgetMap.h
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2016 Volodymyr Shymanskyy
 * @date       Nov 2016
 * @brief
 */

#ifndef WidgetMap_h
#define WidgetMap_h

#include <Blynk/BlynkWidgetBase.h>

class WidgetMap
    : public BlynkWidgetBase
{
public:
    WidgetMap(uint8_t vPin) : BlynkWidgetBase(vPin) {}

    void clear() {
        Blynk.virtualWrite(mPin, "clr");
    }

    template<typename T1_Blynk, typename T2_Blynk, typename T3_Blynk, typename T4_Blynk>
    void location(const T1_Blynk& index, const T2_Blynk& lat, const T3_Blynk& lon, const T4_Blynk& value) {
        Blynk.virtualWrite(mPin, index, lat, lon, value);
    }

};

#endif
