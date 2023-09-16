#include <iostream>
#include <locale>

#include "DataStructure.h"
#include "UserInterface.h"

#include "Queue.h"
#include "Stack.h"


int main() {
	setlocale(LC_ALL, "");

	DataStructure* structure = nullptr;

	UserInterface interface;

	UserInterface::Middleware undefinedStructure;

	undefinedStructure.message = "Nenhuma estrutura definida!";
	undefinedStructure.verify = [&]() {
		if (!structure)
			return false;

		return true;
	};

	std::vector<UserInterface::Middleware> middlewares;

	middlewares.push_back(undefinedStructure);

	interface.addOption("Inserir", [&]() {
		UserInterface::messageEndl("Opção Inserir", 2);
	}, middlewares);

	interface.addOption("Remover", [&]() {
		UserInterface::messageEndl("Opção Remover", 2);
	}, middlewares);

	middlewares.pop_back();

	interface.addOption("Definir Estrutura", [&]() {
		UserInterface::messageEndl("Definir Estrutura", 2);
	}, middlewares);

	interface.start();

	return 0;
}