#include "Panel.h"

Panel::Panel(MPoint start, MPoint end, std::string ment) : Container(start, end, ment) {}

void Panel::repaint(HDC hdc) {
	Component::repaint(hdc); //�׵θ� �׸�
	Container::repaint(hdc);
}
