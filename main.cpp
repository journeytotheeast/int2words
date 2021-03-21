#include <iostream>
#include "langlist.h"

int main() {

	LanguageList Library = LanguageList();
	long long input;
	std::string langCode;
	std::cin >> langCode;
	Language* language = Library.lookUp(langCode);

	while (language == nullptr) {
		std::cout << "LANGUAGE NOT FOUND! PLEASE CHOOSE YOUR LANGUAGE AGAIN..\n";
		std::cin >> langCode;
		delete language;
		language = Library.lookUp(langCode);
	}

	std::cout << "PLEASE ENTER YOUR NUMBER..\n";
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "INVALID NUMBER. PLEASE ENTER YOUR NUMBER AGAIN..\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}

	std::cout << "your input: " << input << std::endl;
	std::wstring output = language->integerToWord(input);
	wordDisplay(output);

	std::cout << std::endl;
	
	system("pause");
	return 0;
}
