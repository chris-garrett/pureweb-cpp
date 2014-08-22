#pragma once

#include "iexample.h"

class StringExamples : public IExample
{
public:
    StringExamples();
	virtual ~StringExamples();

	void Run();
	void ToStdString();
};

