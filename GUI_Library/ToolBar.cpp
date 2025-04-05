#include "ToolBar.h"

ToolBar::ToolBar(MPoint start, MPoint end, std::string ment) 
	: Container(start, end, ment) {}

void ToolBar::repaint(HDC hdc) {
	Component::repaint(hdc); //�׵θ� �׸�
	Container::repaint(hdc);
}

void ToolBar::addComponent(Component* comp) {
	//��ġ �ο�
	//��ư ����� ��� �����ϰ� ���ٸ� �ִ� ��Ȳ�� ����
	if (myComponents_.empty()) {
		comp->setStartX(startX_ + 3);
		comp->setStartY(startY_ + 3);
	}
	else {
		comp->setStartX(3 + myComponents_.back()->getEndX());
		comp->setStartY(startY_ + 3);
	}

	//����Ʈ�� �߰�
	myComponents_.push_back(comp);
}