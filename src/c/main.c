#include <stdio.h>
#include <stdlib.h>

#include "rps.h"

int main(int argc, char* args[]) {
	if (argc != 3) {
		fprintf(stderr, "Please provide choices for player one and player two as arguments\n");
		return 1;
	}

	RPSItem p1, p2;

	RPSItem* res = rps_item_by_name(args[1], &p1);
	if (res == 0) {
		fprintf(stderr, "P1 INVALID\n");
		return 1;
	}
	res = rps_item_by_name(args[2], &p2);
	if (res == 0) {
		fprintf(stderr, "P2 INVALID\n");
		return 2;
	}

	int rval = 0;
	switch(rps_match(&p1, &p2)) {
	case RPS_TIE: {
		printf("TIE\n");
		break;
	}
	case RPS_P1_WINS: {
		printf("P1 WINS\n");
		break;
	}
	case RPS_P2_WINS: {
		printf("P2 WINS\n");
		break;
	}
	case RPS_ERROR: {
		fprintf(stderr, "ERROR");
		rval = 255;
	}
	}

	return rval;
}
