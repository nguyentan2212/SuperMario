#pragma once
#include <d3d9.h>
#include <string>

class StringHelper
{
private:
	

public:
	static std::wstring s2ws(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}
	static LPWSTR String2LPWSTR(const std::string& str)
	{
		wchar_t wtext[50];
		size_t outSize;
		mbstowcs_s(&outSize, wtext, str.c_str(), str.size() + 1);//Plus null
		LPWSTR temp = wtext;
		return temp;
	}
	static LPCWSTR String2LPCWSTR(const std::string& str)
	{
		std::wstring stemp = s2ws(str);
		LPCWSTR result = stemp.c_str();
		return result;
	}
};