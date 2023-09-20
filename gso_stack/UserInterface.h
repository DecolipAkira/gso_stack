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

	void start(int optionZero = 0, bool pauseAfterAction = true, bool finishAfterChoosingOption= false);
	void addOption(const std::string& description, std::function<void()> action, std::vector<Middleware> middlewares = {});
private:
	struct Option {
		std::string description;
		std::function<void()> action;
		std::vector<Middleware> middlewares;
	};

	std::vector<Option> options;

	bool verifyMiddlewares(std::vector<Middleware> Middleware);

	int chosenOption;

	void menu(int optionZero);

	bool verifyChosenAction();
	void executeChosenAction(bool pauseAfterAction);
};

