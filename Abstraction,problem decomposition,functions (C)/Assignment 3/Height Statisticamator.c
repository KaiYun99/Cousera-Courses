/*
 * File:   main.c
 * Author: <Kai Yun>

Assignment Description

implement a variety of functions to decompose a large programming problem into smaller sub-problems.
Here's the large problem:
Get how many heights you need to process (1 to 100),
then get that many heights (in inches, 1 to 96).
Calculate the average height and find the minimum and maximum heights in the set of heights.
Print out the average height, the minimum height, and the maximum height.


Functions

The function prototypes for the functions you're required to implement for this solution are provided below.
Don't combine the functions or write more functions than I've provided; I want you to use exactly these functions.

int getValidInteger(int lowerBound,int upperBound)

The getValidInteger function gets a valid integer between the lower bound and the upper bound.
If it gets a number that’s not between lower bound and upper bound inclusive, it keeps getting another number until it gets a valid one.

float averageIntegerArray(int values[],int count);

The averageIntegerArray function averages the first count integers in the values array

int findExtremeInIntegerArray(int minOrMax,int values[], int count);

The findExtremeInIntegerArray function finds either the minimum or maximum value in the first count integers in the values array.
The minOrMax parameter tells whether the function should be looking for the minimum or the maximum

For e.g.
for the three heights of 69, 70, and 71, your output should be the following on a single line (be sure to include a newline at the end):

70.00 69 71


 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

#define MIN 0
#define MAX 1

typedef struct LinkedList LinkedList;
struct LinkedList
{
    int data;
    LinkedList *next;
};
LinkedList *head;
LinkedList *tail;

// prototypes for student-implemented functions
int getValidInteger(int lowerBound, int upperBound);
float averageIntegerArray(int values[], int count);
int findExtremeInIntegerArray(int minOrMax, int values[], int count);

// prototypes for Dr. T functions
void buildLinkedListFromString(char string[]);
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
                   LinkedList *node);
LinkedList *getNode(char string[], int spaceIndex);
int getNumber();

/*
 * Height Statisticamator Programming Assignment
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
        int min = 0;
        int max = 1;

        int NoOfHeight;
        NoOfHeight = getValidInteger( 1 , 100);
        int arrray[NoOfHeight];


        for ( int i = 0 ; i < NoOfHeight ; i++)
        {
            arrray[i] = getValidInteger( 1 , 96 );

        }
        /*printf("%.2f %d %d", averageIntegerArray(arrray[NoOfHeight], NoOfHeight) , findExtremeInIntegerArray( min , arrray[NoOfHeight] , NoOfHeight )
               , findExtremeInIntegerArray ( max , arrray[NoOfHeight] , NoOfHeight ) );  */
        printf("%.2f ", averageIntegerArray(arrray , NoOfHeight));
        printf("%d ", findExtremeInIntegerArray ( min , arrray , NoOfHeight ) );
        printf("%d\n", findExtremeInIntegerArray ( max , arrray , NoOfHeight ));

        // Don't add or modify any code below
        // this comment except as indicated below
        fgets(input, MAX_LENGTH, stdin);
    }

    return 0;
}

// Add your function implementations between this
// comment and the comment below. You can of course
// add more space between the comments as needed

int getValidInteger(int lowerBound, int upperBound)
{
    int Number;

    Number = getNumber();

    while ( Number < lowerBound || Number > upperBound )
    {
        Number = getNumber();
    }
    return Number;
}

float averageIntegerArray(int values[], int count)
{
    float total = 0;

    float average = 0;

    for ( int i =0 ; i < count ; i++)
    {

        total += values[i];

    }

    average = (float) total / count ;
    return average;
}
int findExtremeInIntegerArray(int minOrMax, int values[], int count)
{
    int lowest = 999;
    int highest = -999;
    if  ( minOrMax == 0 )    //min
    {
        for (int i =0 ; i < count ; i ++)
        {
            if ( values[i] < lowest)
            {
                lowest = values[i];
            }
        }
        return lowest;
    }
    if ( minOrMax == 1 )    // max
    {
        for ( int i =0 ; i < count ; i++ )
        {
            if (values[i]> highest)
            {
                highest = values[i];
            }
        }
        return highest;
    }
    return 0;
}


// Don't add or modify any code below this comment

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
