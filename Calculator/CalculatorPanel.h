#pragma once
#include "Panel.h"
#include "ActionListener.h"

class StaticText;

class CalculatorPanel : public Panel, public ActionListener {
public:
	static const int  PLUS = 10, MINUS = 11, MULTI = 12, DIVISION = 13, EQUAL = 14, ALLCLEAN = 15, NOTREADY = 16;//���� ��ɵ�
private:
	Frame* myFrame_;
	StaticText* myScreen_; //���� ȭ��
	int Num1_ = 0;
	int Num2_ = 0;
	int operOnHand_ = NOTREADY; //�غ�ȿ���
public:
	CalculatorPanel(Frame* myFrame,StaticText* myScreen, MPoint start, MPoint end, std::string ment = "");
	virtual void actionPerformed(ActionEvent ae) override;
};

