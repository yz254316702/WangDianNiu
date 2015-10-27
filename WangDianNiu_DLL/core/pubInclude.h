#pragma once


#include <string>
#include <vector>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>


// TODO: reference additional headers your program requires here

void Unicode_to_UTF8(const wchar_t* in, unsigned int len, std::string& out);

void UTF8_to_Unicode(const char* in, unsigned int len, std::wstring& out);

void Unicode_to_ANSI(const wchar_t* in, unsigned int len, std::string& out);

void ANSI_to_Unicode(const char* in, unsigned int len, std::wstring& out);

