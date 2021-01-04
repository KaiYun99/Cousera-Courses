/* Content

Problem 1 – Read in scores from user
Create an array of size 5 and get that many valid (0-100) scores from the user.

Problem 2 – Find the min and max scores the user entered
Walk the array of scores to find the min and max scores in the array.
Print out the min and max scores.
Hint: You might find it helpful to assume that element 0 of the array is both the min score and the max score before you start walking the array

Problem 3 – Dynamically allocate the array

You’ll be using the code for this problem to replace some of the code you used to solve the previous problems.
Ask the user how many scores they want to enter.
Some C Complier doesn’t let you declare the array with a non-constant size (from the user input in this case), although other C compilers let you do that.
To dynamically create an array of the appropriate size, we’re going to need to use pointers. You can allocate an array of the appropriate size using the following code:

int * scores = malloc( n * sizeof(int));   malloc is to allocate memory

The code above assumes you want your array variable to be named scores and that n is the variable holding the size of the array that the user provided.
You’ll need to make one more change if you did the following in your for loops that walk the array:

for(int i=0 ; i<sizeof(scores) / sizeof(scores[0] ) ; i++ )    OR  for ( int i=0; i < n ; i++)

Although this a good approach to use for arrays in general, it won’t work when we treat the scores variable as a pointer. Instead, you should use the following for those for loops:
for(inti=0;i<n;i++)

*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>     // for INT_MIN INT_MAX
#include <stdlib.h>   // for mallocc
int main()
{
    // Problem 1
    int scores[5];
    for ( int i = 1 ; i < 6 ; i++)
    {
        printf("Input score (0-100) for result %d\n", i);
        scanf("%d", &scores[i-1]);
        while (scores[i-1] < 0 || scores[i-1]>100)                            //isalpha(scores[i-1]) ||
        {
            printf("Please input valid score (0-100) for result %d\n", i);
            scanf("%d", &scores[i-1]);
        }
    }

    //Problem 2
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for ( int i = 0 ; i < 5 ; i++)
    {
        if ( scores[i] < minimum )
        {
            minimum = scores[i];
        }
        if ( scores[i] >  maximum)
        {
            maximum = scores[i];
        }
    }
    printf("Minimum number = %d\n", minimum);
    printf("Maximum number = %d\n", maximum);

    //Problem 3     codeblock is able to
    int number;
    printf("How many elements in array: \n");
    scanf("%d", &number);
    int score_userdefinednumber[number];
    for ( int i = 1 ; i < number + 1; i++)
    {
        printf("Input score (0-100) for result %d\n", i);
        scanf("%d", &score_userdefinednumber[i-1]);
        while (score_userdefinednumber[i-1] < 0 || score_userdefinednumber[i-1]>100)                            //isalpha(scores[i-1]) ||
        {
            printf("Please input valid score (0-100) for result %d\n", i);
            scanf("%d", &score_userdefinednumber[i-1]);
        }
    }
    minimum = INT_MAX;
    maximum = INT_MIN;
    for ( int i = 0 ; i < number ; i++)
    {
        if ( score_userdefinednumber[i] < minimum )
        {
            minimum = score_userdefinednumber[i];
        }
        if ( score_userdefinednumber[i] >  maximum)
        {
            maximum = score_userdefinednumber[i];
        }
    }
    printf("Minimum number = %d\n", minimum);
    printf("Maximum number = %d\n", maximum);
    // some complier caannot but array[user defined || non constant value ]  -- so use pointer need manually assign memory but rest can normal array indexing
    int n;
    printf("How many elements in array: \n");
    scanf("%d", &n);
    int *scores_point = malloc( n * sizeof(int));
    for ( int i = 1 ; i < n + 1; i++)
    {
        printf("Input score (0-100) for result %d\n", i);
        scanf("%d", &scores_point[i-1]);
        while (scores_point[i-1] < 0 || scores_point[i-1]>100)                            //isalpha(scores[i-1]) ||
        {
            printf("Please input valid score (0-100) for result %d\n", i);
            scanf("%d", &scores_point[i-1]);
        }
    }
    minimum = INT_MAX;
    maximum = INT_MIN;
    for ( int i = 0 ; i < n  ; i++)
    {
        if ( scores_point[i] < minimum )
        {
            minimum = scores_point[i];
        }
        if ( scores_point[i] >  maximum)
        {
            maximum = scores_point[i];
        }
    }
    printf("Minimum number = %d\n", minimum);
    printf("Maximum number = %d\n", maximum);
    return 0;
}

