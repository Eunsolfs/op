#pragma once
#ifndef __COLOR_H_
#define __COLOR_H_
#include <algorithm>
#include "../core/optype.h"
#include <math.h>

#define WORD_BKCOLOR 0
#define WORD_COLOR 1
#define color2uint(color) (*(uint*)&color)

template<typename T>
constexpr T OP_ABS(T x) {
	return x < 0 ? -x : x;
}
template<typename T>
constexpr bool IN_RANGE(T lhs, T rhs, T df) {
	return OP_ABS(lhs.b - rhs.b) <= df.b
		&& OP_ABS(lhs.g - rhs.g) <= df.g
		&& OP_ABS(lhs.r - rhs.r) <= df.r;
}

//#pragma pack(push)
#pragma pack(1)

/*
#pragma pack(1) 是一个预处理指令，用于告诉编译器以指定的字节对齐方式对结构体、类或联合进行打包。
在这种情况下，(1) 指定了以1字节对齐，即按照最小的对齐原则进行对齐，不添加任何填充字节。
这个指令通常用于需要与外部系统进行数据交换的情况，或者在需要与特定硬件进行交互时。
然而，使用这个指令也可能会增加内存访问的效率，并减小内存占用，因为它避免了结构体或类被填充以达到特定对齐要求。
*/

struct color_t {
	//b is in low address ,alpha is in high address
	uchar b, g, r, alpha;
	color_t() :b(0), g(0), r(0), alpha(0) {}
	color_t(int b_, int g_, int r_) :b(b_), g(g_), r(r_), alpha(0xffu) {}

	color_t& str2color(const std::wstring& s) {
		int r = 0, g = 0, b = 0;
		std::wstring ss = s;
		std::transform(ss.begin(), ss.end(), ss.begin(), ::towupper);
		int cnt = swscanf(ss.c_str(), L"%02X%02X%02X", &r, &g, &b);
		this->b = b; this->r = r; this->g = g;
		return *this;
	}
	color_t& str2color(const std::string& s) {
		int r, g, b;
		std::string ss = s;
		std::transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
		int cnt = sscanf(ss.c_str(), "%02X%02X%02X", &r, &g, &b);
		this->b = b; this->r = r; this->g = g;
		return *this;
	}
	std::string tostr() {
		char buff[10];
		sprintf(buff, "%02X%02X%02X", r, g, b);
		return buff;
	}
	std::wstring towstr() {
		wchar_t buff[10];
		wsprintf(buff, L"%02X%02X%02X", r, g, b);
		return buff;
	}
	uchar toGray() const {
		return (r * 299 + g * 587 + b * 114 + 500) / 1000;
	}
};
#pragma pack()
struct color_df_t {
	color_t color;
	color_t df;
};

struct pt_cr_df_t {
	int x, y;
	std::vector<color_df_t> crdfs;
};

#endif
