/* Content
 * File:   main.c
 * Author: <Kai Yun>

    Assignment Description

    You’ve decided that Chemistry is an awesome field to explore.
    Since we recently celebrated the 150th anniversary of Mendeleev’s periodic table of the elements,
    you decide to go look at the (current) periodic table of the elements.
    You’re so excited by the beauty and elegance of that arrangement
    that you decide to print out the symbols for the first 10 elements in the periodic table of the elements.

    Requirements
    Your solution must do the following:
    1.  Print the symbol for each of the first 10 elements of the periodic table, with each symbol appearing on its own line in the output
    2.  Do NOT print anything else in your output; if you do, you’ll confuse the automated grader and you’ll get a bad grade!

    Here are the first 3 lines of required output (you’ll have 10 lines of output):
    H
    He
    Li
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

/*
 * Programming Assignment 1
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

        printf("H\n");
        printf("He\n");
        printf("Li\n");
        printf("Be\n");
        printf("B\n");
        printf("C\n");
        printf("N\n");
        printf("O\n");
        printf("F\n");
        printf("Ne\n");
        // Don't add or modify any code below
        // this comment
        fgets(input, MAX_LENGTH, stdin);
    }

    return 0;
}
