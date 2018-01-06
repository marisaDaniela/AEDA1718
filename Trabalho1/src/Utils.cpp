#include "Utils.h"

void trim(string &str)
{
	int i = 0;
	int spacesBegin = 0;
	while (' ' == str[i++])
	{
		spacesBegin++;
	}

	i = str.length();
	int spacesEnd = 0;

	while (' ' == str[--i])
	{
		spacesEnd++;
	}

	int strLength;

	strLength = str.length() - spacesBegin - spacesEnd;

	str = str.substr(spacesBegin, strLength);
}
