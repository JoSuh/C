/* PROGRAM:	StudentRegistration.c
   AUTHOR:	Jo Suh
   DATE:	10/02/19
   TOPIC:	Program for creating and managing Student IDs and course codes.
		Asks and gets user inputs.
		This program implements a 2D array and methods.
		
*/




/*********************************************************************************************
	Declare include files
 *********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* String Library Function */
#include "helper.c"




/*********************************************************************************************
	Main
		- Asks for
			- number of students
			- number of courses
			- the course each student is taking
		- Asks what the user wants to do
		- Registers a student in a course
		- Withdraws a student from a course
		- Displays the registration table
		- Until user inputs exit
 *********************************************************************************************/
int main( void ) {
	/* need to specify type of void */

		/*--------------------*/

		/* all declarations had to come before any statements in a block */

		int userChoice;  /* set to a random number by default */
		
		int i, j; /* declare index to be used in for loops later*/

		int numberOfStudents, numberOfCourses, rowSize, columnSize, line, eachStudent;

		
		int studentIndex, courseIndex;
		char *selectedCode = (char *)malloc(7 * sizeof(char*));
		int selectedID;





		/*--------------------*/
		printf("\n\n\n::  Student Course handling program  ::\n");
		/*--------------------*/


    		
		/* Get number of Students */
		printf("\nEnter number of students: ");
		scanf( "%d", &numberOfStudents ); /* get an integer from user */

		int *studentIDs = (int *)malloc(numberOfStudents * sizeof(int));
		
		/* Get each student's ID
		Student IDs are 5-lengthed integers*/
		for (i=0 ; i < numberOfStudents ; i++ ){
			printf("  Enter student ID for student #%d: ", i+1);
			scanf("%d", &studentIDs[i]);
		}

		/*--------------------*/

		/* Get number of Courses */
		printf("\nEnter number of courses: ");
		scanf( "%d", &numberOfCourses ); /* get an integer from user */

   		char *courseCodes[numberOfCourses];

		for ( i = 0; i < numberOfCourses; i++){
			courseCodes[i] = (char *)malloc(sizeof(char));
			printf("  Enter course code #%d: ", i+1 );
        		scanf("%s", courseCodes[i]);
		}
		

		/*--------------------*/


		/* initialize 2D array */
		rowSize = numberOfStudents*numberOfCourses;
		columnSize = 3; /* Student ID index, course code index, enrolled value (0=no/1=yes) */

		/* Since initialized an arry here instead of at the top, need to compile with iso 99
			(gcc -g -o Assign1 Assign1.c -ansi -pedantic -Wall -std=c99) */
		int  registrationTable[rowSize][columnSize];

 		initilaize2DArray((int *)registrationTable, rowSize, columnSize);

		/* Set the correct values */
		line= 0;
		eachStudent = 0;
		while (line<rowSize){
			for (i = 0; i < numberOfCourses ; i++) {
				registrationTable[line][0] = eachStudent; /* Student ID index */
				registrationTable[line][1] = i; /* All courses are not enrolled by default */
				registrationTable[line][2] = 0; /* All courses are not enrolled by default */
				line++;			
			}
			eachStudent++;
		}
		







		/*------------------------------------------------------------------------------*/
		/*------------------------------------------------------------------------------*/
		/*------------------------------------------------------------------------------*/


		/* Menu */

		menu: while( userChoice!=4 ){
			/* Print menu options */
			printf("\n\n\n------------------ Main Menu ------------------\n");
			printf("1. Register a student in a course\n");
			printf("2. Withdraw a student from a course\n");
			printf("3. Display registration table\n");
			printf("4. Exit\n");
			
			printf("\nSelect an option: ");
			scanf( "%d", &userChoice ); /* get an integer from user */
			
			/* Execute according to the user input */
			switch(userChoice){
				/* ------------------------------------------------------- */
				case 1:	
					/* Register a student in a course */
					printf("\nEnter Student ID: ");
					scanf( "%d", &selectedID );


					printf("Enter Course code: ");


					/* fgets( selectedCode, 8, stdin); */
					scanf( "%8s", selectedCode );

					/* find which student ID is required */
					for ( i=0 ; i < numberOfStudents ; i ++ ){
						if ( studentIDs[i] == selectedID ){
							studentIndex = i;
							break;
						}
					}


					/* find which course code is required */
					for ( i=0 ; i < numberOfCourses ; i ++ ){


						int this = strcmp(courseCodes[i], selectedCode);
						printf("%d", this);
						if ( strcmp(courseCodes[i], selectedCode) == 0 ){
							courseIndex = i;
							break;
						}
					}

					i = (studentIndex*numberOfCourses)+(courseIndex);
					registrationTable[i][2] = 1;

					break;


				/* ------------------------------------------------------- */
				case 2:	
					/* Withdraw a student from a course */
					printf("\nEnter Student ID: ");
					scanf( "%d", &selectedID );
					printf("Enter Course code: ");
					scanf( "%s", selectedCode );

					/* find which student ID is required */
					for ( i=0 ; i < numberOfStudents ; i ++ ){
						if ( studentIDs[i] == selectedID ){
							studentIndex = i;
							break;
						}
					}

					/* find which course code is required */
					for ( i=0 ; i < numberOfCourses ; i ++ ){
						if ( strcmp(courseCodes[i], selectedCode) == 0 ){
							courseIndex = i;
							break;
						}
					}
					
					i = (studentIndex*numberOfCourses)+(courseIndex);
					/* i = (studentIndex+1)*(courseIndex+1) -1; */
					registrationTable[i][2] = 0;

					break;

				/* ------------------------------------------------------- */
				case 3:	
					/* Display registration table */
					/* Header */
					printf("\n\n  ---------------- Registration Table ----------------\n  Student ID  |");
					//print the course names
					for ( i = 0; i < numberOfCourses ; i++ ){
						printf("   %s    |", courseCodes[i]);
					}




					/* Body */
					/* print each student's values */
					for ( i = 0; i < numberOfStudents ; i++ ){
						/* Student ID */
						printf("     \n     %d  ", studentIDs[i]); 
						
						/* whether the student is enrolled or not */
						for ( j = 0; j < numberOfCourses ; j++ ){
							if ( !registrationTable[i*numberOfCourses + j][2] ){
								printf("        No    ");
							}else {
								printf("        Yes   ");    
							}
						}
					}
					break;


				/* ------------------------------------------------------- */
				case 4:	
					/* Exit */
					printf("\nExitting with exit code: q ...");
					break;


				/* ------------------------------------------------------- */
				default:
					/* Invalid input */
					printf("\nInvalid input");
					break;


				/* ------------------------------------------------------- */
			}
			goto menu;
			return EXIT_FAILURE;
		
		
	}
	printf("\nPrgram exitted with exit code: q\n\n\n\n");
	return EXIT_SUCCESS;
	return 0;
}
