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
		DIALOG_ON = 8, DIALOG_OFF = 9, RED = 10, BLUE = 11, BLACK = 12;  //모양,동작, 색깔 을 나타냄
	CheckBox* myGroupCheckBox_ = nullptr; //그룹핑이 끝날시 체크 해제를 위함
protected:
	int shape_ = UNDETERMINED;//현재 모양
	bool gridFlag_ = false; //그리드 기능
	bool groupFlag_ = false; //그룹선택 기능

	FigureStuff* selectedStuff_ = nullptr; //이동을 위함

	// 응용을 위해 필요한 변수
	MPoint start_;
	MPoint end_;

	//모양 배열
	MyList<FigureStuff*> myFigureStuff_;

	Frame* myFrame_;
	Dialog* myDialog_ = nullptr; //clolor picker

	HPEN blackPen_;
	HPEN redPen_;
	HPEN bluePen_;

	int color_ = BLACK; //현재 지정된 색
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
	void startColorPick(); //dialog를 frame의 component리스트에 추가
	void endColorPick(); //dialog를 frame의 component리스트에서 제거
	void chagePenColor(int color);

	HDC getHdc() const;
	FigureStuff* findStuff(const MPoint& p);
	//container::eventHandler사용
	virtual void repaint(HDC hdc)override;

	virtual void actionPerformed(ActionEvent ae) override;
	virtual void mousePressed(MEvent e)override;
	virtual void mouseReleased(MEvent e)override;
};

