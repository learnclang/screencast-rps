#include <stdio.h>
#include <string.h>

const char* choices[] = {"rock", "paper", "scissors"};
const char* results[] = {"We tied", "Player 2 wins", "Player 1 wins"};
const int NUM_RESULTS = sizeof(results) / sizeof(results[0]);


int input_id(const char* input) {
	for (unsigned long cid = 0; cid < sizeof(choices) / sizeof(choices[0]); ++cid) {
		if (strcmp(input, choices[cid]) == 0) {
			return cid;
		}
	}
	return -1;
}

int choices_are_valid(const int*const c, const int csize) {
	for (const int* i = c; i < c + csize; ++i) {
		if (*i < 0) {
			return i - c;
		}
	}
	return -1;
}

int main(int argc, char* args[]) {
	if (argc != 3) {
		fprintf(stderr, "Please provide choices for player one and player two as arguments\n");
		return 1;
	}

	int pchoices[] = {0, 0};
	for (int argi = 1; argi < argc; ++argi) {
		const int pci = argi - 1;
		pchoices[pci] = input_id(args[argi]);
	}

	int res = 0;
	if ((res = choices_are_valid(pchoices, 2)) > -1) {
		fprintf(stderr, "Player choice '%s' is invalid, please choose one of %s, %s, or %s\n", args[res+1], choices[0], choices[1], choices[2]);
		return 1;
	}

	// halfchar a[] = {'1', '2'} // sizeof(a[0]) == 1
	// halfchar* e = a + 2 // 8 + 2
	// for (halfchar* i = a; i < e; ++i)
	// 1: 8 < 10 : 1 - a : (8 - 8) / 1 == 0
	// 2: 9 < 10 : i - a : (9 - 8) / 1 == 1
	// 3: 10 < 10 FALSE !!
	// 00|01|02|03|04|05|06|07|08|09|10|11|12|13|14|15  -> slot address
	// 08|00|00|00|00|00|00|00|01|02|00|00|00|00|00|00  -> slot values
	// assert(a[0] == '1')
	// assert(*(a+0) == '1')
	// assert(a[1] == '2')
	// assert(*(a+1) == '2') // *(8+1)
	//
	// int a[] = {1, 2} // sizeof(a[0]) == 4
	// int* e = a + 2 // 8 + (2*4) = 15 + 1 == 0 ; lets assume this is 16
	// for (int* i = a; i < e; ++i)
	// 1: 8 < 16 ....                    == 0
	// 2: 12 < 16 : i - a : (12 - 8) / 4 == 1
	// 00|01|02|03|04|05|06|07|08|09|10|11|12|13|14|15  -> slot address
	// 08|00|00|00|00|00|00|00|00 00 00 01|00 00 00 02  -> slot values
	// assert(*a == 1) // go to 8 and read 4 half bytes from 8
	// assert(*(a+1) == 2) // go to (8+4) and read 4 half bytes

	printf("%s\n", results[((pchoices[1] - pchoices[0]) + NUM_RESULTS) % NUM_RESULTS]);
	return 0;
}
