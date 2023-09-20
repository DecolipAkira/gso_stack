#pragma once

#include <iostream>
#include <locale>

class Helper
{
public:
	static void locale();

	static void message(const std::string& text);
	static void messageEndl(const std::string& text, int times = 1);
	static void endl(int times = 1);

	static void clear();
	static void pause();
};

