#pragma once

#include "DataStructure.h"

class Stack : public DataStructure {
public:
	Stack(const std::string& name);

	void rm() override;
};

