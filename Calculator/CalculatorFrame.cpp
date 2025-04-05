#include "CalculatorFrame.h"
#include "CalculatorPanel.h"
#include "StaticText.h"
#include "button.h"

CalculatorFrame::CalculatorFrame(std::string title, int width, int height)
	: Frame(title, width, height) {}

CalculatorFrame::~CalculatorFrame() {
	delete myCalculatorPanel_;
}

void CalculatorFrame::initialize() {
	myCalculatorPanel_ = new CalculatorPanel(this,new StaticText(MPoint(300,100),MPoint(620,158)), MPoint(298, 98), MPoint(622, 485));
	addComponent(myCalculatorPanel_);

	/// line 1
	Button* plusB = new Button(MPoint(300,160),MPoint(380,240), " +");
	plusB->setCommand(CalculatorPanel::PLUS);
	plusB->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(plusB);

	Button* minusB = new Button(MPoint(380, 160), MPoint(460, 240), " -");
	minusB->setCommand(CalculatorPanel::MINUS);
	minusB->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(minusB);

	Button* multiB = new Button(MPoint(460, 160), MPoint(540, 240), " x");
	multiB->setCommand(CalculatorPanel::MULTI);
	multiB->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(multiB);

	Button* divB = new Button(MPoint(540, 160), MPoint(620, 240), " /");
	divB->setCommand(CalculatorPanel::DIVISION);
	divB->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(divB);


	/// line 2
	Button* zero = new Button(MPoint(300, 240), MPoint(380, 320), " 0");
	zero->setCommand(0);
	zero->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(zero);

	Button* one = new Button(MPoint(380, 240), MPoint(460, 320), " 1");
	one->setCommand(1);
	one->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(one);

	Button* two = new Button(MPoint(460, 240), MPoint(540, 320), " 2");
	two->setCommand(2);
	two->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(two);

	Button* three = new Button(MPoint(540, 240), MPoint(620, 320), " 3");
	three->setCommand(3);
	three->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(three);


	/// line 3
	Button* four = new Button(MPoint(300, 320), MPoint(380, 400), " 4");
	four->setCommand(4);
	four->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(four);

	Button* five = new Button(MPoint(380, 320), MPoint(460, 400), " 5");
	five->setCommand(5);
	five->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(five);

	Button* six = new Button(MPoint(460, 320), MPoint(540, 400), " 6");
	six->setCommand(6);
	six->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(six);

	Button* seven = new Button(MPoint(540, 320), MPoint(620, 400), " 7");
	seven->setCommand(7);
	seven->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(seven);


	/// line 4
	Button* eight = new Button(MPoint(300, 400), MPoint(380, 480), " 8");
	eight->setCommand(8);
	eight->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(eight);

	Button* nine = new Button(MPoint(380, 400), MPoint(460, 480), " 9");
	nine->setCommand(9);
	nine->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(nine);

	Button* allCleanB = new Button(MPoint(460, 400), MPoint(540, 480), " AC");
	allCleanB->setCommand(CalculatorPanel::ALLCLEAN);
	allCleanB->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(allCleanB);

	Button* equalB = new Button(MPoint(540, 400), MPoint(620, 480), " =");
	equalB->setCommand(CalculatorPanel::EQUAL);
	equalB->addActionListener(myCalculatorPanel_);
	myCalculatorPanel_->addComponent(equalB);

}