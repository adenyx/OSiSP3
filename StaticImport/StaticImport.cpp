#include <iostream>
#include <Windows.h>
#include "strReplace.h"

int main()
{
	DWORD pid = GetCurrentProcessId();

	const char srcString[] = "old string for static";
	const char resString[] = "new string for static";

	ReplaceString(srcString, resString);

	std::cout << srcString << "\n";
}