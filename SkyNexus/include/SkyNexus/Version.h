#pragma once
#include "exports.h"
#include "Property.h"
namespace SkyNexus
{
	class SKYNEXUS_API Version
	{
	private:
		int major, minor, build, revision;
	public:
		ReadOnlyProperty<int> Major = ReadOnlyProperty<int>(major);
		ReadOnlyProperty<int> Minor = ReadOnlyProperty<int>(minor);
		ReadOnlyProperty<int> Build = ReadOnlyProperty<int>(build);
		ReadOnlyProperty<int> Revision = ReadOnlyProperty<int>(revision);
	public:
		Version();
		Version(int major);
		Version(int major, int minor);
		Version(int major, int minor, int build);
		Version(int major, int minor, int build, int revision);
	};
}