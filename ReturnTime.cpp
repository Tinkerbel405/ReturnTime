
#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <istream>
#include <ios>
#include <string>

#include "get_time.h"

using std::cout; using std::string;

int main(){

	//char *buffer[40];								// Declare the char array to hold the time string 
	//int nbuf = sizeof(buffer)/sizeof(buffer[0]) ;	// Get the length of char array

	//// char * telltime = get_time_s(*buffer, nbuf);	// Call get_time_s
	//cout << "Time is: " << get_time_s(*buffer, nbuf) << "\n";		//Print the time

	print_time_s();
	
	_getch();
	return 0;
}