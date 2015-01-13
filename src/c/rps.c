#include <assert.h>
#include <string.h>

#include "rps.h"


void rps_rock_lost(FILE* stream) {
	fprintf(stream, "I am blind !\n");
}

void rps_paper_lost(FILE* stream) {
	fprintf(stream, "I feel divided!\n");
}

void rps_scissors_lost(FILE* stream) {
	fprintf(stream, "I am crushed !\n");
}

const RPSItem items[] = {
	{ .name = "rock",
	  .id = 0,
	  .say_you_lost = rps_rock_lost,},
	{ .name = "paper",
	  .id = 1,
	  .say_you_lost = rps_paper_lost,},
	{ .name = "scissors",
	  .id = 2,
	  .say_you_lost = rps_scissors_lost,}
};
const int NUM_ITEMS = sizeof(items) / sizeof(items[0]);

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

RPS_Result rps_match(const RPSItem *p1_pick, const RPSItem *p2_pick) {
	assert(p1_pick);
	assert(p2_pick);

	switch(((p1_pick->id - p2_pick->id) + NUM_ITEMS) % NUM_ITEMS) {
	case 0: return RPS_TIE;
	case 1: return RPS_P1_WINS;
	case 2: return RPS_P2_WINS;
	default: {
		assert(0);
		return RPS_ERROR;
	}
	}
}

RPSItem* rps_item_by_name(const char *name, RPSItem* destination)
{
	for (const RPSItem* item = items; item < items + NUM_ITEMS; ++item) {
		if (rps_strcmp(item->name, name) == 0) {
			memcpy(destination, item, sizeof(RPSItem));
			return destination;
		}
	}

	return 0;
}
