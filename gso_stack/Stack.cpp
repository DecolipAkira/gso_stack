#include "Stack.h"
#include "Helper.h"

Stack::Stack() : DataStructure("Pilha", 15) {}

void Stack::rm() {
	if (!items.empty())
		items.pop_back();
}

void Stack::getItems() {
	for (Process item : items)
		Helper::messageEndl("[" + item.name + "]");
}