#pragma once
#include "FigureStuff.h"

class Figure : public FigureStuff{
public:
	Figure(Container* myContainer, const MPoint& sp, const MPoint& ep, int color);
protected:
	int myColor_; //색을 나타냄
};

