#include "figure.h"

Figure::Figure(Container* myContainer, const MPoint& sp, const MPoint& ep, int color) 
	: FigureStuff(myContainer, sp, ep), myColor_(color) {}

