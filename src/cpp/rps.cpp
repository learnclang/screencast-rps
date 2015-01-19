#include <cassert>
#include <iostream>

#include "rps.hpp"

enum Type {
	tRock = 0,
	tPaper,
	tScissors,

	tUndefined = ~0
};

const Rock rock;
const Paper paper;
const Scissors scissors;

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

RPSItem* rps_item_by_name(const char *name)
{
	for (const RPSItem** item = items; item < items + NUM_ITEMS; ++item) {
		if (rps_strcmp((**item).name, name) == 0) {
			switch((*item)->id){
			// This copy constructor invocation is just for show
			case tRock: return new Rock(*dynamic_cast<const Rock*>(*item));
			case tPaper: return new Paper;
			case tScissors: return new Scissors;
			}
		}
	}

	return 0;
}


RPSItem::RPSItem()
	: name(0)
	, id(tUndefined)
{

}

RPSItem::RPSItem(const char *name, const int id)
	: name(name)
	, id(id)
{
}

RPSItem::RPSItem(const RPSItem &rhs)
	: name(rhs.name)
	, id(rhs.id)
{

}

RPSItem::~RPSItem()
{
	std::cerr << "Destroyed " << this->name << " (" << this << ")" << std::endl;
}


Rock::Rock()
	: RPSItem("rock", tRock)
{

}

void Rock::say_you_lost(FILE *stream) const
{
	fprintf(stream, "I am blind !\n");
}

Rock::~Rock()
{
	std::cerr << "I AM ROCK" << std::endl;
}


Paper::Paper()
	: RPSItem("paper", tPaper)
{

}

void Paper::say_you_lost(FILE *stream) const
{
	fprintf(stream, "I feel divided!\n");
}


Scissors::Scissors()
	: RPSItem("scissors", tScissors)
{

}

void Scissors::say_you_lost(FILE *stream) const
{
	fprintf(stream, "I am crushed !\n");
}
