#pragma once

#include <vector>
#include <string>
#include <iostream>

class DataStructure {
protected:
	std::vector<int> items;
	std::string structureName;
public:
	DataStructure(const std::string& name);
	virtual void add(int value);
	virtual void show();

	virtual void rm() = 0;
};