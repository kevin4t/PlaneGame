////////////////////////////////// HttpClient.cpp
#include "StdAfx.h"
#include "HttpClient.h"

#define  BUFFER_SIZE       1024

#define  NORMAL_CONNECT             INTERNET_FLAG_KEEP_CONNECTION
#define  SECURE_CONNECT             NORMAL_CONNECT | INTERNET_FLAG_SECURE
#define  NORMAL_REQUEST             INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE
#define  SECURE_REQUEST             NORMAL_REQUEST | INTERNET_FLAG_SECURE | \
									INTERNET_FLAG_IGNORE_CERT_CN_INVALID| \
									INTERNET_FLAG_IGNORE_CERT_DATE_INVALID 

CHttpClient::CHttpClient(const CString& szReqCode, LPCTSTR strAgent)
{
	m_pSession = new CInternetSession(strAgent);
	m_szReqCode = szReqCode;
	m_pConnection = NULL;
	m_pFile = NULL;
}

CHttpClient::~CHttpClient(void)
{
	Clear();
	if (NULL != m_pSession)
	{
		m_pSession->Close();
		delete m_pSession;
		m_pSession = NULL;
	}
}

void CHttpClient::Clear()
{
	if (NULL != m_pFile)
	{
		m_pFile->Close();
		delete m_pFile;
		m_pFile = NULL;
	}

	if (NULL != m_pConnection)
	{
		m_pConnection->Close();
		delete m_pConnection;
		m_pConnection = NULL;
	}
}

int CHttpClient::ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, CString &strResponse, LPCTSTR imgPath = NULL)
{
	DWORD dwFlags;
	CString strServer;
	CString strObject;
	DWORD dwServiceType;
	INTERNET_PORT nPort;
	strResponse = _T("");


	AfxParseURL(strUrl, dwServiceType, strServer, strObject, nPort);

	if (AFX_INET_SERVICE_HTTP != dwServiceType && AFX_INET_SERVICE_HTTPS != dwServiceType)
	{
		return FAILURE;
	}
	try
	{
		m_pConnection = m_pSession->GetHttpConnection(strServer,
			dwServiceType == AFX_INET_SERVICE_HTTP ? NORMAL_CONNECT : SECURE_CONNECT, nPort);
		m_pFile = m_pConnection->OpenRequest(strMethod, strObject, NULL, 1, NULL, NULL,
			(dwServiceType == AFX_INET_SERVICE_HTTP ? NORMAL_REQUEST : SECURE_REQUEST));
		if (AFX_INET_SERVICE_HTTPS == dwServiceType)
		{
			m_pFile->QueryOption(INTERNET_OPTION_SECURITY_FLAGS, dwFlags);
			dwFlags |= SECURITY_FLAG_IGNORE_UNKNOWN_CA;
			m_pFile->SetOption(INTERNET_OPTION_SECURITY_FLAGS, dwFlags);
		}
		m_pFile->AddRequestHeaders(_T("Accept: *,*/*"));
		m_pFile->AddRequestHeaders(_T("Accept-Language: zh-cn"));
		m_pFile->AddRequestHeaders(_T("Content-Type: application/x-www-form-urlencoded"));
		m_pFile->AddRequestHeaders(_T("Accept-Encoding: deflate"));
		if (strPostData != NULL) {
			CStringA strData = GetReqData(strPostData);
			m_pFile->SendRequest(NULL, 0, (LPVOID)(LPCSTR)strData, strlen(strData));
		}
		else {
			m_pFile->SendRequest();
		}

		char szChars[BUFFER_SIZE + 1] = { 0 };
		CStringA strRawResponse = "";
		UINT nReaded = 0;

		if (imgPath == NULL) {
			while ((nReaded = m_pFile->Read((void*)szChars, BUFFER_SIZE)) > 0)
			{
				szChars[nReaded] = '\0';
				strRawResponse += szChars;
				memset(szChars, 0, BUFFER_SIZE + 1);
			}
			strResponse = GetResData(strRawResponse);
		}
		else {
			CFile f;
			f.Open(imgPath, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);
			while ((nReaded = m_pFile->Read((void*)szChars, BUFFER_SIZE)) > 0)
			{
				szChars[nReaded] = '\0';
				f.Write(szChars, BUFFER_SIZE);
				memset(szChars, 0, BUFFER_SIZE + 1);
			}
			f.Close();
		}
		Clear();
	}
	catch (CInternetException* e)
	{
		Clear();
		DWORD dwErrorCode = e->m_dwError;
		e->Delete();
		DWORD dwError = GetLastError();

		if (ERROR_INTERNET_TIMEOUT == dwErrorCode)
		{
			return OUTTIME;
		}
		else
		{
			return FAILURE;
		}
	}
	return SUCCESS;
}

int CHttpClient::HttpGet(LPCTSTR strUrl, CString &strResponse)
{
	return ExecuteRequest(_T("GET"), strUrl, NULL, strResponse);
}

int CHttpClient::HttpPost(LPCTSTR strUrl, CString &strResponse, LPCTSTR strPostData)
{
	return ExecuteRequest(_T("POST"), strUrl, strPostData, strResponse);
}

int CHttpClient::HttpGetImg(LPCTSTR strUrl, LPCTSTR imgPath)
{
	CString str;
	return ExecuteRequest(_T("GET"), strUrl, NULL, str, imgPath);
}
CStringA CHttpClient::GetReqData(const CString& szReqData)
{
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_UTF8, 0, szReqData, -1, NULL, 0, NULL, NULL);
	char * pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_UTF8, 0, szReqData, -1, pAssii, ansiiLen, NULL, NULL);
	CStringA szRet(pAssii);
	free(pAssii);
	return szRet;
}
CString CHttpClient::GetResData(const CStringA& szResData)
{
	if (m_szReqCode == REQ_CODE_GBK)
		return CString(szResData);
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, szResData, -1, NULL, 0);
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_UTF8, 0, szResData, -1, pUnicode, unicodeLen);
	CString szRet(pUnicode);
	free(pUnicode);
	return szRet;
}