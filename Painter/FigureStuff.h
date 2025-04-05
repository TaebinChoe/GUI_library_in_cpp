#pragma once

#include "Misc.h"

class Container;

class FigureStuff{
protected:
    Container* myContainer_;
	MPoint startPos_;
	MPoint endPos_;
public:
	FigureStuff(Container* myContainer, const MPoint&, const MPoint&);
	virtual ~FigureStuff();
	virtual void draw() = 0;
	bool isInclude(const MPoint& point);
	bool isInclude(const FigureStuff& stuff); //stuff를 포함하는지

	virtual void move(int x, int y); //(x,y)만큼 평행이동
};
