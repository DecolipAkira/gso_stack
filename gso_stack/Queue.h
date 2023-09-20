#pragma once

#include "DataStructure.h"

class Queue : public DataStructure {
public:
	Queue();

	virtual void rm() override;
	virtual void getItems() override;
};

