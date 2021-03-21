#include "langlist.h"


Language* LanguageList::lookUp(const std::string& key) {
	for (auto const& lang : this->languageLibrary) {
		std::string alias = lang.second->langAlias;
		if (alias == key) {
			return lang.second;
		}
	}
	return nullptr;
}

void LanguageList::initText() {
	std::cout << "-------------CONVERT INTEGER TO WORDS------------\n\n";
	std::cout << "SUPPORTED LANGUAGES:" << std::endl;
	for (auto const& langCode : languageLibrary) {
		std::cout << langCode.first << " : " << langCode.second->langName << std::endl << std::endl;
	}
	std::cout << "--------------------------------------------------\n\n";
	std::cout << "PLEASE CHOOSE YOUR LANGUAGE..\n";
}

void LanguageList::loadLanguages() {
	english = new EN();
	this->languageLibrary["en"] = english;
	vietnamese = new VI();
	this->languageLibrary["vi"] = vietnamese;
}