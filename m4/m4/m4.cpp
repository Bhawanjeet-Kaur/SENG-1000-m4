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
int processFlight(char flightName[20], struct flightData variousFlights[], int* totalCount)
{
	strcat(flightName, ".txt");
	//file name able to get .txt extension
	FILE* file = fopen(flightName, "r");
	if (file == NULL)
	{
		printf("Error: Not able to read the file.\n");
		return 1;
	}
	char airline[30];
	//char* fileNameStart = flightName;
	char* pName = strchr(flightName, '.');
	if (pName != nullptr)
	{
		*pName = '\0';
	}
	strcpy(airline, flightName);
	//removed the .txt extension again
	char line[100];
	int status;
	int count = 0;

	while (fgets(line, sizeof(line), file) != NULL && count < 100)
	{
		//taking only one
		line[strcspn(line, "\n")] = '\0';
		//printf("%s.",line);
		char source[50];
		char destination[50];
		int fare;
		status = parseLine(source, destination, &fare, line);
		//printf("%d\n", status);
		if (status == 0)
		{
			// Parsing successful, store in flights array
			//printf("Going in");
			strcpy(variousFlights[count].source, source);
			strcpy(variousFlights[count].destination, destination);
			variousFlights[count].fare = fare;
			strcpy(variousFlights[count].airline, airline);
			count++;
		}

		else
		{
			fclose(file);
			return -2; // Parsing line failed
		}

	}
	fclose(file);
	//printf("%d", count);
	*totalCount = count;
	return 0;
}