#include "Helper.h"

void Helper::locale() {
	setlocale(LC_ALL, "");
}

void Helper::message(const std::string& text) {
	std::cout << text;
}

void Helper::endl(int times)
{
	for (int i = 0; i < times; ++i)
		std::cout << std::endl;
}

void Helper::messageEndl(const std::string& text, int timesEndl) {
	message(text);

	endl(timesEndl);
}

void Helper::clear() {
#if _WIN32 || _WIN64
	system("cls");
#else
	system("clear");
#endif
}

void Helper::pause() {
#if _WIN32 || _WIN64
	system("pause");
#elif __APPLE__ || __MACH__
	system("read -n 1 -s -p \"Pressione qualquer tecla para continuar. . .\");
#else
	message("Pressione qualquer tecla para continuar. . .");
	std::cin.ignore().get();
#endif
}