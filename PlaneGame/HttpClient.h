#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <afxinet.h>

#define  IE_AGENT  _T("Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)")
#define  REQ_CODE_UTF8  _T("UTF-8")
#define  REQ_CODE_GBK   _T("GBK")

// 操作成功
#define SUCCESS        0
// 操作失败
#define FAILURE        1
// 操作超时
#define OUTTIME        2

class CHttpClient
{
public:
	CHttpClient(const CString& szReqCode = REQ_CODE_UTF8, LPCTSTR strAgent = IE_AGENT);
	virtual ~CHttpClient(void);

	int HttpGet(LPCTSTR strUrl, CString &strResponse);
	int HttpGetImg(LPCTSTR strUrl, LPCTSTR imgPath);
	int HttpPost(LPCTSTR strUrl, CString &strResponse, LPCTSTR strPostData);

private:
	int ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, CString &strResponse, LPCTSTR imgPath);
	void Clear();
	CStringA GetReqData(const CString&  szReqData);
	CString  GetResData(const CStringA& szResData);
private:
	CInternetSession * m_pSession;
	CHttpConnection *m_pConnection;
	CHttpFile *m_pFile;
	CString m_szReqCode;
};

#endif