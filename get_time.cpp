//SOURCE FILE FOR get_time.cpp
// Using localtime_s rather than localtime 
//	localtime is apparently unstable in multithreaded code
//	BJA 08.01.2014
//	THIS FUNCTION CONSTRUSTS and PRINTS to SCREEN THE DATE AND TIME AS A STRING

#include <string>
#include <time.h>
#include <stdio.h>

#include "get_time.h"

using std::string; 

////FUNCTION TO **PRINT** THE DATE AND TIME using localtime_s AND asctime_s
int print_time_s()
{

	time_t rawtime;		// current time
	struct tm timeinfo; // time structure

	char buffer[32];	// buffer for asctime_s
	errno_t errNum;		// error message for asctime_s
	time(&rawtime);		// get the time
	localtime_s (&timeinfo, &rawtime);	// convert the time to struct tm form
	
	errNum = asctime_s(buffer, 32, &timeinfo); //An error if the buffere is not big enough
	if(errNum){ 
		printf("Error code: %d", (int)errNum);
		return 1;
	}

	printf("Time printed is: %s", buffer);
	return 0;
}
