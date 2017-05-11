#pragma once
#ifdef SKYNEXUS_EXPORTS
#define SKYNEXUS_API __declspec(dllexport)
#define SKYNEXUS_INTERNAL
#else
#define SKYNEXUS_API __declspec(dllimport)
#endif
