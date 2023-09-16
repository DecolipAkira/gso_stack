#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>

class UserInterface {
public:
	struct Middleware {
		std::string message;
		std::function<bool()> verify;
	};

	void start();
	void addOption(const std::string& description, std::function<void()> action, std::vector<Middleware> middlewares);

	static void message(const std::string& text);
	static void messageEndl(const std::string& text, int times = 1);
	static void endl(int times = 1);
private:
	struct Option {
		std::string description;
		std::function<void()> action;
		std::vector<Middleware> middlewares;
	};

	std::vector<Option> options;

	bool verifyMiddlewares(std::vector<Middleware> Middleware);

	int chosenOption;

	void menu();

	bool verifyChosenAction();
	void executeChosenAction();
};

