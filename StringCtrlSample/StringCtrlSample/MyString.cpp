#include "MyString.h"
#include<iostream>
using namespace std;

CMyString::CMyString()
	:m_pszData(NULL),
	m_nLength(0)
{

}

CMyString::~CMyString()
{

}

int CMyString::SetString(const char* pszParam)
{
	// TODO: 여기에 구현 코드 추가.
	return 0;
}

const char* CMyString::GetString()
{
	return NULL;
}

void  CMyString::Release()
{
}