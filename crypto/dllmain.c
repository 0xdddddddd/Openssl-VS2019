#include "e_os.h"
#include "internal/cryptlib_int.h"
# pragma comment(lib,"ws2_32.lib")

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		OPENSSL_cpuid_setup();
		break;
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		OPENSSL_thread_stop();
        break;
    }
    return TRUE;
}