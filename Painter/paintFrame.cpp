#include "paintFrame.h"
#include "rect.h"
#include "ellipse.h"
#include "line.h"
#include "FigureGroup.h"
#include "button.h"
#include "checkBox.h"
#include "ActionListener.h"
#include "PaintPanel.h"
#include "ToolBar.h"
#include "Dialog.h"
#include "ColorButton.h"


PaintFrame::PaintFrame(std::string title, int width, int height)
	: Frame(title, width, height){}

PaintFrame::~PaintFrame() {
	delete myPaintPanel_;
	delete myToolBar_;
}

void PaintFrame::initialize() {
	//toolBar만들기
	//toolBar에 Button 추가
	myToolBar_ = new ToolBar(MPoint(5, 5), MPoint(900, 32));
	myPaintPanel_ = new PaintPanel(this,MPoint(5,34), MPoint(900,700)); 

	Button* rectB = new Button("Rectangle");
	rectB->setCommand(PaintPanel::RECTANGLE);
	rectB->addActionListener(myPaintPanel_);

	Button* ellipB = new Button("Ellipse");
	ellipB->setCommand(PaintPanel::ELLIPSE);
	ellipB->addActionListener(myPaintPanel_);

	Button* lineB = new Button("Line");
	lineB->setCommand(PaintPanel::LINE);
	lineB->addActionListener(myPaintPanel_);

	Button* cleaner = new Button("All Clean");
	cleaner->setCommand(PaintPanel::CLEAN);
	cleaner->addActionListener(myPaintPanel_);

	Button* poper = new Button("    <----");
	poper->setCommand(PaintPanel::POP);
	poper->addActionListener(myPaintPanel_);

	Button* colorP = new Button("Color Picker");
	colorP->setCommand(PaintPanel::DIALOG_ON);
	colorP->addActionListener(myPaintPanel_);

	myToolBar_ -> addComponent(rectB);
	myToolBar_ -> addComponent(ellipB);
	myToolBar_ -> addComponent(lineB);
	myToolBar_ -> addComponent(cleaner);
	myToolBar_->addComponent(poper);
	myToolBar_->addComponent(colorP);

	//ToolBar에 checkBox추가
	//grid
	CheckBox* gridC = new CheckBox("Fit to grid");
	gridC->setCommand(PaintPanel::GRID);
	gridC->addActionListener(myPaintPanel_);

	//group
	myPaintPanel_->myGroupCheckBox_ = new CheckBox("Grouping");
	myPaintPanel_->myGroupCheckBox_->setCommand(PaintPanel::GROUP);
	myPaintPanel_->myGroupCheckBox_->addActionListener(myPaintPanel_);

	myToolBar_->addComponent(gridC);
	myToolBar_->addComponent(myPaintPanel_->myGroupCheckBox_);


	//cololrPicker만들어 두기
	Dialog* colorPicker = new Dialog(MPoint(300,200), MPoint(600,350));

	Button* confirmB = new Button(MPoint(480,300),MPoint(580,340),"Confirm");
	confirmB->setCommand(PaintPanel::DIALOG_OFF);
	confirmB->addActionListener(myPaintPanel_);

	ColorButton* redB = new ColorButton(MPoint(305, 210), MPoint(395, 250), PaintPanel::RED,"Red");
	redB->setCommand(PaintPanel::RED);
	redB->addActionListener(myPaintPanel_);

	ColorButton* blueB = new ColorButton(MPoint(405, 210), MPoint(495, 250),PaintPanel::BLUE, "Blue");
	blueB->setCommand(PaintPanel::BLUE);
	blueB->addActionListener(myPaintPanel_);

	ColorButton* blackB = new ColorButton(MPoint(505, 210), MPoint(595, 250),PaintPanel::BLACK, "Balck");
	blackB->setCommand(PaintPanel::BLACK);
	blackB->addActionListener(myPaintPanel_);

	colorPicker->addComponent(confirmB);
	colorPicker->addComponent(redB);
	colorPicker->addComponent(blueB);
	colorPicker->addComponent(blackB);

	myPaintPanel_->setDialog(colorPicker); //바로 리스트에 추가하지 않고 Panel이 멤버로 가지고 있다가 필요할때 리스트에 넣고 뺌

	myPaintPanel_ ->addMouseListener(myPaintPanel_); //마우스리스너 추가해주기

	//리스트에 component추가
	addComponent(myPaintPanel_); //리스트에 panel추가
	addComponent(myToolBar_); //리스트에 toolBar추가
}
