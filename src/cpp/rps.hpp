#include <stdio.h>

typedef enum {RPS_P1_WINS,
			  RPS_P2_WINS,
			  RPS_TIE,
			  RPS_ERROR} RPS_Result;


class RPSItem {
public:
	const char*const name;
	const int   id;

	virtual void say_you_lost(FILE*) const = 0;

protected:
	RPSItem();
	RPSItem(const char* name, const int id);
	RPSItem(const RPSItem& rhs);

public:
	virtual ~RPSItem();
};

class Rock : public RPSItem {
public:
	Rock();

	virtual void say_you_lost(FILE*) const;

	virtual ~Rock();
};

class Paper : public RPSItem {
public:
	Paper();

	virtual void say_you_lost(FILE*) const;
};

class Scissors : public RPSItem {
public:
	Scissors();

	virtual void say_you_lost(FILE*) const;
};


RPSItem *rps_item_by_name(const char* name);
RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick);
