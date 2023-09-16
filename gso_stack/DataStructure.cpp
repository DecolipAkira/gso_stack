#include "DataStructure.h"

DataStructure::DataStructure(const std::string& name) : structureName(name) {}

void DataStructure::add(int value) {
	items.push_back(value);
}

void DataStructure::show() {
	std::cout << structureName << ": ";

	for (int item : items)
		std::cout << item << " ";

	std::cout << std::endl;
}