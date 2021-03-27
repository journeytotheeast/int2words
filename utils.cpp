#include "utils.h"

std::string prompt = "PLEASE ENTER YOUR NUMBER..\n";
std::string reprompt = "INVALID NUMBER. PLEASE ENTER YOUR NUMBER AGAIN..\n";


long long getInteger() {
	while (true) {
		std::cout << prompt;
		long long value;
		std::string line;
		char trash;

		if (!std::getline(std::cin, line))
			throw std::domain_error("not cool!\n");
			
		std::istringstream iss(line);
		if (iss >> value && !(iss >> trash)) {
			return value;
		}

		iss.clear();
		iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		std::cout << reprompt;
	}
}

std::wstring wstringJoin(const std::vector<std::wstring>& elements, const wchar_t* separator) {
	switch (elements.size()) {
		case 0: {
			return L"";
		}
		case 1: {
			return elements[0];
			break;
		}
		default: {
			std::wstring result = L"";
			for (size_t i = 0; i < elements.size(); i++) {
				result += (i ? separator : L"");
				result += elements[i];
			}
			return result;
		}
	}
}


std::vector<int> integeToTriplets(long long number) {
	std::vector<int> triplets;
	while (number > 0) {
		triplets.push_back(number % 1000);
		number = number / 1000;
	}
	return triplets;
}

void wordDisplay(const std::wstring s) {
	_cputws(s.c_str());
}