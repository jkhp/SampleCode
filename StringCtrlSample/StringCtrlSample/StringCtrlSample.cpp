#include<iostream>
#include "MyString.h"
using namespace std;

//MyString.h, MyString.cpp에 const char *에 대한 변환 생성자와 char *로의 형변환 연산자를 만들어 넣어 작동하게 만들기

void TestFunc(const CMyString &strParam) {
	cout << strParam << endl;
}

int main(int argc, char* argv[])
{
	CMyString strData("Hello");

	::TestFunc(strData);
	::TestFunc(CMyString("World"));

	return 0;

}