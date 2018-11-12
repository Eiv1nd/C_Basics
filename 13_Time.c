#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
/**
struct tm {
   int tm_sec;         // seconds,  range 0 to 59
   int tm_min;         // minutes, range 0 to 59
   int tm_hour;        // hours, range 0 to 23
   int tm_mday;        // day of the month, range 1 to 31
   int tm_mon;         // month, range 0 to 11
   int tm_year;        // The number of years since 1900
   int tm_wday;        // day of the week, range 0 to 6
   int tm_yday;        // day in the year, range 0 to 365
   int tm_isdst;       // daylight saving time
};
*/

void wait_n_sec(int n)
{
	clock_t ticks1, ticks2;
	ticks1 = clock();
	ticks2 = ticks1;
	while(ticks2/CLOCKS_PER_SEC - ticks1 /CLOCKS_PER_SEC < n) ticks2 = clock();
	printf("Took %ld ticks to wait one second.\n", ticks2 - ticks1);
	printf("Value of CLOCKS_PER_SEC is %ld\n", CLOCKS_PER_SEC);
}

void countdown(int n)
{
	for(int i = n; i>-1; i--)
	{
		wait_n_sec(1);
		printf("%d seconds left\n", i);
	}
}


int main()
{
	countdown(10);
	return 0;
}
