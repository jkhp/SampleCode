#include<iostream>
#include "MyString.h"
using namespace std;

//MyString.h, MyString.cpp에 이동 생성자 추가하기

CMyString TestFunc(void) {
	CMyString strTest("TestFunc() return");
	cout << strTest << endl;		// 변환 생성자로 인해 작동 o

	return strTest;
}

int main(int argc, char* argv[])
{
	// 이름 없는 임시 객체가 만들어진다... 이동 생성자가 실행 안되는데???????
	TestFunc();

	return 0;

}