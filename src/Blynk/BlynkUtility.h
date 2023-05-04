/**
 * @file       BlynkUtility.h
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
 * @date       Jun 2015
 * @brief      Utility functions
 *
 */

#ifndef BlynkUtility_h
#define BlynkUtility_h

#include <Blynk/BlynkDebug.h>

template<class T_Blynk>
const T_Blynk& BlynkMin(const T_Blynk& a, const T_Blynk& b)
{
    return (b < a) ? b : a;
}

template<class T_Blynk>
const T_Blynk& BlynkMax(const T_Blynk& a, const T_Blynk& b)
{
    return (b < a) ? a : b;
}


template <class T_Blynk, class T2_Blynk>
T_Blynk BlynkMathMap(T_Blynk x, T2_Blynk in_min, T2_Blynk in_max, T2_Blynk out_min, T2_Blynk out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

template <class T_Blynk, class T2_Blynk>
T_Blynk BlynkMathClamp(T_Blynk val, T2_Blynk low, T2_Blynk high)
{
  return (val < low) ? low : ((val > high) ? high : val);
}

template <class T_Blynk, class T2_Blynk>
T_Blynk BlynkMathClampMap(T_Blynk x, T2_Blynk in_min, T2_Blynk in_max, T2_Blynk out_min, T2_Blynk out_max)
{
  x = BlynkMathClamp(x, in_min, in_max);
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

template <class T_Blynk, unsigned N>
class BlynkMovingAverage {
public:
    BlynkMovingAverage() {
        reset();
    }

    void reset() {
        _first = true;
        _avg = 0;
    }

    bool hasValue() const {
        return !_first;
    }

    T_Blynk get() const {
        return _avg;
    }

    T_Blynk push(T_Blynk value) {
        if (_first) {
            _avg = value;
            _first = false;
        } else {
            _avg -= _avg/N;
            _avg += double(value)/N;
        }
        return _avg;
    }

private:
    bool    _first;
    double  _avg;
};

template <unsigned WSIZE, typename T_Blynk>
void BlynkAverageSample (T_Blynk& avg, const T_Blynk& input) {
    avg -= avg/WSIZE;
    const T_Blynk add = input/WSIZE;
    // Fix for shorter delays
    if (add > 0)
      avg += add;
    else
      avg -= 1;
}

static inline
int BlynkRSSI2SQ(int dBm) {
    if(dBm <= -100) {
        return 0;
    } else if(dBm >= -50) {
        return 100;
    } else {
        return 2 * (dBm + 100);
    }
}

static inline
int BlynkSQ2RSSI(int quality) {
    if(quality <= 0) {
        return -100;
    } else if(quality >= 100) {
        return -50;
    } else {
        return (quality / 2) - 100;
    }
}

static inline
uint32_t BlynkCRC32(const void* data, size_t length, uint32_t previousCrc32 = 0)
{
  const uint32_t Polynomial = 0xEDB88320;
  uint32_t crc = ~previousCrc32;
  unsigned char* current = (unsigned char*)data;
  while (length--) {
    crc ^= *current++;
    for (unsigned int j = 0; j < 8; j++) {
      crc = (crc >> 1) ^ (-int(crc & 1) & Polynomial);
    }
  }
  return ~crc;
}

static inline
bool BlynkStrMatch(const char* pat, const char* txt) {
    const long n = strlen(txt);
    const long m = strlen(pat);

    if (m == 0)
        return (n == 0);

    long i = 0, j = 0, index_txt = -1,
        index_pat = -1;

    while (i < n) {
        if (j < m && txt[i] == pat[j]) {
            i++;
            j++;
        } else if (j < m && pat[j] == '?') {
            i++;
            j++;
        } else if (j < m && pat[j] == '*') {
            index_txt = i;
            index_pat = j;
            j++;
        } else if (index_pat != -1) {
            j = index_pat + 1;
            i = index_txt + 1;
            index_txt++;
        } else {
            return false;
        }
    }

    while (j < m && pat[j] == '*') {
        j++;
    }

    if (j == m) {
        return true;
    }

    return false;
}

class BlynkHelperAutoInc {
public:
    BlynkHelperAutoInc(uint8_t& counter) : c(counter) { ++c; }
    ~BlynkHelperAutoInc() { --c; }
private:
    uint8_t& c;
};

#define BlynkBitSet(value, bit)   ((value) |= (1UL << (bit)))
#define BlynkBitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define BlynkBitRead(value, bit)  (((value) >> (bit)) & 0x01)
#define BlynkBitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#endif
