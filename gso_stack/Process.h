#pragma once

#include <iostream>
#include <string>

struct Process {
	std::string name;
	int resourceUsage;

	Process(const std::string& name, int usage);
};