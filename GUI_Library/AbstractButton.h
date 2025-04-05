#pragma once
#include "component.h"
#include "myList.h"

class AbstractButton :  public Component{
private:
	int command_ = 0;

protected:
	MyList<ActionListener*> myActionListeners_; //여러개의 action을 listener를 가질 수도 있으니
public:
	AbstractButton(std::string ment);
	AbstractButton(MPoint start, MPoint end, std::string ment = "");
	~AbstractButton();
	void addActionListener(ActionListener* listener);
	void setCommand(int command);
	int getCommand() const;
	virtual void eventHandler(MEvent e) override;
};


