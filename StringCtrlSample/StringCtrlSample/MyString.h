#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);		//���� ������ ����
	explicit CMyString(const char *pszParam);			//const char* �� ���� ��ȯ ������
	CMyString(CMyString &&rhs);		// �̵�������
	~CMyString();

	operator char* (void) const { return m_pszData; }		//����ȯ ������, const�� ���� ������ TestFunc�� cout���� ���� �߻�?

private:
	char* m_pszData;	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������	
	int m_nLength;	//����� ���ڿ��� ����

public:
	int SetString(const char* pszParam);
	const char* GetString() const;		//const char* ������ �� const?
	void Release();
	CMyString& operator=(const CMyString& rhs);		//���� ����(?)�� ���� ���� ������ ����
};

