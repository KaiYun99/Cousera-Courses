/* Content
 * File:   main.c
 * Author: <Kai Yun>

 Assignment Description
 In this assignment, you'll add five cards to an array, process the array to determine how many cards of each suit you have, then print out that information.

Requirements
The code I’ve provided in the main.c file reads in the rank and suit of 5 different card.
Your code must call the getCard function 5 times and store the Card the function returns in an array variable.
Once you’ve filled up the array, you need to count how many cards of each suit are in the array and print that result.

The Card struct has two char fields named rank and suit. The rank field can have the following values: 2, 3, 4, 5, 6, 7, 8, 9, 0, J, Q, K, or A (0 means a 10).
The suit field can have the following values: C, D, H, or S (for clubs, diamonds, hearts, and spades).

Your solution must do the following:

·        Store the 5 cards in an array

·        Count the number of cards you have of each suit

·        Print the counts of each suit as described below

For example, if you have 1 club, 1 diamond, 0 hearts, and 3 spades in the array,
your output should be the following on a single line (be sure to include a newline at the end):
C 1 D 1 H 0 S 3

E.g. input output
2,C 3,D 4,S 0,S A,S

C 1 D 1 H 0 S 3

 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct Card Card;
struct Card
{
	int rank;
	int suit;
};

typedef struct LinkedList LinkedList;
struct LinkedList
{
	Card data;
	LinkedList *next;
};
LinkedList *head;
LinkedList *tail;

void buildLinkedListFromString(char string[]);
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	LinkedList *node);
LinkedList *getCardNode(char string[], int spaceIndex);
Card extractCardFromString(char string[], int length);
Card getCard();

/*
 * An Array of Cards Programming Assignment
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
		buildLinkedListFromString(input);

		// Add your code between this comment
		// and the comment below. You can of
		// course add more space between the
		// comments as needed
        int C , D , H , S ;
        C = 0;
        D = 0;
        H = 0;
        S = 0;
        //char set[5];
        for (int i = 0 ; i <5 ; i ++)
        {
            Card set = getCard();

            if ( set.suit == 'C')
            {
                C++;
            }
            if ( set.suit == 'D')
            {
                D++;
            }
            if ( set.suit == 'H')
            {
                H++;
            }
            if ( set.suit == 'S')
            {
                S++;
            }
        }

        printf("C %d D %d H %d S %d\n", C , D , H , S);


		// Don't add or modify any code below
		// this comment
		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}

/*
* Builds a linked list of cards from provided string
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
		LinkedList *node = getCardNode(stringStart, spaceIndex);
		addNodeToList(&head, &tail, node);

		// find next space in string
		string = &string[0] + spaceIndex + 1;
		result = strchr(string, ' ');
		stringStart = &string[0];
	}

	// add final node to list
	LinkedList *node = getCardNode(stringStart,
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
* Gets a node for a Card
*/
LinkedList *getCardNode(char string[], int length)
{
	// extract card from string
	Card value = extractCardFromString(string, length);

	// build and return node
	LinkedList *node;
	node = malloc(sizeof(struct LinkedList));
	node->data = value;
	node->next = NULL;
	return node;
}

/*
* Extracts a card struct from the given string
*
* We know the string format is always 3 characters
* long: r,s (rank,suit)
*/
Card extractCardFromString(char string[], int length)
{
	// extract card string from string
	char* cardString = malloc((length + 1) * sizeof(char));
	strncpy(cardString, string, length);
	cardString[length] = '\0';

	// build Card struct
	Card *cardInfo = malloc(sizeof(Card));
	cardInfo->rank = cardString[0];
	cardInfo->suit = cardString[2];

	// free memory and return card
	free(cardString);
	cardString = NULL;
	return *cardInfo;
}

/*
* Get a card from the linked list. If the linked
* list is null, the returned card has q values
* for both rank and suit
*/
Card getCard()
{
	// check for empty list
	Card value;
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
		Card *qCard = malloc(sizeof(Card));
		qCard->rank = 'Q';
		qCard->suit = 'Q';
		value = *qCard;
	}
	return value;
}
