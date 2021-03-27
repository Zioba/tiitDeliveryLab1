#pragma once


#ifdef SUFLIBRARY_EXPORTS
#define SUFLIBRARY_API __declspec(dllexport)
#else
#define SUFLIBRARY_API __declspec(dllimport)
#endif


extern "C" SUFLIBRARY_API void SufAr(char* txt);


extern "C" SUFLIBRARY_API void LCP(char* X, char* Y);


extern "C" SUFLIBRARY_API void MCS(char* a);



