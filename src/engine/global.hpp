#pragma once

#ifdef MAKEDLL
	#ifdef _WIN32
		#define SHARED __declspec(dllexport)
	#endif
#else
	#ifdef _WIN32
		#define SHARED __declspec(dllimport)
	#endif
#endif