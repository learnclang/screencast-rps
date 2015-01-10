#include <assert.h>

#include "rps.h"

const char* choices[] = {"rock", "paper", "scissors"};
const int NUM_CHOICES = sizeof(choices) / sizeof(choices[0]);

int rps_strcmp(const char* a, const char* b) {
	assert(a);
	assert(b);

	for (; *a && *b ; ++a, ++b) {
		if (*a != *b) {
			return -1;
		}
	}

	if (*a == 0 && *b == 0) {
		return 0;
	}

	return -1;
}

int input_id(const char* input) {
	for (unsigned long cid = 0; cid < sizeof(choices) / sizeof(choices[0]); ++cid) {
		if (rps_strcmp(input, choices[cid]) == 0) {
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

RPS_Result rps_match(const char* p1_pick, const char* p2_pick) {
	int pchoices[] = {0, 0};
	pchoices[0] = input_id(p1_pick);
	pchoices[1] = input_id(p2_pick);

	int res = 0;
	if ((res = choices_are_valid(pchoices, 2)) > -1) {
		switch(res) {
		case 0: return RPS_P1_INVALID;
		case 1: return RPS_P2_INVALID;
		default: {
			assert(0);
			return RPS_ERROR;
		}
		}
	}

	switch(((pchoices[1] - pchoices[0]) + NUM_CHOICES) % NUM_CHOICES) {
	case 0: return RPS_TIE;
	case 1: return RPS_P1_WINS;
	case 2: return RPS_P2_WINS;
	default: {
		assert(0);
		return RPS_ERROR;
	}
	}
}
