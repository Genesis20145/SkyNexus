#pragma once
#include "exports.h"
#include "Color.h"
#include "Encoding.h"
#include "String.h"
#include "Property.h"
#include "IO\Stream.h"
#include <iostream>
#include <conio.h>
namespace SkyNexus
{
	class SKYNEXUS_API Console
	{
	public:
		static Color GetBackgroundColor(); static void SetBackgroundColor(Color value);
		static String GetTitle(); static void SetTitle(String value);
	public:
		static Property<Color> BackgroundColor;
		static Property<int> BufferHeight;
		static Property<int> BufferWidth;
		static ReadOnlyProperty<bool> CapsLock;
		static Property<int> CursorLeft;
		static Property<int> CursorSize;
		static Property<int> CursorTop;
		static Property<bool> CursorVisible;
		static ReadOnlyProperty<IO::Stream*> Error;
		static Property<Color> ForegroundColor;
		static ReadOnlyProperty<IO::Stream*> In;
		static Property<Encoding> InputEncoding;
		static ReadOnlyProperty<bool> IsErrorRedirected;
		static ReadOnlyProperty<bool> IsInputRedirected;
		static ReadOnlyProperty<bool> IsOutputRedirected;
		static ReadOnlyProperty<bool> KeyAvailable;
		static ReadOnlyProperty<int> LargestWindowHeight;
		static ReadOnlyProperty<int> LargestWindowWidth;
		static ReadOnlyProperty<bool> NumberLock;
		static ReadOnlyProperty<IO::Stream*> Out;
		static Property<Encoding> OutputEncoding;
		static Property<String> Title;
		static Property<bool> ThreadControlCAsInput;
		static Property<int> WindowHeight;
		static Property<int> WindowLeft;
		static Property<int> WindowTop;
		static Property<int> WindowWidth;
	public:
		static String Read();
		static String Read(char c);
		static String ReadLine();
		static String ReadLine(char c);
		static void Write(String text);
		static void WriteLine(String Text);
	};
}