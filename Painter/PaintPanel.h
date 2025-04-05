#pragma once
#include "Panel.h"
#include "ActionListener.h"
#include "MouseListener.h"

class CheckBox;
class FigureStuff;
class Dialog;

class PaintPanel : public Panel, public ActionListener, public MouseListener{
public:
	static const int UNDETERMINED = 0, RECTANGLE = 1, ELLIPSE = 2, LINE = 3
		, GRID = 4, GROUP = 5, CLEAN = 6, POP = 7, 
		DIALOG_ON = 8, DIALOG_OFF = 9, RED = 10, BLUE = 11, BLACK = 12;  //���,����, ���� �� ��Ÿ��
	CheckBox* myGroupCheckBox_ = nullptr; //�׷����� ������ üũ ������ ����
protected:
	int shape_ = UNDETERMINED;//���� ���
	bool gridFlag_ = false; //�׸��� ���
	bool groupFlag_ = false; //�׷켱�� ���

	FigureStuff* selectedStuff_ = nullptr; //�̵��� ����

	// ������ ���� �ʿ��� ����
	MPoint start_;
	MPoint end_;

	//��� �迭
	MyList<FigureStuff*> myFigureStuff_;

	Frame* myFrame_;
	Dialog* myDialog_ = nullptr; //clolor picker

	HPEN blackPen_;
	HPEN redPen_;
	HPEN bluePen_;

	int color_ = BLACK; //���� ������ ��
public:
	PaintPanel(Frame* myFrame, MPoint start, MPoint end, std::string ment = "");
	virtual ~PaintPanel() override;
	void setShape(int);
	void setGridFlag();
	void setGroupFlag();
	void setDialog(Dialog* myDialog);
	void fitToGrid();
	void group();
	void allClean();
	void popStuff();
	void startColorPick(); //dialog�� frame�� component����Ʈ�� �߰�
	void endColorPick(); //dialog�� frame�� component����Ʈ���� ����
	void chagePenColor(int color);

	HDC getHdc() const;
	FigureStuff* findStuff(const MPoint& p);
	//container::eventHandler���
	virtual void repaint(HDC hdc)override;

	virtual void actionPerformed(ActionEvent ae) override;
	virtual void mousePressed(MEvent e)override;
	virtual void mouseReleased(MEvent e)override;
};

