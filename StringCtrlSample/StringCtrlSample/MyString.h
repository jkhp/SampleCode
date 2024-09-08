#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);		//복사 생성자 선언
	explicit CMyString(const char *pszParam);			//const char* 에 대한 변환 생성자
	CMyString(CMyString &&rhs);		// 이동생성자
	~CMyString();

	operator char* (void) const { return m_pszData; }		//형변환 생성자, const를 달지 않으면 TestFunc의 cout에서 에러 발생?

private:
	char* m_pszData;	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터	
	int m_nLength;	//저장된 문자열의 길이

public:
	int SetString(const char* pszParam);
	const char* GetString() const;		//const char* 다음에 또 const?
	void Release();
	CMyString& operator=(const CMyString& rhs);		//깊은 복사(?)를 위한 대입 연산자 정의
};

