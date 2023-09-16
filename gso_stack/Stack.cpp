#include "Stack.h"

Stack::Stack(const std::string& name) : DataStructure("Pilha") {}

void Stack::rm() {
	if (!items.empty())
		items.pop_back();
}