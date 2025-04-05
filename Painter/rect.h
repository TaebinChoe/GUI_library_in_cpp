#pragma once
#include "figure.h"

class Rect : public Figure {
public:
	Rect(Container* myContainer, const MPoint& sp, const MPoint& ep, int color);
	void draw() override;
};