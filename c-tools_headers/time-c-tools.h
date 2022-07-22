#include <sys/time.h>

//#include <sys/time.h>
// Returns number that grows by one every ms
unsigned long long time_ms(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return ((unsigned long long)(t.tv_sec) * 1000 + (unsigned long long)(t.tv_usec) / 1000);
}
