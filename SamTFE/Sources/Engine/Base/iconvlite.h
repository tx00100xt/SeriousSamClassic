/*
iconvlite.h
Iconv Lite
Simple cpp functions to convert strings from cp1251 to utf8 and ftom utf8 to cp1251
https://github.com/Iyamoto/iconv-lite
*/

#ifndef ICONVLITE_H
#define ICONVLITE_H

#include <cstdio>

void cp2utf1(char *out, const char *in, size_t out_size);

#endif