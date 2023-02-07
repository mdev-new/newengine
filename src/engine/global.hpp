#pragma once

#ifdef MAKEDLL
	#ifdef _WIN32
		#define SHARED __declspec(dllexport)
	#else
		#define SHARED __attribute__((visibility ("default")))
	#endif
#else
	#ifdef _WIN32
		#define SHARED __declspec(dllimport)
	#else
		#define SHARED __attribute__((visibility ("hidden")))
	#endif
#endif