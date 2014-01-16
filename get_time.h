#ifndef GUARD_get_time
#define GUARD_get_time

//get_time.h HEADER FILE
//	DECLARATION OF THE FUNCTION
//	THIS FUNCTION PRINTS THE CURRENT TIME

#include <time.h>				//TIME() - RANDOM SEED GENERATOR

//FUNCTION TO **PRINT** THE TIME
int print_time_s();

////FUNCTION TO **RETURN** THE TIME AND PASS IT BACK AS A STRING
//char* get_time_s(char* buffer, int n);// buffer for asctime_s);

////OLD FUNCTION TO **RETURN** THE DATE AND TIME using localtime AND asctime
//std::string get_time();

#endif