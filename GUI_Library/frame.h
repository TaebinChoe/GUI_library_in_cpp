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
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;	 // 윈도 핸들을 저장해둔다.
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

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
