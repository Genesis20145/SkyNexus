#pragma once
#include "exports.h"
#include <string>
#include <algorithm>
#include <cstdio>
#include <memory>
#include <vector>
#include "Property.h"

namespace SkyNexus
{		
	class SKYNEXUS_API String
	{
	public:
		const static String Empty;
	private:
		std::string m_value;	
	public:
		int GetLength(); ReadOnlyProperty<int> Length = ReadOnlyProperty<int>(this, &String::GetLength);
	public:
		bool EndsWith(String value, bool ignoreCase = false);
		String PadLeft(int totalWidth);
		String PadLeft(int totalWidth, char paddingChar);
		String PadRight(int totalWidth);
		String PadRight(int totalWidth, char paddingChar);
		String Remove(int startIndex);
		String Remove(int startIndex, int count);
		String Replace(char oldChar, char newChar);
		String Replace(String oldValue, String newValue);		
		bool StartWith(String value, bool ignoreCase = false);	
		String Substring(int startIndex);
		String Substring(int startIndex, int length);
		char* ToCharArray();
		char* ToCharArray(int startIndex, int length);
		String ToLower(); 
		String ToUpper();
		String Trim(char trimChar);
		String Trim();
		String Trim(char* trimChars);
	public:
		static String ToLower(String value);
		static String ToUpper(String value);
	public:
		String();	
		String(char* value);
		String(char* value, int length);
		String(const char* value);
		String(const char* value, int length);
		String(std::string value);
		String(wchar_t* value);
		String(wchar_t* value, int length);
		String(const wchar_t* value);
		String(const wchar_t* value, int length);
		String(std::wstring value);
	public:
		void operator =(char* value);
		void operator =(const char* value);
		void operator =(std::string value);
		void operator =(wchar_t* value);
		void operator =(const wchar_t* value);
		void operator =(std::wstring value);
		void operator =(String value);
		bool operator ==(char* value);
		bool operator ==(const char* value);
		bool operator ==(std::string value);
		bool operator ==(wchar_t* value);
		bool operator ==(const wchar_t* value);
		bool operator ==(std::wstring value);
		bool operator ==(String value);
		bool operator !=(char* value);
		bool operator !=(const char* value);
		bool operator !=(std::string value);
		bool operator !=(wchar_t* value);
		bool operator !=(const wchar_t* value);
		bool operator !=(std::wstring value);
		bool operator !=(String value);
		String operator +(char* value);
		String operator +(const char* value);
		String operator +(std::string value);
		String operator +(wchar_t* value);
		String operator +(const wchar_t* value);
		String operator +(std::wstring value);
		String operator +(String value);
		void operator +=(char* value);
		void operator +=(const char* value);
		void operator +=(std::string value);
		void operator +=(wchar_t* value);
		void operator +=(const wchar_t* value);
		void operator +=(std::wstring value);		
		void operator +=(String value);
		char operator[](int index);
	public:		
		operator char*() const;
		operator const char*() const;
		operator std::string() const;
		operator wchar_t*() const;
		operator const wchar_t*() const;
		operator std::wstring() const;
	};
}