#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <algorithm>
#include <sstream>		// std::ostringstream
#include "utils.h"

class Language {
public:

	Language(std::string aName, std::string anAlias) {
		langName = aName;
		langAlias = anAlias;
	}

	virtual std::wstring integerToWord(long long input) = 0;

	std::string langName;
	std::string langAlias;
};

