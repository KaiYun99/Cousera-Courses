#include <stdio.h>
#include <ctype.h>
// #include <stdbool.h>  not sure how to use this //

int main()
{

    int number;
    printf("Please enter a number:\n");   // problem 1
    scanf("%d", &number);

    if (number > 0)
    {
        printf("It is a positive number\n");    //problem 2
    }
    else if ( number == 0)
    {
        printf("Number is Zero");
    }
    else
    {
        printf("It is a negative number\n");
    }

    // Problem 3 //

    printf("\nHello welcome, please select an option:\n");
    printf("\n");
    printf("N   New Game\n");
    printf("L   Load Game\n");
    printf("O   Options\n");
    printf("Q   Quit\n");
    printf("\n");

    char userchoice;
    int boo=0;

    scanf("\n%c",&userchoice);                  // Apparently there is a buffer here, not sure why //
    userchoice = toupper(userchoice);           // buffer usually occur when u change from requesting a number to char //
    while ( boo == 0)
    {
        printf("\n");
        switch ( userchoice )                           // However in line 33, i added a new line, not sure why buffer still remains //
        {
        // How do i use while ( true )

        case 'N' :                             // if never do line 39 , changing to upper , can stack cases like this , it acts like "Or" statement //
        // case 'n' :                        // or u can stack 2 cases like this for switch statements , both the cases will run the following code body//
        {
            printf("Loading New Game, please wait ...\n");
            //false;
            boo = 1;
            break;
        }
        case 'L' :
        {
            printf("Loading Saved Game, please wait...\n");
            //false;
            boo = 1;
            break;
        }
        case 'O' :
        {
            printf("What settings would u like to change\n");
            //false;
            boo = 1;
            break;
        }
        case 'Q' :
        {
            printf( "Quitting Game\n");
            //false;
            boo = 1;
            break;
        }
        default :
        {
            printf("Please enter a valid option:\n");
            printf("\n");
            printf("N   New Game\n");
            printf("L   Load Game\n");
            printf("O   Options\n");
            printf("Q   Quit\n");
            printf("\n");
            scanf("\n%c",&userchoice);                      // here also got buffer , if not will repeat this twice
            userchoice = toupper(userchoice);
            break;
        }
        }

    }
    return 0;
}

/*  Content
Problem 1 – Print positive message


Prompt for and read in an integer from the user.

Print a message if the number is positive (including 0).


Problem 2 – Print positive or negative message

Prompt for and read in an integer from the user.

Print one message if the number is positive (including 0) and a different message if the number is negative.

Problem 3 – Respond to menu choice

Output a menu of choices for the user. It should look like the following


N   NewGame
L   LoadGame
O   Options
Q   Quit

You should then prompt for and read in the user’s choice.

Your application should print an appropriate response confirming their choice, such as:

Loading game …

Your application should:

1.  Print the menu
2.  Prompt for and read in the user's choice
3.  Store the choice in an appropriate variable
4.  Using an if statement, determine which menu option the user selected, printing an appropriate message for the option selected
    (accept both upper and lower case characters for each choice)
5.  If the user enters something other than a menu option, print an appropriate message
*/

