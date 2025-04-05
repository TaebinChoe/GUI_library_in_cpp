#pragma once

#include "figure.h"

class Ellip : public Figure {
public:
	Ellip(Container* myContainer, const MPoint& sp, const MPoint& ep, int color);
	void draw() override;
};

