/* PROGRAM:  PhoneNumberPrinter.c 
   AUTHOR:   Jo Suh
   DATE:     09/15/19
   TOPIC:    Accept correct input of phone number and formats them
*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include <stdio.h>
#include <string.h> //include the String Library Function
#include <ctype.h> //for chekcing variable types


/*
strlen: String length
strcpy: STring copy
strcmp: String compare
strcat: String concatenation
sprintf: String print
*/



/**************************************************************************
 * Main
 **************************************************************************/
int main( void ) {
	//need to specify type of void

	char phoneNumber[100];
	//C doesn't have a String, so to hold the input values, create an array of chars to hold the 'string'
	

	int quit = 0; //Since C doesn't have booleans, set false to 0

	while (quit==00){
		printf("Enter phone number, or 0 to exit\n");

		//scanf: scans the input according to the format provided
		scanf("%s", phoneNumber);

		
		//check for correct length
		if (strlen(phoneNumber) != 7){
			//if invalid length, check if user wants to quit
			if ( phoneNumber[0] == '0'){
				//if both strings are identical
				printf("quit signal received\n");
				break;
			}
			printf("The number entered is not 7-digits long\n");
			continue;
		}
	
		//check if every char is a number
		for (int i=0; i<7; i++){
			if (!isdigit(phoneNumber[i])){
				printf("Invalid phone number\n");
				continue;
			}
		}
		
		//check if the first digit is in the correct range
		if ( (phoneNumber[0]-'0') < 2 ){
			//subtract  nothing to use the value as an integer
			//cannot be 0, or 1
			printf("Invalid phone number\n");
			continue;
		}

		//If make it to here, then the number is correctly formatted
		printf("The formatted phone number is: %c%c%c - %c%c%c%c\n",
			phoneNumber[0],
			phoneNumber[1],
			phoneNumber[2],
			phoneNumber[3],
			phoneNumber[4],
			phoneNumber[5],
			phoneNumber[6]
		);
				
	}
	printf("Program ended with exit code: 0\n");
		
}


