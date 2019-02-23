#include "utils.h"

void warn(const char* message)
{
	fprintf(stderr, "WARN: %s\n", message);
}

void err(const char* message)
{
	fprintf(stderr, "ERROR: %s\n", message);
	exit(CELL_FIRE);
}
