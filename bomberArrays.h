#ifndef BOMBER_ARRAYS
#define BOMBER_ARRAYS

#include <map>

namespace Bomber
{
	const char encodeArrOdd[16] = {
		'B', 'H', 'M', 'J',
		'D', 'N', 'I', 'A',
		'O', 'F', 'K', 'C',
		'P', 'G', 'E', 'L'
	};
	
	const char encodeArrEven[16] = {
		'A', 'I', 'N', 'D',
		'J', 'M', 'H', 'B',
		'L', 'E', 'G', 'P',
		'C', 'K', 'F', 'O'
	};

	const std::map<char, uint8_t> decodeArrOdd = {
		{'B',  0}, {'H',  1}, {'M',  2}, {'J',  3},
		{'D',  4}, {'N',  5}, {'I',  6}, {'A',  7},
		{'O',  8}, {'F',  9}, {'K', 10}, {'C', 11},
		{'P', 12}, {'G', 13}, {'E', 14}, {'L', 15}
	};

	const std::map<char, uint8_t> decodeArrEven = {
		{'A',  0}, {'I',  1}, {'N',  2}, {'D',  3},
		{'J',  4}, {'M',  5}, {'H',  6}, {'B',  7},
		{'L',  8}, {'E',  9}, {'G', 10}, {'P', 11},
		{'C', 12}, {'K', 13}, {'F', 14}, {'O', 15}
	};
}

#endif//BOMBER_ARRAYS