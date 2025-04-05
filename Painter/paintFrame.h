#pragma once

#include "frame.h"

class PaintPanel;
class ToolBar;

class PaintFrame : public Frame{
private:
	PaintPanel* myPaintPanel_;
	ToolBar* myToolBar_;
public:
	PaintFrame(std::string title, int width, int height);
	virtual ~PaintFrame() override;
	virtual void initialize() override;
};