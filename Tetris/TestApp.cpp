#include "TestApp.h"

TestApp::TestApp() : Parent(20, 30) {
	score = 0;
	mObj1XOld = 0;
	mObj1YOld = 0;
	mObj1X = 0;
	mObj1Y = 0;
	mObj2XOld = 0;
	mObj2YOld = 0;
	mObj2X = 0;
	mObj2Y = 0;
	mObj3XOld = 0;
	mObj3YOld = 0;
	mObj3X = 0;
	mObj3Y = 0;
	mObj4XOld = 0;
	mObj4YOld = 0;
	mObj4X = 0;
	mObj4Y = 0;
	newBlock();
}

void TestApp::KeyPressed(int btnCode) {
	switch (btnCode) {
	case 32: {
		rotateBlock();
		break;
	}
	case 115: { //s
		if (mObj1Y < Y_SIZE - 1) {
			mObj1Y++;
			mObj2Y++;
			mObj3Y++;
			mObj4Y++;
		}
		break;
		}
	case 97: { //a
		if (mObj1X > 0) {
			mObj1X--;
			mObj2X--;
			mObj3X--;
			mObj4X--;
		}
		break;
		}
	case 100: { //d
		if (mObj4X < X_SIZE) {
			mObj1X++;
			mObj2X++;
			mObj3X++;
			mObj4X++;
		}
		break;
		}
	}
}

void TestApp::UpdateF(float deltaTime) {
	if (isFull()) {
		system("cls");
		printf("Game over!\nYour score: %d", score);
		_getch();
		exit (0);
	}
	
	if (pattern == 1 || pattern == 5 || pattern == 10 || pattern == 14) {
		SetChar(mObj3XOld, mObj3YOld, L' ');
		SetChar(mObj3X, mObj3Y, L'O');
		SetChar(mObj4XOld, mObj4YOld, L' ');
		SetChar(mObj4X, mObj4Y, L'O');
	}
	SetChar(mObj1XOld, mObj1YOld, L' ');
	SetChar(mObj1X, mObj1Y, L'O');
	SetChar(mObj2XOld, mObj2YOld, L' ');
	SetChar(mObj2X, mObj2Y, L'O');
	if (pattern == 2 || pattern == 3 || pattern == 4 || pattern == 6 || pattern == 7 || pattern == 8 || pattern == 11 || pattern == 12) {
		SetChar(mObj3XOld, mObj3YOld, L' ');
		SetChar(mObj3X, mObj3Y, L'O');
		SetChar(mObj4XOld, mObj4YOld, L' ');
		SetChar(mObj4X, mObj4Y, L'O');
	}
	if (pattern == 9 || pattern == 13 || pattern == 15) {
		SetChar(mObj4XOld, mObj4YOld, L' ');
		SetChar(mObj4X, mObj4Y, L'O');
		SetChar(mObj3XOld, mObj3YOld, L' ');
		SetChar(mObj3X, mObj3Y, L'O');
	}
	mObj1XOld = mObj1X;
	mObj1YOld = mObj1Y;
	mObj2XOld = mObj2X;
	mObj2YOld = mObj2Y;
	mObj3XOld = mObj3X;
	mObj3YOld = mObj3Y;
	mObj4XOld = mObj4X;
	mObj4YOld = mObj4Y;
	if (mObj1Y == Y_SIZE - 1 || mObj2Y == Y_SIZE - 1 || mObj3Y == Y_SIZE - 1 || mObj4Y == Y_SIZE - 1) {
		insertBlock();
		checkRow();
		}
	else {
		if (GetChar(mObj1X, mObj1Y + 1) == L'M' || GetChar(mObj2X, mObj2Y + 1) == L'M' || GetChar(mObj3X, mObj3Y + 1) == L'M' || GetChar(mObj4X, mObj4Y + 1) == L'M')
			insertBlock();
		else {
			mObj1Y++;
			mObj2Y++;
			mObj3Y++;
			mObj4Y++;
			Sleep(250);
		}		
	}
}

void TestApp::insertBlock() {
	SetChar(mObj1X, mObj1Y, L'M');
	SetChar(mObj2X, mObj2Y, L'M');
	SetChar(mObj3X, mObj3Y, L'M');
	SetChar(mObj4X, mObj4Y, L'M');
	newBlock();
}

void TestApp::checkRow() {
	for (int k = 0; k < X_SIZE; k++) {
		if (GetChar(k, Y_SIZE - 1) == L' ')
			return;
	}
	deleteRow();
	checkRow();
	checkRow();
	checkRow();
}

void TestApp::deleteRow() {
	score += 10;
	for (int i = 0; i < X_SIZE; i++) {
		SetChar(i, Y_SIZE - 1, L' ');
		deleteColumn(i);
	}
}

void TestApp::deleteColumn(int i) {
	for (int j = Y_SIZE - 1; j > 0; j--) {
		SetChar(i, j, GetChar(i, j - 1));
	}
}

