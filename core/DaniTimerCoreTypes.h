typedef std::function<int(unsigned long)> DaniTimerCoreCallbackFunc;

namespace TimerCore
{
	enum CountMode
	{
		COUNTUP   = 0x00000000,
		COUNTDOWN = 0x00000001
	};
    
    enum CurrentState
    {
        PROGRESS = 0x10000000,
        PAUSE    = 0x10000001,
        STOP     = 0x10000002
    };
    
    enum Error
    {
        SUCCESS          = 0x00000000,
        INVALID_STATE    = 0x20000001,
        OPERATION_FAILED = 0x20000002
    };
}