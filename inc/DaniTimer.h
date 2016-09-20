#ifndef DANI_TIMER_H_DEF
#define DANI_TIMER_H_DEF

#if defined _WIN32 || _WIN64
#include<Windows.h>
#elif defined __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#else
#include<sys/time.h>
#endif

#include <functional>
#include <pthread.h>

typedef std::function<int(unsigned int)> DaniTimerCallbackFunc;

namespace callFrequency
{
    enum Enum
    {
        callTypeFirst = 0,
        CALL_FUNCTION_EVERYTIME = 0,
        CALL_FUNCTION_ONCE,
        callTypeLast = CALL_FUNCTION_ONCE
    };
}

class DaniTimer
{
public:
	DaniTimer();
	~DaniTimer();
    int registerCallback(DaniTimerCallbackFunc callback, callFrequency::Enum callType, unsigned long intervalMilliSec);
	int start();
	int stop();
	unsigned long getCurrentTimeMicroSec();
    unsigned long getCurrentTimeMilliSec();
    unsigned long getCurrentTimeSec();
	unsigned long getElapsedTimeMicroSec();
    unsigned long getElapsedTimeMilliSec();
    unsigned long getElapsedTimeSec();

private:
    int init();
    unsigned long getMeasureTime();
    
#if defined _WIN32 || _WIN64
	LARGE_INTEGER frequency;
	LARGE_INTEGER measureTime;
#elif defined __MACH__
    clock_serv_t measureClock;
    mach_timespec_t measureTime;
#else
    struct timespec measureTime;
#endif
    static unsigned long startTimeSec;
    static unsigned long elapsedTimeSec;
    static DaniTimerCallbackFunc callBackFunc;
    static int callType;
    static unsigned long intervalMilliSec;
    
protected:
    pthread_t callBackThread;
    static void* callbackThreadFunc(void*);
};

#endif
