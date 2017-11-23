/**
 * How to run:
 *
 *   $ gcc -std=gnu99 -o datetime datetime.c
 *   $ ./datetime
 *
 */

#define _POSIX_SOURCE /* for tzset() */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//time(), localtime(), strftime()

extern char *tzname[2];
extern long timezone;

void show_timezone()
{
	tzset();
	printf("tzname  : %s,%s\n", tzname[0], tzname[1]);
	printf("timezone: %ldsec (%dhour)\n", timezone, timezone / 3600);
}

void show_today()
{
	time_t now = time(NULL);
	printf("Unix Time: %ld\n", now);

	struct tm *utctm, *localtm;


#if defined(WIN32)
	utctm = gmtime(&now);
#else
	struct tm tmp;
	utctm = gmtime_r(&now, &tmp);
#endif
	if (utctm == NULL) {
		perror("gmtime");
		exit(EXIT_FAILURE);
	}
	printf("UTC: %s", asctime(utctm));


#if defined(WIN32)
	localtm = localtime(&now);
	/*
	 * Using reentrant function causes a following build error.
	 * "undefined reference to `localtime_r'"
	 * It looks like, Windows does not support reentrant functions.
	 */
	 //localtm = localtime_r(&now, &tmp);		// Build error
#else
	localtm = localtime_r(&now, &tmp);
#endif
	if (localtm == NULL) {
		perror("localtime");
		exit(EXIT_FAILURE);
	}
	printf("UTC: %s", asctime(utctm));		// utctm is overwritten due to none-reentrant
	printf("JST: %s", asctime(localtm));


	char outstr[200] = {0};
	char format[] = "%Y-%m-%d %H:%M:%S";
	/*
	 * %F and %T does not work on Windows even -std=gnu99 is set.
	 * Thus strftime() returns 0.
	 */
	 //char *format = "%F %T";		// Not work

	if (strftime(outstr, sizeof(outstr), format, localtm) == 0) {
		fprintf(stderr, "strftime returned 0");
		exit(EXIT_FAILURE);
	}
	printf("JST: %s\n", outstr);
}

/**
 * @brief Convert from Unix Time to local time.
 * @param[in] timep  A Unix Time
 * @return           A local time converted from timep
 */
struct tm *from_unix_time(const time_t *timep)
{
	return localtime(timep);
}

/**
 * @brief Convert from local time to Unix Time.
 * @param[in] ptm    A local time
 * @return           A Unix Time converted from ptm
 */
time_t to_unix_time(struct tm *ptm)
{
	return mktime(ptm);
}

int main(int argc, char *argv[])
{
	printf("Hello, world!\n");
	show_today();
	show_timezone();

	printf("---- Test case 1 ----\n");
	struct tm *ptm;
	time_t converted;
	time_t origtime = 1511333444;	// 2017-11-22 15:50:44
	ptm = from_unix_time(&origtime);
	converted = to_unix_time(ptm);
	if (origtime == converted) {
		printf("Success: %ld = %s", origtime, asctime(ptm));
	} else {
		printf("Failure: %ld != %s", origtime, asctime(ptm));
	}


	return 0;
}
