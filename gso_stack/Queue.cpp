#include "Queue.h"

Queue::Queue(const std::string& name) : DataStructure("Fila") {}

void Queue::rm() {
	if (!items.empty())
		items.erase(
			items.begin()
		);
}