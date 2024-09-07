#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);		//���� ������ ����
	~CMyString();

private:
	char* m_pszData;	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������	
	int m_nLength;	//����� ���ڿ��� ����

public:
	int SetString(const char* pszParam);
	const char* GetString() const;		//const char* ������ �� const?
	void Release();
	CMyString& operator=(const CMyString& rhs);		//���� ����(?)�� ���� ���� ������ ����
};