void TestApp::rotateBlock() {
	clean();
	switch (pattern) {
	case 1: {
		break;
	}
	case 2: {
		pattern = 3;
		setPattern3(mObj1X, mObj1Y - 2);
		break;
	}
	case 3: {
		pattern = 2;
		setPattern2(mObj1X, mObj1Y - 2);
		break;
	}
	case 4: {
		pattern = 5;
		setPattern5(mObj1X, mObj1Y);
		break;
	}
	case 5: {
		pattern = 6;
		setPattern6(mObj1X, mObj1Y);
		break;
	}
	case 6: {
		pattern = 7;
		setPattern7(mObj1X, mObj1Y);
		break;
	}
	case 7: {
		pattern = 4;
		setPattern4(mObj1X, mObj1Y);
		break;
	}
	case 8: {
		pattern = 9;
		setPattern9(mObj1X, mObj1Y);
		break;
	}
	case 9: {
		pattern = 10;
		setPattern10(mObj1X, mObj1Y);
		break;
	}
	case 10: {
		pattern = 11;
		setPattern11(mObj1X, mObj1Y);
		break;
	}
	case 11: {
		pattern = 8;
		setPattern8(mObj1X, mObj1Y);
		break;
	}
	case 12: {
		pattern = 13;
		setPattern13(mObj1X, mObj1Y);
		break;
	}
	case 13: {
		pattern = 14;
		setPattern14(mObj1X, mObj1Y);
		break;
	}
	case 14: {
		pattern = 15;
		setPattern15(mObj1X, mObj1Y);
		break;
	}
	case 15: {
		pattern = 12;
		setPattern12(mObj1X, mObj1Y);
		break;
	}
	}
}

bool TestApp::isFull() {
	for (int i = 0; i <= X_SIZE; i++) {
		if (GetChar(i, 0) == L'M' || GetChar(i, 1) == L'M')
			return true;
	}
	return false;
}

void TestApp::setPattern1(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = x;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y + 1;
}

void TestApp::setPattern2(int x, int y) {
	mObj1XOld = mObj1X = (x * 2) / 3;
	mObj1YOld = mObj1Y = y;
	mObj2XOld = mObj2X = ((x * 2) / 3) + 1;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = ((x * 2) / 3) + 2;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = ((x * 2) / 3) + 3;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern3(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 3;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y + 2;
	mObj3XOld = mObj3X = x;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern4(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 1;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y + 2;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern5(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 1;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 2;
	mObj4YOld = mObj4Y = y + 1;
}

void TestApp::setPattern6(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 2;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y + 1;
	mObj3XOld = mObj3X = x;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y + 1;
}

void TestApp::setPattern7(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y + 1;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = x + 2;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern8(int x, int y) {
	if ((y + 2) >= Y_SIZE - 1)
		y -= 2;
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 2;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y + 1;
	mObj3XOld = mObj3X = x;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern9(int x, int y) {
	if ((y + 2) >= Y_SIZE - 1)
		y -= 2;
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y + 2;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y + 1;
}

void TestApp::setPattern10(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 1;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 2;
	mObj4YOld = mObj4Y = y + 1;
}

void TestApp::setPattern11(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 1;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = x + 2;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern12(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 2;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y + 1;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y;
}

void TestApp::setPattern13(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 1;
	mObj2XOld = mObj2X = x;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 1;
	mObj4YOld = mObj4Y = y + 2;
}

void TestApp::setPattern14(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y + 1;
	mObj4XOld = mObj4X = x + 2;
	mObj4YOld = mObj4Y = y + 1;
}

void TestApp::setPattern15(int x, int y) {
	mObj1XOld = mObj1X = x;
	mObj1YOld = mObj1Y = y + 1;
	mObj2XOld = mObj2X = x + 1;
	mObj2YOld = mObj2Y = y + 1;
	mObj3XOld = mObj3X = x + 1;
	mObj3YOld = mObj3Y = y;
	mObj4XOld = mObj4X = x + 2;
	mObj4YOld = mObj4Y = y;
}

void TestApp::newBlock() {
	srand((unsigned int)time(0));
	pattern = 0 + rand() % 16;
	int x = X_SIZE / 2;
	int y = 0;
	switch (pattern) {
	case 1: {
		setPattern1(x, y);
		break;
	}
	case 2: {
		setPattern2(x, y);
		break;
	}
	case 3: {
		setPattern3(x, y);
		break;
	}
	case 4: {
		setPattern4(x, y);
		break;
	}
	case 5: {
		setPattern5(x, y);
		break;
	}
	case 6: {
		setPattern6(x, y);
		break;
	}
	case 7: {
		setPattern7(x, y);
		break;
	}
	case 8: {
		setPattern8(x, y);
		break;
	}
	case 9: {
		setPattern9(x, y);
		break;
	}
	case 10: {
		setPattern10(x, y);
		break;
	}
	case 11: {
		setPattern11(x, y);
		break;
	}
	case 12: {
		setPattern12(x, y);
		break;
	}
	case 13: {
		setPattern13(x, y);
		break;
	}
	case 14: {
		setPattern14(x, y);
		break;
	}
	case 15: {
		setPattern15(x, y);
		break;
		}
	}
}

void TestApp::clean() {
	SetChar(mObj1X, mObj1Y, L' ');
	SetChar(mObj2X, mObj2Y, L' ');
	SetChar(mObj3X, mObj3Y, L' ');
	SetChar(mObj4X, mObj4Y, L' ');

	SetChar(mObj1XOld, mObj1YOld, L' ');
	SetChar(mObj2XOld, mObj2YOld, L' ');
	SetChar(mObj3XOld, mObj3YOld, L' ');
	SetChar(mObj4XOld, mObj4YOld, L' ');
}