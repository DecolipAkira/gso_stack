#include "UserInterface.h"

void UserInterface::start() {
	do {
		system("cls");
		
		menu();

		if (verifyChosenAction())
			executeChosenAction();

	} while (chosenOption != 0);
}

void UserInterface::addOption(const std::string& description, std::function<void()> action, std::vector<Middleware> middlewares) {
	Option option;

	option.description = description;
	option.action = action;
	option.middlewares = middlewares;

	options.push_back(option);
}

void UserInterface::message(const std::string& text) {
	std::cout << text;
}

void UserInterface::endl(int times)
{
	for(int i = 0; i < times; ++i)
		std::cout << std::endl;
}

void UserInterface::messageEndl(const std::string& text, int times) {
	message(text);

	endl(times);
}

bool UserInterface::verifyMiddlewares(std::vector<Middleware> middlewares) {
	bool result = true;

	for (Middleware middleware : middlewares) {
		if (!middleware.verify()) {
			messageEndl(middleware.message, 2);

			system("pause");

			return false;
		}
	}

	return true;
}

void UserInterface::menu() {
	messageEndl("Opções Disponíveis: ", 2);

	for (size_t i = 0; i < options.size(); ++i)
		messageEndl("[" + std::to_string(i + 1) + "] " + options[i].description);

	messageEndl("[0] Sair", 2);

	message("Escolha uma opção: ");

	std::cin >> chosenOption;
}

bool UserInterface::verifyChosenAction() {
	if (!(chosenOption >= 1 && chosenOption <= static_cast<int>(options.size())))
		return false;

	return true;
}

void UserInterface::executeChosenAction() {
	system("cls");

	if (!verifyMiddlewares(options[chosenOption - 1].middlewares))
		return;

	options[chosenOption - 1].action();

	system("pause");
}