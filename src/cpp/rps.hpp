#include <stdio.h>

typedef enum {RPS_P1_WINS,
			  RPS_P2_WINS,
			  RPS_TIE,
			  RPS_ERROR} RPS_Result;

struct RPSItem {
	const char* name;
	const int   id;
	void (*say_you_lost)(FILE*);

	RPSItem();
	RPSItem(const char* name, const int id, void (*say_you_lost)(FILE*));
};


RPSItem* rps_item_by_name(const char* name, RPSItem *destination);
RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick);
