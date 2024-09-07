#include "MyString.h"
#include<iostream>
using namespace std;

CMyString::CMyString()
	:m_pszData(NULL),
	m_nLength(0)
{
}

CMyString::CMyString(const CMyString &rhs)
	:m_pszData(NULL),
	m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::CMyString(const char* pszParam)		//const char *에 대한 변환 생성자
	:m_pszData(NULL),
	m_nLength(0)
{
	SetString(pszParam);
}

CMyString::~CMyString()		// 새로운 문자열 할당에 앞서 기존 정보를 해제
{
	Release();
}


// 매개변수로 전달된 문자열의 길이를 측정하고 m_nLength에 저장
// 매개변수로 전달된 문자열이 저장될 수 있는 메모리를 동적 할당
// 동적 할당한 메모리에 문자열을 저장(m_pszData)
// 매개변수가 NULL이거나 문자열의 길이가 0인 경우를 고려
// 여기서 동적 할당한 메모리는 언제 어디서 해제하는지 생각하고 대응
// 사용자가 다음 예와 같이 이 함수를 2회 호출하는 경우를 생각하고 대응

int CMyString::SetString(const char* pszParam)
{	
	//초기화 및 예외처리
	Release();

	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	//메모리 동적할당 및 문자열 저장
	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData,sizeof(char)* (nLength + 1),pszParam);
	m_nLength = nLength;

	return nLength;
}	// 1. nLength를 선언해서 사용하는 이유는?	2. 포인터 및 동적할당 복습하기	3. sizof 함수

const char* CMyString::GetString() const
{
	return m_pszData;
}


// m_pszData라는 멤버 변수가 가리키는 메모리를 해제
// Relase() 후 바로 SetString()을 호출하는 경우 등 다양한 경우를 고려
void  CMyString::Release()
{
	//메모리 해제
	if (m_pszData != NULL)
		delete[] m_pszData;

	//초기화
	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString& rhs)		//this(포인터)와 SetString(동적할당 및 문자열 저장)으로 깊은 복사, 자료형 뒤 &..?
{
	if(this != &rhs)
		this->SetString(rhs.GetString());		//&rhs의 m_pszParam(GetString 반환값)을 복사

	return *this;		// 포인터 값이 포인터?
}