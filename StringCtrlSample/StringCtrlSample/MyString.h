#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();

private:
	char* m_pszData;	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������	
	int m_nLength;	//����� ���ڿ��� ����

public:
	int SetString(const char* pszParam);
	const char* GetString() const;		//const char* ������ �� const?
	void Release();
};

