#pragma once
#include "Windows.h"
#include <string>
#include "myList.h"
#include "Misc.h"
#include "Container.h"

class Component;
class Figure;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Frame : public Container{
protected:
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;	 // ���� �ڵ��� �����صд�.
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.

	//MPoint start_;
	//MPoint end_;
	
public:
	Frame();
	virtual~Frame();
	Frame(std::string, int, int);

	virtual void run();
	virtual void repaint(HDC hdc) override;
	void invalidate();
	
	HDC getHdc() const;

	virtual void initialize() = 0;
};
