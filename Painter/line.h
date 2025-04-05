#pragma once

#include "figure.h"

class Line : public Figure {
public:
	Line(Container* myContainer, const MPoint& sp, const MPoint& ep, int color);
	void draw() override;

};