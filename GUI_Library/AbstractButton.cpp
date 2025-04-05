#include "AbstractButton.h"
#include "ActionListener.h"

AbstractButton::AbstractButton(std::string ment) : Component(ment) {}

AbstractButton::AbstractButton(MPoint start, MPoint end, std::string ment) : Component(start, end, ment) {}

AbstractButton::~AbstractButton() {
	for (MyList<ActionListener*>::iterator i = myActionListeners_.begin(); i != myActionListeners_.end(); ++i) {
		delete (*i);
	}
}

void AbstractButton::eventHandler(MEvent e) {
	if (e.isLButtonUpEvent()){
		for (MyList<ActionListener*>::iterator i = myActionListeners_.begin(); i != myActionListeners_.end(); ++i) {
			(*i)->actionPerformed(e.makeActionEvent(this));
		}
	}
}

int AbstractButton::getCommand() const {
	return command_;
}

void AbstractButton::setCommand(int command) {
	command_ = command;
}

void AbstractButton::addActionListener(ActionListener* listener) {
	myActionListeners_.push_back(listener);
}
