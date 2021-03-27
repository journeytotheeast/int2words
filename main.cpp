#include <iostream>
#include "langlist.h"
#include "utils.h"


int main() {

	LanguageList Library = LanguageList();
	long long input;
	std::string langCode;
	std::getline(std::cin, langCode);
	Language* language = Library.lookUp(langCode);

	while (language == nullptr) {
		std::cout << "LANGUAGE NOT FOUND! PLEASE CHOOSE YOUR LANGUAGE AGAIN..\n";
		std::getline(std::cin, langCode);
		delete language;
		language = Library.lookUp(langCode);
	}

	input = getInteger();

	std::cout << "your input: " << input << std::endl;
	std::wstring output = language->integerToWord(input);
	wordDisplay(output);
	
	language = nullptr;
	std::cout << std::endl;
	
	system("pause");
	return 0;
}
