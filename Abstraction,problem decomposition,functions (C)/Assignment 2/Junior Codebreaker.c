/* Content
 * File:   main.c
 * Author: <Kai Yun>

 Assignment Description
 In this assignment, you'll be developing an application that takes a string of 99 characters or fewer
 Count how many times each of the alphabetic characters appears.
 Case(upper/lower) doesn't matter for the counts
 So the string aAa should yield a count of 3 for the letter A.
 Finally, the program should print, for each character that appears at least once in the phrase, the character and the count for that character.

 Requirements

 Your solution must do the following:

·        Count how many times each alphabetic character appears in the phrase, ignoring case (so A and a both add to the count of As)

·        For each character that appears at least once in the string, print the character and the count for that character. You should have one space between each character count output, with all the character counts on a single line

For example, for the string aAaBbZ, your output should be the following on a single line (be sure to include a newline at the end):

A3 B2 Z1

 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/*
 * Junior Codebreaker Programming Assignment
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
        // Add your code between this comment
        // and the comment below. You can of
        // course add more space between the
        // comments as needed
        int length = strlen(input);
        char temp[2];
        int count;
        char currentalpha;

        char newinput[length + 1];
        for ( int i =0 ; i < length ; i++)      // to convert all to upper //
        {
            newinput[i] = toupper(input[i]);
            //printf("%c\n", newinput[i]);
        }
        newinput[length] = '\0';


        for ( int i = 0 ; i < 26 ; i++ )  // loop through A to Z //
        {

            count = 0;
            currentalpha = 'A' + i;
            //printf("%c\n", currentalpha);

            for ( int j = 0 ; j < length ; j++)     // loop through 1st index to the last index //
            {

                //temp[0] = newinput[j] ;
                //printf("%c\n", temp[0]);
                if ( newinput[j] == currentalpha )    // if the index is same as the letter
                {
                    count++;
                }
            }
            if ( count > 0 )
            {
                printf("%c%d ", currentalpha, count);
            }

        }
        printf("\n");

        // Don't add or modify any code below
        // this comment
        fgets(input, MAX_LENGTH, stdin);
    }

    return 0;
}
