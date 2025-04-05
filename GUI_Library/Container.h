#pragma once
#include "component.h"
#include "myList.h"

class MouseListener;

//Component의 리스트를 가지는 Component
class Container : public Component{
public:
	Container(std::string ment);
	Container(MPoint start, MPoint end, std::string ment = "");
	virtual ~Container() override;
	virtual void addComponent(Component*);//리스트에만 추가 
	Component* popComponent();//가장 위의 컴포넌트  리스트에서 제거
	Component* findComponent(MPoint pos);
	virtual void repaint(HDC hdc) override;
	virtual void eventHandler(MEvent e) override;
	void addMouseListener(MouseListener* ml);
protected:
	MyList<Component*> myComponents_;
	MyList<MouseListener*> myMouseListeners_; //여러개일 필요가 있을까?
};

