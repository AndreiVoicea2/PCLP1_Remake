#pragma once
#include <string>
#include <iostream>
#include "windows.h"

using namespace std;

extern void WriteColoredText(string text, bool isHighlt , bool Reset);

class GlobalVariables
{
	public:
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			
};

