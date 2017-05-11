#pragma once
#include <functional>
namespace SkyNexus
{
	template<typename T> class ReadOnlyProperty
	{
	private:
		T m_value;
		T& handle=m_value; 
		std::function<T()> get;		
	public:
		T Get() { return handle; }
		operator T() { return get(); }
	public:		
		ReadOnlyProperty() { handle = this->m_value; get = std::bind(&Property::Get, this); set = std::bind(&Property::Set, this, std::placeholders::_1); }
		ReadOnlyProperty(T value) { handle = value; get = std::bind(&ReadOnlyProperty::Get, this); }
		ReadOnlyProperty(T(*GetMethod)()) { get = std::bind(GetMethod); }
		template<typename C> ReadOnlyProperty(C* Object, T(C::*GetMethod)()) { get = std::bind(GetMethod, Object); }
	};

	template<typename T> class Property
	{
	private:
		T m_value;
		T& handle=m_value;
		std::function<T()> get; std::function<void(T)> set;
	public:
		T Get() { return handle; } void Set(T value) { handle = value; }
		operator T() { return get(); } void operator=(T value) { set(value); }
	public:
		Property() { handle = this->m_value; get = std::bind(&Property::Get, this); set = std::bind(&Property::Set, this, std::placeholders::_1); }
		Property(T value) { handle = value; get = std::bind(&Property::Get, this); set = std::bind(&Property::Set, this, std::placeholders::_1); }
		Property(T(*GetMethod)(), void(*SetMethod)(T)) { get = std::bind(GetMethod); set = std::bind(SetMethod, std::placeholders::_1); }
		template<typename C> Property(C* Object, T(C::*GetMethod)(), void(C::*SetMethod)(T)) { get = std::bind(GetMethod, Object); set = std::bind(SetMethod, Object, std::placeholders::_1); }
	};
}