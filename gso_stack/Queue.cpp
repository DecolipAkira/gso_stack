#include "Queue.h"
#include "Helper.h"

Queue::Queue() : DataStructure("Fila", 20) {}

void Queue::rm() {
	if (!items.empty())
		items.erase(
			items.begin()
		);
}

void Queue::getItems() {
	for (Process item : items)
		Helper::message("[" + item.name + "]");
}