#pragma once
#include "en.h"
#include "vi.h"
#include "lang.h"

class LanguageList {
public:

	std::map<std::string, Language*> languageLibrary;
	std::vector<std::string> languageList;
	EN* english;
	VI* vietnamese;

	LanguageList() {

		loadLanguages();

		initText();
	}

	Language* lookUp(const std::string& key);
	void initText();
	void loadLanguages();

	~LanguageList() {
		delete english;
		delete vietnamese;
		english = nullptr;
		vietnamese = nullptr;
	};

};
