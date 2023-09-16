#pragma once

#include "DataStructure.h"

class Queue : public DataStructure {
public:
	Queue(const std::string& name);

	virtual void rm() override;
};

