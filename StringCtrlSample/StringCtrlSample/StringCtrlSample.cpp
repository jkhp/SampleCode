#include<iostream>
#include "MyString.h"
using namespace std;

//MyString.h, MyString.cpp�� const char *�� ���� ��ȯ �����ڿ� char *���� ����ȯ �����ڸ� ����� �־� �۵��ϰ� �����

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