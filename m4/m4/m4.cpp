/*
* FILE : m4.cpp
* PROJECT : SENG1000- major assignment 4
* PROGRAMMER : Bhawanjeet Kaur Gill
* FIRST VERSION : 2024-03-27
* DESCRIPTION : Write a program to display flight information where the least fare found for given source –
*               destination pair.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
struct flightData
{
	char source[20] = "";
	char destination[20] = "";
	int fare = 0;
	char airline[20] = "";
};
void displayLeastFareDetails(struct flightData variousFlights[], int count);
int processFlight(char flightName[20], struct flightData variousFlights[], int* totalCount);
int main(void)
{
	return 0;
}
/*
*
* NAME: parseLine()
* DESCRIPTION: This function takes exactly four parameters and will return a status indicating if the parsing of
*              the airline result worked perfectly or not. The function returns an integer, if the parsing is done
*              successfully then return 0 else return -1.
* PARAMETERS: char* source, char* destination, int* fare, char* line
* RETURNS: 0 or -1
*/

int parseLine(char* source, char* destination, int* fare, char* line)
{
	char* dashPos = strchr(line, '-');
	if (dashPos != NULL) {
		*dashPos = '\0'; // Replace '-' with null terminator to separate source
		strcpy(source, line);

		char* commaPos = strchr(dashPos + 1, ',');
		if (commaPos != NULL) {
			*commaPos = '\0'; // Replace ',' with null terminator to separate destination
			strcpy(destination, dashPos + 1);

			*fare = atoi(commaPos + 1); // Convert fare string to integer
			return 0; // Parsing successful
		}
	}
	else
	{
		printf("Boo!");
		return -1; // Parsing failed
	}
}