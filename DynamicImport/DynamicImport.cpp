#include <iostream>
#include <Windows.h>

typedef void __cdecl ReplacingFunction(const char* srcString, const char* resString);

int main()
{
	const char srcString[] = "old string for dynamic";
	const char resString[] = "new string for dynamic";

	HMODULE hDll = LoadLibrary(L"Lab3DLL.dll");
	if (hDll != NULL)
	{
		ReplacingFunction* replaceFunction = (ReplacingFunction*)GetProcAddress(hDll, "ReplaceString");
		if (replaceFunction != NULL)
		{
			replaceFunction(srcString, resString);
		}
		else
		{
			std::cout << GetLastError();
		}

		FreeLibrary(hDll);
	}

	std::cout << srcString << "\n";
}
