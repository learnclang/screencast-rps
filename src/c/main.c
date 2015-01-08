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

int main(int argc, char* args[]) {
	if (argc != 3) {
		fprintf(stderr, "Please provide choices for player one and player two as arguments\n");
		return 1;
	}

	int pchoices[] = {0, 0};
	for (int argi = 1; argi < argc; ++argi) {
		const int pci = argi - 1;
		pchoices[pci] = input_id(args[argi]);
		if (pchoices[pci] < 0) {
			fprintf(stderr, "Player choice '%s' is invalid, please choose one of %s, %s, or %s\n", args[argi], choices[0], choices[1], choices[2]);
			return 1;
		}
	}

	printf("%s\n", results[((pchoices[1] - pchoices[0]) + NUM_RESULTS) % NUM_RESULTS]);
	return 0;
}
