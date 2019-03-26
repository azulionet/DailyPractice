#pragma once

BEGIN_UTIL

class Debug
{
public:

	public static void Log(std::wstring a_sLog, std::wstring a_sFileName);
	public static void LogError(std::wstring a_sLog, std::wstring a_sFileName);
};

END_UTIL

