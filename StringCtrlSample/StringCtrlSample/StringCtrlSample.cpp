#include<iostream>
#include "MyString.h"
using namespace std;

//MyString.h, MyString.cpp�� �̵� ������ �߰��ϱ�

CMyString TestFunc(void) {
	CMyString strTest("TestFunc() return");
	cout << strTest << endl;		// ��ȯ �����ڷ� ���� �۵� o

	return strTest;
}

int main(int argc, char* argv[])
{
	// �̸� ���� �ӽ� ��ü�� ���������... �̵� �����ڰ� ���� �ȵǴµ�???????
	TestFunc();

	return 0;

}