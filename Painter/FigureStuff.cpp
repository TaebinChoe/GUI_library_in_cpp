#include "FigureStuff.h"
#include "Container.h"

FigureStuff::FigureStuff(Container* myContainer, const MPoint& sp, const MPoint& ep) : myContainer_(myContainer){
	//startPos_: 좌상단점 endPos_: 우하단점 으로 정돈해줌
	MPoint tempS;
	MPoint tempE;
	if (sp.x_ <= ep.x_) {
		tempS.x_ = sp.x_;
		tempE.x_ = ep.x_;
	}
	else {
		tempS.x_ = ep.x_;
		tempE.x_ = sp.x_;
	}

	if (sp.y_ <= ep.y_) {
		tempS.y_ = sp.y_;
		tempE.y_ = ep.y_;
	}
	else {
		tempS.y_ = ep.y_;
		tempE.y_ = sp.y_;
	}
	startPos_ = tempS;
	endPos_ = tempE;
}

FigureStuff::~FigureStuff() {}

bool FigureStuff::isInclude(const MPoint& point) {
	return (startPos_.x_ <= point.x_ && point.x_ <= endPos_.x_  && startPos_.y_ <= point.y_ && point.y_ <= endPos_.y_);
}

bool FigureStuff::isInclude(const FigureStuff& stuff) {
	return (isInclude(stuff.startPos_) && isInclude(stuff.endPos_));
}

void FigureStuff::move(int x, int y) {
	startPos_.x_ += x;
	startPos_.y_ += y;

	endPos_.x_ += x;
	endPos_.y_ += y;
}