/*
 * File:   main.c
 * Author: <Kai Yun>

 Assignment Description
 You’re really excited about the differences between the int and float data types,
 and you want to explore those differences some more.
 For this programming assignment, you’ll calculate the sum and average of 3 integers.

 Requirements
 The code I’ve provided in the main.c file reads in 3 integers and stores them in a variable named inputValues,
 which is an Input struct. The Input struct has 3 integer fields
 named num1, num2, and num3. Your sum and average calculations must use those integer fields.

 Your solution must do the following:
 1. Calculate the sum of the 3 integers
 2. Calculate the average of the 3 integers
 3. Print the sum, a single space, and the average to 2 decimal places on a single line

 For example, if the 3 integers are 1, 2, and 2, your output should be the following on a single line (be sure to include a newline at the end) :
 1 2 2
 5 1.67
 
 2 2 2
 6 2.00
 
 q  (Program exits with q)
 
 ********************************** TEST CASE WRITE IN THE SAME LINE e.g. " 1 SPACE 2 SPACE 2 " **************************************************
   it should give " 5 1.67 "
 
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct Input Input;
struct Input
{
    int num1;
    int num2;
    int num3;
};

void getInputValuesFromString(char string[], Input *inputValues);

/*
 * Programming Assignment 2
 */
int main(int argc, char** argv)
{
    // IMPORTANT: Only add code in the section
    // indicated below. The code I've provided
    // makes your solution work with the
    // automated grader on Coursera
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);
    while (input[0] != 'q')
    {
        Input inputValues;
        getInputValuesFromString(input, &inputValues);

        // Add your code between this comment
        // and the comment below. You can of
        // course add more space between the
        // comments as needed
        
        float sum,avg;
        sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
        avg = sum / 3;
        printf("%.0f %.2f\n",sum,avg);
        
        // Don't add or modify any code below
        // this comment
        fgets(input, MAX_LENGTH, stdin);
    }

    return 0;
}

/*
* Extracts input values from provided string
*/
void getInputValuesFromString(char string[], Input *inputValues)
{
    // find first space index
    int spaceIndex = -1;
    char *result = NULL;
    result = strchr(string, ' ');
    char *stringStart = &string[0];
    spaceIndex = result - stringStart;

    // extract first number from string
    char* firstNumberString = malloc((spaceIndex + 1) * sizeof(char));
    strncpy(firstNumberString, string, spaceIndex);
    firstNumberString[spaceIndex] = '\0';
    inputValues->num1 = atoi(firstNumberString);

    // find second space index
    string = &string[0] + spaceIndex + 1;
    result = strchr(string, ' ');
    stringStart = &string[0];
    spaceIndex = result - stringStart;

    // extract second number from string
    char* secondNumberString = malloc((spaceIndex + 1) * sizeof(char));
    strncpy(secondNumberString, string, spaceIndex);
    secondNumberString[spaceIndex] = '\0';
    inputValues->num2 = atoi(secondNumberString);

    // extract third number from string
    string = &string[spaceIndex + 1];
    inputValues->num3 = atoi(string);

    // free memory
    free(firstNumberString);
    firstNumberString = NULL;
    free(secondNumberString);
    secondNumberString = NULL;
}
