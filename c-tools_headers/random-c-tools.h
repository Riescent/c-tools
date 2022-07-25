#pragma once

#include <stdlib.h>

/*
#include <time.h>
#include <stdlib.h>
*/
// srand((int)time_ms()); included in main gives better results. random_range() returns random value between min and max (min and max are possible returns).
int random_range(const int min, const int max)
{
	return ((rand() % (max + 1 - min)) + min);
}
