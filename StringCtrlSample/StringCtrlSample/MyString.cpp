#include "MyString.h"
#include<iostream>
using namespace std;

CMyString::CMyString()
	:m_pszData(NULL),
	m_nLength(0)
{
}

CMyString::CMyString(const char* pszParam)		//const char *�� ���� ��ȯ ������
	:m_pszData(NULL),
	m_nLength(0)
{
	SetString(pszParam);
}
//���� ������
CMyString::CMyString(const CMyString &rhs)
	:m_pszData(NULL),
	m_nLength(0)
{
	this->SetString(rhs.GetString());
}

//�̵� ������
CMyString::CMyString(CMyString &&rhs) 
	:m_pszData(NULL),
	m_nLength(0)
{
	cout << "CMyString �̵� ������ ȣ��" << endl;
	
	// ����(������ ��ü)�� �� �Ҹ�ǹǷ� ���ο� ��ü�� ���� ����
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// ���� �ӽ� ��ü�� �ɹ����� �ʱ�ȭ�Ѵ�. �����ϸ� �ȵ� (������?)
	// rhs�� NULL�� �ʱ�ȭ ���ֹǷ� �� �����Ͱ� ���� ����� ����ų ���� ���� => ������ �Ҹ��Ұǵ� ���� �ʿ��Ѱ�? => ��ü�� �ƴ϶� m_pszData�� �����Ͷ� ������ �߱�?  
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
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

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	//�Ű����� ��ȿ�� �˻�
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	//��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó��
	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	//���� ���ڿ��� ���� ���
	int nLenCur = m_nLength;

	//�� ���ڿ��� ���ļ� ������ �� �ִ� �޸𸮸� ���� �Ҵ�
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// ���ڿ� ����
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur),
		sizeof(char) * (nLenParam + 1), pszParam);

	//���� ���ڿ� ���� �� ��� ���� ����
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString& rhs)
{


}
CMyString& CMyString::operator+=(const CMyString& rhs)
{


}