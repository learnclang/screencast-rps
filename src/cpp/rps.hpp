#include <stdio.h>

typedef enum {RPS_P1_WINS,
			  RPS_P2_WINS,
			  RPS_TIE,
			  RPS_ERROR} RPS_Result;

struct RPSItem {
	const char*const name;
	const int   id;

	virtual void say_you_lost(FILE*) const = 0;

	RPSItem();
	RPSItem(const char* name, const int id);
};

struct Rock : RPSItem {
	Rock();

	virtual void say_you_lost(FILE*) const;
};

struct Paper : RPSItem {
	Paper();

	virtual void say_you_lost(FILE*) const;
};

struct Scissors : RPSItem {
	Scissors();

	virtual void say_you_lost(FILE*) const;
};


const RPSItem *rps_item_by_name(const char* name);
RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick);
