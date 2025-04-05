#include "ToolBar.h"

ToolBar::ToolBar(MPoint start, MPoint end, std::string ment) 
	: Container(start, end, ment) {}

void ToolBar::repaint(HDC hdc) {
	Component::repaint(hdc); //테두리 그림
	Container::repaint(hdc);
}

void ToolBar::addComponent(Component* comp) {
	//위치 부여
	//버튼 모양이 모두 일정하고 한줄만 있는 상황을 가정
	if (myComponents_.empty()) {
		comp->setStartX(startX_ + 3);
		comp->setStartY(startY_ + 3);
	}
	else {
		comp->setStartX(3 + myComponents_.back()->getEndX());
		comp->setStartY(startY_ + 3);
	}

	//리스트에 추가
	myComponents_.push_back(comp);
}