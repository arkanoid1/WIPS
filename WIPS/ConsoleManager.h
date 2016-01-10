#pragma once
static volatile bool _sniffingLoopCondition = false;

class ConsoleManager
{
public:
    static bool Create()
    {
        if (!AllocConsole())
            return false;

        if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleManager::SignalHandler_SIGINT, TRUE))
            return false;

        HANDLE standardOutputHandler = GetStdHandle(STD_OUTPUT_HANDLE);
        if (!standardOutputHandler || standardOutputHandler == INVALID_HANDLE_VALUE)
            return false;

        SetConsoleTitle("WIPS, WoW injector packet sniffer");
        freopen("CONOUT$", "w", stdout);
        _sniffingLoopCondition = true;
        return true;
    }

    static void Destroy()  { FreeConsole(); }
    static bool IsRuning() { return _sniffingLoopCondition; }

    static BOOL SignalHandler_SIGINT(DWORD type)
    {
        printf("\nQuiting...\n");
        _sniffingLoopCondition = false;
        return TRUE;
    }
};
