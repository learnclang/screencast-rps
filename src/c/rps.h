
typedef enum {RPS_P1_INVALID,
			  RPS_P2_INVALID,
			  RPS_P1_WINS,
			  RPS_P2_WINS,
			  RPS_TIE,
			  RPS_ERROR} RPS_Result;

RPS_Result rps_match(const char* p1_pick, const char* p2_pick);
