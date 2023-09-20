#pragma once

#include "DataStructure.h"

class Stack : public DataStructure {
public:
	Stack();

	virtual void rm() override;
	virtual void getItems() override;
};

