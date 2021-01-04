/*  Content
 * File:   main.c
 * Author: <Kai Yun>

Assignment Description

You want to develop a program that takes in as many positive integers as the user wants to enter and then tells them how many integers they entered and the mean (average) of those numbers.
This will also give you more practice implementing while loops!
In this assignment, you'll get integer numbers until you get a -1,
at which point you’ll print how many numbers you processed (not including the -1) and the mean of those numbers (not including the -1).

Requirements

The code I’ve provided in the main.c file reads in a set of integers that ends with -1. Your code must call the \tt{getNumber}getNumber function and store the \tt{int}int the function returns in a variable, then process that number as appropriate.
Your solution must do the following:

·        Print the count of the numbers you processed (not including the -1)
·        Print a space
·        Print the mean of the numbers you processed (not including the -1) to 2 decimal places
·        Print a newline character

For example, if the set of numbers you process is 1 2 3 4 -1, your output should be the following on a single line (be sure to include a newline at the end)    :

4 2.50

We’d typically label our output to tell the user what the output means, but that will just confuse the automated grader. You must print ONLY the values described above in your output, with the values appearing on a single line with a single space between them.

Note: For the special case when -1 is the first number, your mean should be set to 0.00.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct LinkedList LinkedList;
struct LinkedList
{
	int data;
	LinkedList *next;
};
LinkedList *head;
LinkedList *tail;

void buildLinkedListFromString(char string[]);
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	LinkedList *node);
LinkedList *getNode(char string[], int length);
int getNumber();

/*
 * When Will They Stop Programming Assignment
 */
int main(int argc, char** argv)
{
	// IMPORTANT: Only add code in the section
	// indicated below. The code I've provided
	// makes your solution work with the
	// automated grader on Coursera
	char input[MAX_LENGTH];
	fgets(input, MAX_LENGTH, stdin);
	while (input[0] != 'q')             // q to stop the prog
	{
		buildLinkedListFromString(input);

		// Add your code between this comment
		// and the comment below. You can of
		// course add more space between the
		// comments as needed

        int count;
        float average,total;
        int number;
        number = getNumber();


        while ( number != -1 )
        {
            count +=1;
            total += number;
            number = getNumber();
        }
        if (count == 0)
        {
            printf("0 0.00");
        }
        else
        {
            average = total / count;
            printf("%d %.2f", count ,average);
            total = 0;   // to reset variables after each line//
            average = 0;
            count = 0;
        }
        printf ("\n");

		// Don't add or modify any code below
		// this comment
		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}

/*
* Builds a linked list of input values from provided string
*/
void buildLinkedListFromString(char string[])
{
	// find first space in string
	int spaceIndex = -1;
	char *result = NULL;
	result = strchr(string, ' ');
	char *stringStart = &string[0];

	// loop while there are more spaces in string
	while (result != NULL)
	{
		spaceIndex = result - stringStart;

		// build new node and add to list
		LinkedList *node = getNode(stringStart, spaceIndex);
		addNodeToList(&head, &tail, node);

		// find next space in string
		string = &string[0] + spaceIndex + 1;
		result = strchr(string, ' ');
		stringStart = &string[0];
	}

	// add final node to list
	LinkedList *node = getNode(stringStart,
		strlen(stringStart));
	addNodeToList(&head, &tail, node);
}

/*
* Adds a node to the linked list
*/
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	LinkedList *node)
{
	// add node to linked list
	if (*headPointer == NULL)
	{
		// adding to empty list
		*headPointer = node;
	}
	else
	{
		// add to end of list
		(*tailPointer)->next = node;
	}
	*tailPointer = node;
}

/*
* Gets a node for the linked list
*/
LinkedList *getNode(char string[], int length)
{
	// extract int from string
	char* intString = malloc((length + 1) * sizeof(char));
	strncpy(intString, string, length);
	intString[length] = '\0';
	int value = atoi(intString);

	// free memory
	free(intString);
	intString = NULL;

	// build and return node
	LinkedList *node;
	node = malloc(sizeof(struct LinkedList));
	node->data = value;
	node->next = NULL;
	return node;
}

/*
* Get a number from the linked list. If the linked
* list is empty, returns -1
*/
int getNumber()
{
	// check for empty list
	int value;
	if (head != NULL)
	{
		// save value at front of list
		value = head->data;

		// move along list
		LinkedList *temp = head;
		head = head->next;
		free(temp);
	}
	else
	{
		// empty list
		value = -1;
	}
	return value;
}
