#include "CalculatorPanel.h"
#include "StaticText.h"
#include "button.h"
#include "CalculatorFrame.h"

CalculatorPanel::CalculatorPanel(Frame* myFrame,StaticText* myScreen, MPoint start, MPoint end, std::string ment)
	:Panel(start, end, ment),myFrame_(myFrame), myScreen_(myScreen) {
	addComponent(myScreen_); //리스트에 넣고 시작
	myScreen_->setMent("0");
}

void CalculatorPanel::actionPerformed(ActionEvent ae) {
	int command = ae.getHostButton()->getCommand();

	//알고리즘 수정 필요
	switch (command) {
	case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
		if (operOnHand_ == NOTREADY) {
			Num1_ = (Num1_ * 10) + command;
			myScreen_->setMent(std::to_string(Num1_));
		}
		else {
			Num2_ = (Num2_ * 10) + command;
			std::string msg = std::to_string(Num1_);

			switch (operOnHand_) {
			case PLUS:
				msg += " + ";
				break;
			case MINUS:
				msg += " - ";
				break;
			case MULTI:
				msg += " x ";
				break;
			case DIVISION:
				msg += " / ";
				break;
			}
			myScreen_->setMent(msg + std::to_string(Num2_));
		}
		break;

	case PLUS:
		myScreen_->setMent(myScreen_->getMent() + " + ");
		operOnHand_ = PLUS;
		break;
	case MINUS:
		myScreen_->setMent(myScreen_->getMent() + " - ");
		operOnHand_ = MINUS;
		break;
	case MULTI:
		myScreen_->setMent(myScreen_->getMent() + " x ");
		operOnHand_ = MULTI;
		break;
	case DIVISION:
		myScreen_->setMent(myScreen_->getMent() + " / ");
		operOnHand_ = DIVISION;
		break;
	case EQUAL:
		switch (operOnHand_) {
		case PLUS:
			Num1_ += Num2_;
			Num2_ = 0;
			break;
		case MINUS:
			Num1_ -= Num2_;
			Num2_ = 0;
			break;
		case MULTI:
			Num1_ *= Num2_;
			Num2_ = 0;
			break;
		case DIVISION:
			Num1_ /= Num2_;
			Num2_ = 0;
			break;
		}
		myScreen_->setMent(std::to_string(Num1_));
		operOnHand_ = NOTREADY;
		break;
	case ALLCLEAN:
		Num1_ = 0;
		Num2_ = 0;
		myScreen_->setMent("0");
		operOnHand_ = NOTREADY;
		break;
	}
	myFrame_->invalidate();
	
}