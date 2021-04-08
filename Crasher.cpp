#include "API/ARK/Ark.h"

#pragma comment(lib, "ArkApi.lib")

void Rampage(APlayerController*, FString*, bool)
{
    TArray<FString> dummy;

    if (dummy[1].IsNumeric())
        LOG->info("There is something weird here...");
}

void RconRampage(RCONClientConnection*, RCONPacket*, UWorld*)
{
    Rampage(nullptr, nullptr, false);
}

void Load()
{
    ArkApi::GetCommands().AddConsoleCommand("crasher.crash", &Rampage);
    ArkApi::GetCommands().AddRconCommand("crasher.crash", &RconRampage);
}

void Unload()
{
    ArkApi::GetCommands().RemoveConsoleCommand("crasher.crash");
    ArkApi::GetCommands().RemoveRconCommand("crasher.crash");
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Load();
        break;
    case DLL_PROCESS_DETACH:
        Unload();
        break;
    }
    return TRUE;
}

