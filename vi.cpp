#include "vi.h"


// convert an integer to Vietnamese
std::wstring VI::integerToWord(long long input) {
	std:: vector<std::wstring> vietMegas = { L"", L"nghìn", L"triệu", L"tỷ", L"nghìn tỷ", L"triệu tỷ", L"tỷ tỷ"};
	std::vector<std::wstring> vietUnits = { L"", L"một", L"hai", L"ba", L"bốn", L"năm", L"sáu", L"bảy", L"tám", L"chín" };
	std::vector<std::wstring> vietTens = { L"", L"mười", L"hai mươi", L"ba mươi", L"bốn mươi", L"năm mươi", L"sáu mươi", L"bảy mươi", L"tám mươi", L"chín mươi" };
	

	std::vector<std::wstring> words;

	if (input == 0) {
		return L"không";
	}

	if (input < 0) {
		words.push_back(L"âm");
		input *= -1;
	}

	// split integer into triplets
	std::vector<int> triplets = integeToTriplets(input);

	if (triplets.size() == 0) {
		return L"không";
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

		if (hundreds == 0 && idx != triplets.size() - 1) {
			words.push_back(L"không trăm");
			if (tens == 0 && units > 0) {
				words.push_back(L"linh");
				words.push_back(vietUnits[units]);
				break;
			}
		}

		if (hundreds > 0) {
			words.push_back(vietUnits[hundreds]);
			words.push_back(L"trăm");
		}

		if (tens == 0 && units == 0) {
			goto tripletEnd;
		}

		switch (tens) {
			case 0: {
				if (hundreds > 0) {
					words.push_back(L"linh");
				}
				words.push_back(vietUnits[units]);
				break;
			}
			default: {
				if (units > 0) {
					words.push_back(vietTens[tens]);
					switch (units) {
						case 1: {
							if (tens == 1) {
								words.push_back(L"một");
							}
							else {
								words.push_back(L"mốt");
							}

							break;
						}
						case 4: {
							if (tens == 1) {
								words.push_back(L"bốn");
							}
							else {
								words.push_back(L"tư");
							}
							break;
						}
						case 5: {
							words.push_back(L"lăm");
							break;
						}
						default: {
							words.push_back(vietUnits[units]);
							break;
						}
					}
				}
				else {
					words.push_back(vietTens[tens]);
				}
				break;
			}
		}

		tripletEnd:
			std::wstring mega = vietMegas[idx];
			if (mega != L"") {
				words.push_back(mega);
			}
	}


	return wstringJoin(words, L" ");
}
