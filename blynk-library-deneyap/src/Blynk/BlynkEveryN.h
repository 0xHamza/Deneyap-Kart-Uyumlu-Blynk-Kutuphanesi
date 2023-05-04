
#ifndef BLYNKEVERYN_H
#define BLYNKEVERYN_H

#include <Blynk/BlynkDebug.h>

millis_time_t blynk_count_millis() {
    const millis_time_t ms = BlynkMillis();
    return ms;
}

uint16_t blynk_count_seconds16() {
    const millis_time_t ms = BlynkMillis();
    return (ms / 1000);
}

uint16_t blynk_count_minutes16()
{
    const millis_time_t ms = BlynkMillis();
    return (ms / (60000L)) & 0xFFFF;
}

uint8_t blynk_count_hours8()
{
    const millis_time_t ms = BlynkMillis();
    return (ms / (3600000L)) & 0xFF;
}

template<typename T_Blynk, T_Blynk (*timeGetter)()>
class BlynkPeriodic {
public:
    T_Blynk mPrev;
    T_Blynk mPeriod;

    BlynkPeriodic()           { reset(); mPeriod = 1; };
    BlynkPeriodic(T_Blynk period)   { reset(); setPeriod(period); };
    void setPeriod( T_Blynk period) { mPeriod = period; };
    T_Blynk getTime()               { return (T_Blynk)(timeGetter()); };
    T_Blynk getPeriod()             { return mPeriod; };
    T_Blynk getElapsed()            { return getTime() - mPrev; }
    T_Blynk getRemaining()          { return mPeriod - getElapsed(); }
    T_Blynk getLastTriggerTime()    { return mPrev; }
    bool ready() {
        bool isReady = (getElapsed() >= mPeriod);
        if( isReady ) { reset(); }
        return isReady;
    }
    void reset()              { mPrev = getTime(); };
    void trigger()            { mPrev = getTime() - mPeriod; };

    operator bool()           { return ready(); }
};

typedef BlynkPeriodic<millis_time_t,blynk_count_millis> BlynkEveryNMillis;
typedef BlynkPeriodic<uint16_t,blynk_count_seconds16>   BlynkEveryNSeconds;
typedef BlynkPeriodic<uint16_t,blynk_count_minutes16>   BlynkEveryNMinutes;
typedef BlynkPeriodic<uint8_t,blynk_count_hours8>       BlynkEveryNHours;

#define BLYNK_EVERY_N_MILLIS_I(NAME,N)  static BlynkEveryNMillis NAME(N); if(NAME)
#define BLYNK_EVERY_N_SECONDS_I(NAME,N) static BlynkEveryNSeconds NAME(N); if(NAME)
#define BLYNK_EVERY_N_MINUTES_I(NAME,N) static BlynkEveryNMinutes NAME(N); if(NAME)
#define BLYNK_EVERY_N_HOURS_I(NAME,N)   static BlynkEveryNHours NAME(N); if(NAME)

#define BLYNK_EVERY_N_MILLIS(N)  BLYNK_EVERY_N_MILLIS_I(BLYNK_CONCAT2(PER, __COUNTER__),N)
#define BLYNK_EVERY_N_SECONDS(N) BLYNK_EVERY_N_SECONDS_I(BLYNK_CONCAT2(PER, __COUNTER__),N)
#define BLYNK_EVERY_N_MINUTES(N) BLYNK_EVERY_N_MINUTES_I(BLYNK_CONCAT2(PER, __COUNTER__),N)
#define BLYNK_EVERY_N_HOURS(N)   BLYNK_EVERY_N_HOURS_I(BLYNK_CONCAT2(PER, __COUNTER__),N)

#endif
