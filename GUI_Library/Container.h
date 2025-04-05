#pragma once
#include "component.h"
#include "myList.h"

class MouseListener;

//Component�� ����Ʈ�� ������ Component
class Container : public Component{
public:
	Container(std::string ment);
	Container(MPoint start, MPoint end, std::string ment = "");
	virtual ~Container() override;
	virtual void addComponent(Component*);//����Ʈ���� �߰� 
	Component* popComponent();//���� ���� ������Ʈ  ����Ʈ���� ����
	Component* findComponent(MPoint pos);
	virtual void repaint(HDC hdc) override;
	virtual void eventHandler(MEvent e) override;
	void addMouseListener(MouseListener* ml);
protected:
	MyList<Component*> myComponents_;
	MyList<MouseListener*> myMouseListeners_; //�������� �ʿ䰡 ������?
};

