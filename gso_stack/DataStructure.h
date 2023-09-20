#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Process.h"

class DataStructure {
protected:
	std::vector<Process> items;
	std::string structureName;
	int resourceLimit;
public:
	DataStructure(const std::string& name, int resourceLimit);
	virtual void add(Process process);
	virtual void show();
	virtual std::string getName();
	virtual bool hasResourcesTo(Process process);
	virtual bool empty();

	virtual void rm() = 0;
	virtual void getItems() = 0;
};