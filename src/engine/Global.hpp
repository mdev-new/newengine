#pragma once

#ifdef _MSC_VER
#	ifdef BUILD_DLL
#		define ENGINEAPI __declspec(dllexport)
#	else
#		define ENGINEAPI __declspec(dllimport)
#	endif
#else
#	define ENGINEAPI
#endif