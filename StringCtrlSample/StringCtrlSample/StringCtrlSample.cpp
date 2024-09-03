#include<iostream>
#include "MyString.h"
using namespace std;

int main(int argc, char* argv[])
{
	CMyString strData;
	strData.SetString("Hello");
	cout << strData.GetString() << endl;

	return 0;

}