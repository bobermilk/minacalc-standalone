// This is a C++ style header file, so we have to do the typedef below to have NoteInfo accessible
#include "NoteDataStructures.h"
typedef struct NoteInfo NoteInfo;

typedef struct CalcHandle {} CalcHandle;

typedef struct Ssr {
	float overall;
	float stream;
	float jumpstream;
	float handstream;
	float stamina;
	float jackspeed;
	float chordjack;
	float technical;
} Ssr;

typedef struct MsdForAllRates {
	// one for each full-rate from 0.7 to 2.0 inclusive
	Ssr msds[14];
} MsdForAllRates;

int calc_version();

CalcHandle *create_calc();

void destroy_calc(CalcHandle *calc);

void calc_file(char* file_path, float rate, float score_goal);