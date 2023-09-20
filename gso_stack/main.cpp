#include <iostream>
#include <string>

#include "DataStructure.h"
#include "UserInterface.h"

#include "Queue.h"
#include "Stack.h"

#include "Helper.h"

#include "Process.h"

int main() {
	Helper::locale();

	std::vector<Process> processes = {
		{"Bloco de Notas", 1},
		{"Paint", 2},
		{"Visual Studio Code", 2},
		{"Spotify", 3},
		{"Word", 3},
		{"Mozilla Firefox", 3},
		{"Excel", 4},
		{"PowerPoint", 3},
		{"Google Chrome", 4}
	};

	DataStructure* structure = nullptr;

	std::function<void()> resetStructure = [&]() {
		if (structure == nullptr)
			return;

		delete structure;
		structure = nullptr;
	};

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
		UserInterface insertInterface;

		for (Process process : processes) {
			insertInterface.addOption(process.name, [&, process]() {
				

				if (structure->hasResourcesTo(process)) {
					structure->add(process);

					Helper::messageEndl("Processo " + process.name + " adicionado a " + structure->getName(), 2);
				} else {
					Helper::messageEndl("Processo " + process.name + " não adicionado a " + structure->getName() + ", por falta de Recursos!", 2);
				}
					
			});
		}

		insertInterface.start();
	}, middlewares);

	interface.addOption("Remover", [&]() {
		Helper::messageEndl("Opção Remover:", 2);

		structure->rm();

		Helper::messageEndl("Valor removido com sucesso.", 2);

		structure->show();
	}, middlewares);

	interface.addOption("Mostrar", [&] {
		structure->show();
	}, middlewares);

	interface.addOption("Definir Estrutura", [&]() {
		UserInterface defineDataStructure;

		defineDataStructure.addOption("Pilha", [&]() {
			resetStructure();

			structure = new Stack;

			Helper::messageEndl(structure->getName() + " definida como Estrutura de Dados.", 2);
		});

		defineDataStructure.addOption("Fila", [&]() {
			resetStructure();

			structure = new Queue;

			Helper::messageEndl(structure->getName() + " definida como Estrutura de Dados.", 2);
		});

		defineDataStructure.start();
	});

	interface.start();

	resetStructure();

	return 0;
}