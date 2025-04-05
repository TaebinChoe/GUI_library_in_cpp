#include "PaintPanel.h"
#include "paintFrame.h"
#include "rect.h"
#include "ellipse.h"
#include "line.h"
#include "FigureGroup.h"
#include "button.h"
#include "checkBox.h"
#include "Dialog.h"


PaintPanel::PaintPanel(Frame* myFrame, MPoint start, MPoint end, std::string ment)
	:Panel(start,end,ment), myFrame_(myFrame) {
	//pen들을 생성
	redPen_ = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	bluePen_ = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	blackPen_ = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
}

void PaintPanel::setShape(int shape) {
	shape_ = shape;
}


void PaintPanel::setGridFlag() {
	gridFlag_ = !gridFlag_;
}

void PaintPanel::setGroupFlag() {
	groupFlag_ = !groupFlag_;
}

void PaintPanel::setDialog(Dialog* myDialog) {
	myDialog_ = myDialog;
}

void PaintPanel::fitToGrid() {
	start_.x_ = (start_.x_ + 10) / 20 * 20;
	start_.y_ = (start_.y_ + 10) / 20 * 20;
	end_.x_ = (end_.x_ + 10) / 20 * 20;
	end_.y_ = (end_.y_ + 10) / 20 * 20;
}

void PaintPanel::allClean() {
	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		delete(*i);
		myFigureStuff_.remove(i);
	}
}

void PaintPanel::popStuff() {
	MyList<FigureStuff*>::reverse_iterator ri = myFigureStuff_.rbegin();
	if (ri != myFigureStuff_.rend()) {
		delete (*ri);
		myFigureStuff_.remove(ri);
	}
}

void PaintPanel::startColorPick() {
	if (myDialog_) {
		myFrame_->addComponent(myDialog_);
	}
}

void PaintPanel::endColorPick() {
	Component* temp = myFrame_->popComponent();
}


void PaintPanel::group() {
	//만들어서 
	FigureGroup* temp = new FigureGroup(this, start_, end_);
	
	//리스트에서 찾아서 temp 안의 리스트에 추가 한다
	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		if (temp->addStuff(*i)) {
			myFigureStuff_.remove(i); //검증 필요 !
		}
	}

	//리스트에 넣기
	myFigureStuff_.push_back(temp);
}

void PaintPanel::chagePenColor(int color) {
	switch (color) {
	case RED:
		SelectObject(getHdc(), redPen_);
		break;
	case BLUE:
		SelectObject(getHdc(),bluePen_);
		break;
	default:
		SelectObject(getHdc(), blackPen_);
	}
}

void PaintPanel::repaint(HDC hdc) {
	Panel::repaint(hdc);
	//그림
	//늦게 그린게 위
	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		(*i)->draw();
	}
	/*
	//먼저 그린게 위
	for (MyList<FigureStuff*>::reverse_iterator ri = myFigureStuff_.rbegin(); ri != myFigureStuff_.rend(); ++ri) {
		(*ri)->draw();
	}
	*/
}

PaintPanel::~PaintPanel() {
	for (MyList<FigureStuff*>::iterator i = myFigureStuff_.begin(); i != myFigureStuff_.end(); ++i) {
		delete(*i);
	}
	if (myDialog_) {
		delete myDialog_;
	}
}

FigureStuff* PaintPanel::findStuff(const MPoint& p) {
	for (MyList<FigureStuff*>::reverse_iterator ri = myFigureStuff_.rbegin(); ri != myFigureStuff_.rend(); ++ri) {
		if ((*ri)->isInclude(p)) {
			return (*ri);
		}
	}
	return nullptr;
}

void PaintPanel::actionPerformed(ActionEvent ae) {
	int command = ae.getHostButton()->getCommand();
	switch (command) {
	case UNDETERMINED: case RECTANGLE: case ELLIPSE: case LINE:
		setShape(command);
		break;
	case GRID:
		setGridFlag();
		myFrame_->invalidate();
		break;
	case GROUP:
		setGroupFlag();
		myFrame_->invalidate();
		break;
	case CLEAN:
		allClean();
		myFrame_->invalidate();
		break;
	case POP:
		popStuff();
		myFrame_->invalidate();
		break;
	case DIALOG_ON:
		startColorPick();
		myFrame_->invalidate();
		break;
	case DIALOG_OFF:
		endColorPick();
		myFrame_->invalidate();
		break;
	case RED: case BLUE: case BLACK:
		color_ = command;
		break;
	}
}

void PaintPanel::mousePressed(MEvent e) {
	start_ = e.getPoint();
	if (e.isCtrlKeyDown()) {
		selectedStuff_ = findStuff(start_); //못찾으면 nullptr이 저장됨
	}
}

void PaintPanel::mouseReleased(MEvent e) {
	end_ = e.getPoint();

	if (e.isCtrlKeyDown()) {
		if (selectedStuff_) {
			selectedStuff_->move(end_.x_ - start_.x_, end_.y_ - start_.y_);
			selectedStuff_ = nullptr;
			myFrame_->invalidate();
		}
	}
	else if (groupFlag_) {
		group();
		myGroupCheckBox_->eventHandler(e);//체크 해제
		myFrame_->invalidate();
	}
	else {
		selectedStuff_ = nullptr;

		if (gridFlag_) {
			fitToGrid();
		}
		
		//색 정보를 가지도록 바꿈
		switch (shape_) {
		case UNDETERMINED:
			break;
		case RECTANGLE:
			myFigureStuff_.push_back(new Rect(this, start_, end_,color_));
			myFrame_->invalidate();
			break;
		case ELLIPSE:
			myFigureStuff_.push_back(new Ellip(this, start_, end_,color_));
			myFrame_->invalidate();
			break;
		case LINE:
			myFigureStuff_.push_back(new Line(this, start_, end_,color_));
			myFrame_->invalidate();
		}
	}
}


HDC PaintPanel::getHdc() const {
	return myFrame_->getHdc();
}
