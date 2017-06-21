#pragma once

#include "BaseApp.h"
#include <conio.h>
#include <ctime>

class TestApp : public BaseApp {
	typedef BaseApp Parent;
	private:
		int mObj1XOld;
		int mObj1YOld;
		int mObj1X;
		int mObj1Y;

		int mObj2XOld;
		int mObj2YOld;
		int mObj2X;
		int mObj2Y;

		int mObj3XOld;
		int mObj3YOld;
		int mObj3X;
		int mObj3Y;

		int mObj4XOld;
		int mObj4YOld;
		int mObj4X;
		int mObj4Y;

		int score;
		int pattern;
	
	public:
		TestApp();
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		void insertBlock();
		void deleteRow();
		void checkRow();
		void deleteColumn(int i);
		void rotateBlock();
		bool isFull();
		void newBlock();

		void setPattern1(int x, int y);
		void setPattern2(int x, int y);
		void setPattern3(int x, int y);
		void setPattern4(int x, int y);
		void setPattern5(int x, int y);
		void setPattern6(int x, int y);
		void setPattern7(int x, int y);
		void setPattern8(int x, int y);
		void setPattern9(int x, int y);
		void setPattern10(int x, int y);
		void setPattern11(int x, int y);
		void setPattern12(int x, int y);
		void setPattern13(int x, int y);
		void setPattern14(int x, int y);
		void setPattern15(int x, int y);

		void clean();
};
