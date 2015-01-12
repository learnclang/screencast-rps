#include <stdio.h>

#include "rps.h"

int main(int argc, char* args[]) {
	if (argc != 3) {
		fprintf(stderr, "Please provide choices for player one and player two as arguments\n");
		return 1;
	}

	switch(rps_match(rps_item_by_name(args[1]), rps_item_by_name(args[2]))) {
	case RPS_P1_INVALID: {
		fprintf(stderr, "P1 INVALID\n");
		return 1;
	}
	case RPS_P2_INVALID: {
		fprintf(stderr, "P2 INVALID\n");
		return 2;
	}
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
		return 255;
	}
	}
	return 0;
}
