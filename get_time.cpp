//SOURCE FILE FOR get_time.cpp
// Using localtime_s rather than localtime 
//	localtime is apparently unstable in multithreaded code
//	BJA 08.01.2014
//	THIS FUNCTION CONSTRUSTS RETURNS THE DATE AND TIME AS A STRING

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


////FUNCTION TO **RETURN** THE DATE AND TIME using localtime_s AND asctime_s
//// nb the size of this buffer is set in the main code
//char* get_time_s(char * buffer, int n)
//{
//
//	time_t rawtime;		// current time
//	struct tm timeinfo; // time structure
//
//	errno_t errNum;		// error message for asctime_s
//	time(&rawtime);		// get the time
//	localtime_s (&timeinfo, &rawtime);	// convert the time to struct tm form
//
//	errNum = asctime_s(buffer, n, &timeinfo);
//	if(errNum)
//	{
//		printf("Error code: %d", (int)errNum);
//		return "You made a bobo - see get_time_s";
//	}
//
//	return buffer;
//}
//
////OLD FUNCTION TO RETURN THE DATE AND TIME using localtime AND asctime
//////	nb this function returns a pointer to a statically allocated struct tm
////std::string get_time()
////{
////	string caltime;
////	time_t rawtime;
////	struct tm *timeinfo;
////	time(&rawtime);
////	timeinfo = localtime (&rawtime);
////	caltime = asctime (timeinfo);
////	caltime = "Time is: " + caltime;
////	return caltime;
////}
//
////
