#include "FigureGroup.h"
#include "PaintPanel.h"

FigureGroup::FigureGroup(Container* myContainer, const MPoint& sp, const MPoint& ep)
	: FigureStuff(myContainer,sp,ep){}

FigureGroup::~FigureGroup() {
	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		delete (*i);
	}
}

void FigureGroup::draw() {
	//점선으로 테두리 표시
	HPEN dotPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(static_cast<PaintPanel*>(myContainer_)->getHdc(), dotPen);
	Rectangle(static_cast<PaintPanel*>(myContainer_)->getHdc(), startPos_.x_, startPos_.y_, endPos_.x_, endPos_.y_);
	SelectObject(static_cast<PaintPanel*>(myContainer_)->getHdc(), oldPen);

	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		(*i)->draw();
	}
}

bool FigureGroup::addStuff(FigureStuff* s) {
	if (isInclude(*s)) {
		myFigureStuff_.push_back(s);
		return true;
	}
	return false;
}

void FigureGroup::move(int x, int y) {
	FigureStuff::move(x, y);

	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		(*i)->move(x,y);
	}
}