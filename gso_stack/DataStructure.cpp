#include "DataStructure.h"
#include "Helper.h"

DataStructure::DataStructure(const std::string& name, int resourceLimit) : structureName(name), resourceLimit(resourceLimit) {}

bool DataStructure::hasResourcesTo(Process process) {
	int sum = 0;

	for (Process item : items)
		sum += item.resourceUsage;

	if (resourceLimit - sum < process.resourceUsage)
		return false;

	return true;
}

void DataStructure::add(Process process) {
	if(hasResourcesTo(process))
		items.push_back(process);
}

void DataStructure::show() {
	Helper::messageEndl(structureName + ": ", 2);

	getItems();

	Helper::endl(2);
}

std::string DataStructure::getName() {
	return structureName;
}