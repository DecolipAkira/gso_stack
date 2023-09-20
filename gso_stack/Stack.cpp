#include "Stack.h"
#include "Helper.h"

Stack::Stack() : DataStructure("Pilha", 15) {}

void Stack::rm() {
	if (!items.empty())
		items.pop_back();
}

void Stack::getItems() {
	for (int i = items.size(); i --> 0;)
		Helper::messageEndl("[" + items[i].name + "]");
}