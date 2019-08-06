#include "pch.h"
#include "Log.h"

// BEGIN_UTIL

/*
using clock = std::chrono::system_clock;

void Debug::Log(std::wstring a_sLog, std::wstring a_sFileName)
{
	wstring s = "[";

	auto& tNow = clock::now();


	return string();
}

void Debug::LogError(std::wstring a_sLog, std::wstring a_sFileName)
{
	return string();
}

public static string Log(string a_sLog,
	string a_sFileName = Path.sLogFile,
	[CallerFilePath] string a_sFilePath = "",
	[CallerLineNumber] int a_nLineNum = 0)
{
	StringBuilder s = new StringBuilder("[");
	s.Append(DateTime.Now);
	s.Append("]");

	if (a_eLogType == eLog.Error)
	{
		s.Append("[Error][");
	}

	s.Append(System.IO.Path.GetFileName(a_sFilePath));
	s.Append(" - ");
	s.Append(a_nLineNum);
	s.Append("] : ");
	s.Append(a_sLog);

	File.Wright(Path.FileName_inMyDocument(Path.eDocumentFile.Log), s.ToString());

	return s.ToString();
}

// assert도 겸함
public static string LogError(string a_sLog,
	string a_sFileName = Path.sLogFile,
	[CallerFilePath] string a_sFilePath = "",
	[CallerLineNumber] int a_nLineNum = 0)
{
	string s = Log(a_sLog, eLog.Error, a_sFileName, a_sFilePath, a_nLineNum);
	assert(false, s);

	return s;
}

*/

// END_UTIL
