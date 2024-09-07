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

CMyString::CMyString(const char* pszParam)		//const char *�� ���� ��ȯ ������
	:m_pszData(NULL),
	m_nLength(0)
{
	SetString(pszParam);
}

CMyString::~CMyString()		// ���ο� ���ڿ� �Ҵ翡 �ռ� ���� ������ ����
{
	Release();
}


// �Ű������� ���޵� ���ڿ��� ���̸� �����ϰ� m_nLength�� ����
// �Ű������� ���޵� ���ڿ��� ����� �� �ִ� �޸𸮸� ���� �Ҵ�
// ���� �Ҵ��� �޸𸮿� ���ڿ��� ����(m_pszData)
// �Ű������� NULL�̰ų� ���ڿ��� ���̰� 0�� ��츦 ���
// ���⼭ ���� �Ҵ��� �޸𸮴� ���� ��� �����ϴ��� �����ϰ� ����
// ����ڰ� ���� ���� ���� �� �Լ��� 2ȸ ȣ���ϴ� ��츦 �����ϰ� ����

int CMyString::SetString(const char* pszParam)
{	
	//�ʱ�ȭ �� ����ó��
	Release();

	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	//�޸� �����Ҵ� �� ���ڿ� ����
	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData,sizeof(char)* (nLength + 1),pszParam);
	m_nLength = nLength;

	return nLength;
}	// 1. nLength�� �����ؼ� ����ϴ� ������?	2. ������ �� �����Ҵ� �����ϱ�	3. sizof �Լ�

const char* CMyString::GetString() const
{
	return m_pszData;
}


// m_pszData��� ��� ������ ����Ű�� �޸𸮸� ����
// Relase() �� �ٷ� SetString()�� ȣ���ϴ� ��� �� �پ��� ��츦 ���
void  CMyString::Release()
{
	//�޸� ����
	if (m_pszData != NULL)
		delete[] m_pszData;

	//�ʱ�ȭ
	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString& rhs)		//this(������)�� SetString(�����Ҵ� �� ���ڿ� ����)���� ���� ����, �ڷ��� �� &..?
{
	if(this != &rhs)
		this->SetString(rhs.GetString());		//&rhs�� m_pszParam(GetString ��ȯ��)�� ����

	return *this;		// ������ ���� ������?
}