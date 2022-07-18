#include "time-riescent.h"
#include <stdlib.h>

/*
#include <time.h>
#include <stdlib.h>
*/
// srand(time_ms()); needs to be included in main. random_range() returns random value between min and max (min and max are possible returns).
int random_range(int min, int max)
{
	// The following needs to be included in main()
	// srand(time_ms()); // Seeds rand() with time_ms() (changes by 1 every ms)
	return ((rand() % (max + 1 - min)) + min);
}
