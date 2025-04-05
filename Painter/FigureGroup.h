#pragma once

#include "FigureStuff.h"
#include "myList.h"

class FigureGroup : public FigureStuff{
private:
	MyList<FigureStuff*> myFigureStuff_;
public:
	FigureGroup(Container* myContainer, const MPoint&, const MPoint&);
	virtual~FigureGroup()override;
	bool addStuff(FigureStuff* s); //stuff�� �Ǵ��ϰ� ���� ��Ų��.
	virtual void draw() override;
	virtual void move(int x, int y) override;
};

