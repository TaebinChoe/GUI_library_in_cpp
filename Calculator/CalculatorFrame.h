#pragma once
#include "frame.h"

class CalculatorPanel;

class CalculatorFrame :public Frame{
private:
	CalculatorPanel* myCalculatorPanel_ = nullptr;
public:
	CalculatorFrame(std::string title, int width, int height);
	virtual ~CalculatorFrame() override;
	virtual void initialize() override;
};

