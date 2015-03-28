#pragma once

#include <string>

static const char __char_digits[0x10] = 
  {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
static const wchar_t __wchar_digits[0x10] = 
  {L'0',L'1',L'2',L'3',L'4',L'5',L'6',L'7',L'8',L'9',L'A',L'B',L'C',L'D',L'E',L'F'};

static long __pow10(int e)
{
	long ret = 1;
	for(int i = 0; i < e; ++i)
	{
		ret *= 10;
	}
	return ret;
}

std::string _to_str(int n)
{
	std::string str;
	if(n < 0)
	{
		str += '-';
		n = -n;
	}
	bool zero = false;
	for(int i = 9; i >= 0; --i)
	{
		int digit = (n/__pow10(i))%10;
		if(digit || zero)
		{
			str += __char_digits[digit];
			zero = true;
		}
	}
	if(!n)
	{
		str += '0';
	}
	return str;
}

std::wstring _to_wstr(int n)
{
	std::wstring str;
	if(n < 0)
	{
		str += L'-';
		n = -n;
	}
	bool zero = false;
	for(int i = 9; i >= 0; --i)
	{
		int digit = (n/__pow10(i))%10;
		if(digit || zero)
		{
			str += __wchar_digits[digit];
			zero = true;
		}
	}
	if(!n)
	{
		str += L'0';
	}
	return str;
}
