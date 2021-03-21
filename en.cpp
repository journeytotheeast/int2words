#include "lang.h"
#include "en.h"


// convert an integer to English
std::wstring EN::integerToWord(long long input) {
	std::wstring englishMegas[] = { L"", L"thousand", L"million", L"billion", L"trillion", L"quadrillion", L"quintillion"};
	std::wstring englishUnits[] = { L"", L"one", L"two", L"three", L"four", L"five", L"six", L"seven", L"eight", L"nine" };
	std::wstring englishTens[] = { L"", L"ten", L"twenty", L"thirty", L"forty", L"fifty", L"sixty", L"seventy", L"eighty", L"ninety" };
	std::wstring englishTeens[] = { L"ten", L"eleven", L"twelve", L"thirteen", L"fourteen", L"fifteen", L"sixteen", L"seventeen", L"eighteen", L"nineteen" };

	std::vector<std::wstring> words;

	if (input == 0) {
		return L"zero";
	}

	if (input < 0) {
		words.push_back(L"minus");
		input *= -1;
	}

	// split integer into triplets
	std::vector<int> triplets = integeToTriplets(input);

	if (triplets.size() == 0) {
		return L"zero";
	}

	// iterate over triplets
	for (int idx = triplets.size() - 1; idx >= 0; idx--) {
		int triplet = triplets[idx];

		// do nothing with empty triplet
		if (triplet == 0) {
			continue;
		}

		// produce three digits
		int hundreds = triplet / 100 % 10;
		int tens = triplet / 10 % 10;
		int units = triplet % 10;


		if (hundreds > 0) {
			words.push_back(englishUnits[hundreds]);
			words.push_back(L"hundred");
		}

		if (tens == 0 && units == 0) {
			goto tripletEnd;
		}

		switch (tens) {
			case 0: {
				words.push_back(englishUnits[units]);
				break;
			}
			case 1: {
				words.push_back(englishTeens[units]);
				break;
			}
			default: {
				if (units > 0) {
					words.push_back(englishTens[tens] + L"-" + englishUnits[units]);
				}
				else {
					words.push_back(englishTens[tens]);
				}
				break;
			}
		}

		tripletEnd:
			std::wstring mega = englishMegas[idx];
			if (mega != L"") {
				words.push_back(mega);
			}
	}

	return wstringJoin(words, L" ");
}
