#include<iostream>
#include "MyString.h"
using namespace std;

int main(int argc, char* argv[])
{
	// MyString.h, MyString.cpp�� �����ؼ� �����ϰ� �����
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	//���� ����
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	// �ܼ� ���� ������ ȣ��
	strNewData = strTest;
	cout << strNewData.GetString() << endl;

	return 0;

}