#include <assert.h>
#include <string.h>

#include "rps.hpp"

Rock rock;
Paper paper;
Scissors scissors;

const RPSItem* items[] = {
	&rock,
	&paper,
	&scissors
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

const RPSItem* rps_item_by_name(const char *name)
{
	for (const RPSItem** item = items; item < items + NUM_ITEMS; ++item) {
		if (rps_strcmp((**item).name, name) == 0) {
			return *item;
		}
	}

	return 0;
}


RPSItem::RPSItem()
	: name(0)
	, id(0)
{

}

RPSItem::RPSItem(const char *name, const int id)
	: name(name)
	, id(id)
{
}


Rock::Rock()
	: RPSItem("rock", 0)
{

}

void Rock::say_you_lost(FILE *stream) const
{
	fprintf(stream, "I am blind !\n");
}


Paper::Paper()
	: RPSItem("paper", 1)
{

}

void Paper::say_you_lost(FILE *stream) const
{
	fprintf(stream, "I feel divided!\n");
}


Scissors::Scissors()
	: RPSItem("scissors", 2)
{

}

void Scissors::say_you_lost(FILE *stream) const
{
	fprintf(stream, "I am crushed !\n");
}
