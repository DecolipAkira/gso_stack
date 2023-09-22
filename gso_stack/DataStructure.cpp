#include "DataStructure.h"
#include "Helper.h"

DataStructure::DataStructure(const std::string& name, int resourceLimit) : structureName(name), resourceLimit(resourceLimit) {}
DataStructure::~DataStructure() {}

bool DataStructure::hasResourcesTo(Process process) {
	int sum = 0;

	for (Process item : items)
		sum += item.resourceUsage;

	if (resourceLimit - sum < process.resourceUsage)
		return false;

	return true;
}

void DataStructure::add(Process process) {
	if (hasResourcesTo(process))
		items.push_back(process);
}

void DataStructure::show() {
	if (empty())
		Helper::message("<vázio>");
	else
		getItems();

	Helper::endl(2);
}

std::string DataStructure::getName() {
	return structureName;
}

bool DataStructure::empty() {
	return items.empty();
}