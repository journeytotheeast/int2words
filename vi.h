#pragma once
#include "lang.h"

class VI : public Language {
public:
	VI() : Language("Vietnamese", "vi") {};

	std::wstring integerToWord(long long input) override;
};
