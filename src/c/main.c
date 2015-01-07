#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int MAX_ARGUMENT_COUNT = 3;
const char* choices[] = {"rock", "paper", "scissors"};
const char* results[] = {"It's a tie", "Player 1 wins", "Player 2 wins"};

int input_id(const char* input) {
	for(const char** choice = choices; choice < choices + sizeof(choices) / sizeof(choices[0]); ++choice) {
		if (strcmp(input, *choice) == 0) {
			return choice - choices;
		}
	}
	return -1;
}

int main(int argc, char* args[]) {
	if (argc != MAX_ARGUMENT_COUNT) {
		fprintf(stderr, "Please provide choices for player 1 and player 2, totalling two arguments\n");
		return 1;
	}

	int pchoice[] = {0, 0};
//	for(char** arg = args + 1; arg < args + MAX_ARGUMENT_COUNT; ++arg) {
	for(int i = 1; i < MAX_ARGUMENT_COUNT; ++i) {
		const int cindex = i - 1;
		pchoice[cindex] = input_id(args[i]);
		if (pchoice[cindex] < 0) {
			fprintf(stderr, "Invalid game choice '%s'\nvalid player choices are %s, %s, or %s\n", args[i], choices[0], choices[1], choices[2]);
			return 1;
		}
	}

	printf("%s\n", results[((pchoice[0] - pchoice[1]) + 3) % 3]);
	return 0;
}
