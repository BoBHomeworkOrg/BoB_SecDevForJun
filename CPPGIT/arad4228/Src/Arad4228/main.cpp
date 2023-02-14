#include "pch.h"

int main()
{
	LPCTSTR pszReportJson = TEXT("C:\\Users\\arad4\\Desktop\\CPPGIT\\report.json"); // ���� ��ο� �°� ����1
	LPCTSTR pszReportXml = TEXT("C:\\Users\\arad4\\Desktop\\target.xml"); // ���� ��ο� �°� ����2
	LPCTSTR pszTargetXml = TEXT("C:\\Users\\arad4\\Desktop\\CPPGIT\\target.xml"); // ���� ��ο� �°� ����3
	try
	{
		ST_REPORT report;
		if (!UTF8::ReadJsonFromFile(&report, pszReportJson))
			throw exception_format(TEXT("Reading %s failure"), pszReportJson);
		if (!UTF8::WriteXmlToFile(&report, pszReportXml))
			throw exception_format(TEXT("Writing %s failure"), pszReportXml);
		std::tstring strMyXml;
		if (EC_SUCCESS != ReadFileContents(pszReportXml, strMyXml))
			throw exception_format(TEXT("Reading MyXml %s failure"), pszReportXml);
		std::tstring strTargetXml;
		if (EC_SUCCESS != ReadFileContents(pszTargetXml, strTargetXml))
			throw exception_format(TEXT("Reading TargetXml %s failure"), pszTargetXml);
		if (strMyXml != strTargetXml)
			throw exception_format(TEXT("Not exactly matched!"));
		printf("You are succeeded!\n");
	}
	catch (const std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}