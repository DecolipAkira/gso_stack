#include "UserInterface.h"
#include "Helper.h"

void UserInterface::start(int optionZero, bool pauseAfterAction, bool finishAfterChoosingOption) {
	do {
		Helper::clear();
		
		menu(optionZero);

		if (verifyChosenAction())
			executeChosenAction(pauseAfterAction);

	} while (!finishAfterChoosingOption && chosenOption != 0);
}

void UserInterface::addOption(const std::string& description, std::function<void()> action, std::vector<Middleware> middlewares) {
	Option option;

	option.description = description;
	option.action = action;
	option.middlewares = middlewares;

	options.push_back(option);
}

bool UserInterface::verifyMiddlewares(std::vector<Middleware> middlewares) {
	bool result = true;

	for (Middleware middleware : middlewares) {
		if (!middleware.verify()) {
			Helper::messageEndl(middleware.message, 2);

			Helper::pause();

			return false;
		}
	}

	return true;
}

void UserInterface::menu(int optionZero) {
	Helper::messageEndl("Opções Disponíveis: ", 2);

	for (size_t i = 0; i < options.size(); ++i)
		Helper::messageEndl("[" + std::to_string(i + 1) + "] " + options[i].description);

	switch (optionZero) {
		case 0:
			Helper::messageEndl("[0] Sair", 2);
			break;
		case 1:
			Helper::messageEndl("[0] Voltar", 2);
			break;
	}

	Helper::message("Escolha uma opções: ");

	std::cin >> chosenOption;
}

bool UserInterface::verifyChosenAction() {
	if (!(chosenOption >= 1 && chosenOption <= static_cast<int>(options.size())))
		return false;

	return true;
}

void UserInterface::executeChosenAction(bool pauseAfterAction) {
	Helper::clear();

	if (!verifyMiddlewares(options[chosenOption - 1].middlewares))
		return;

	options[chosenOption - 1].action();

	if(pauseAfterAction)
		Helper::pause();
}