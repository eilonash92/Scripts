// Q2.c
// The program is a roulette game that random numbers from 0-36 and the user tries to guess the random number
// Eilon Ashkenazi 23/05/2017
// ----------------------------------------------------------------- 


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function Decleration
bool exitClicked(char * input);
int checkInput(char * input);

void main()
{
	// Variable decleration
	char input[5]; // The user input 
	int credits = 100; // The amount of credits
	int randomNumber; // The random number
	srand(time(NULL));

	printf("Total Credits : %d \n", credits);
	printf("Enter a number between 0-36: \n");
	scanf("%s", &input);
	// the loop runs as long as not exit/quit clicked or the user has enough credits
	while (!(exitClicked(input)) && credits > 0)
	{
		
		randomNumber = (rand() % 37); // Random the numbers
		printf("Spinning the wheel...\n");
		printf("The random number is: %d\n", randomNumber);
		if (randomNumber == checkInput(input)) //  Checks the user input with the random number
		{
			printf("YOU WON!\n");
			credits += 36;
		}
		else
			credits -= 1;
		printf("Total Credits : %d \n", credits);
		printf("Enter a number between 0-36: \n");
		scanf("%s", &input);
	}
	if (credits == 0)
		printf("Game over, you are out of credits...");
	else // If credits are not 0, then exit or quit clicked
		printf("Exiting...");

}
// The function converts input from string to integer
int checkInput(char * input)
{
	int result = 0;
	sscanf(input, "%d", &result);
	return result;
}
// The function checks if exit or quit clicked
bool exitClicked(char * input)
{
	int resultExit;
	int resultQuit;
	bool finalResult = false;
	resultExit = strcmp(input, "exit");
	if (resultExit == 0)
		finalResult = true;
	resultQuit = strcmp(input, "quit");
	if (resultQuit == 0)
		finalResult = true;

	return finalResult;
}


