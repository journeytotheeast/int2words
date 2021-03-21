#pragma once
#include "lang.h"

class EN : public Language {
public:
	EN() : Language("English", "en") {};

	std::wstring integerToWord(long long input) override;
};