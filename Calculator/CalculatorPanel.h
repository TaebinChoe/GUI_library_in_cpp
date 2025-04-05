#pragma once
#include "Panel.h"
#include "ActionListener.h"

class StaticText;

class CalculatorPanel : public Panel, public ActionListener {
public:
	static const int  PLUS = 10, MINUS = 11, MULTI = 12, DIVISION = 13, EQUAL = 14, ALLCLEAN = 15, NOTREADY = 16;//연산 명령들
private:
	Frame* myFrame_;
	StaticText* myScreen_; //정답 화면
	int Num1_ = 0;
	int Num2_ = 0;
	int operOnHand_ = NOTREADY; //준비된연산
public:
	CalculatorPanel(Frame* myFrame,StaticText* myScreen, MPoint start, MPoint end, std::string ment = "");
	virtual void actionPerformed(ActionEvent ae) override;
};

