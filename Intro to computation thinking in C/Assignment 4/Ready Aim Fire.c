/*
 * File:   main.c
 * Author: <Kai Yun>

 Assignment Description

 One of the earliest uses of computers was the calculation of ballistic trajectories.
 Imagine you’re trying to predict where a shell fired from a tank will land after following a parabolic trajectory.
 While you may not have taken physics, the equations are straightforward
 and you should be able to develop a solution that will accurately calculate the shell path given a launch angle and a starting shell speed.

 In this assignment, you'll calculate the maximum height the shell reaches and the distance in x the shell travels
 (which will be negative if the launch angle is greater than 90 degrees).

 Physics Equations

 theta // launch angle
 speed // initial speed
 G=9.81m/s ^2 // acceleration due to gravity
 vx = speed∗cos(theta) // x component of the velocity at start
 vy = speed∗sin(theta) // y component of the velocity at start
 t = vy /G // time until shell reaches apex (highest point)
 h = vy ^2 /(2 * G) // height of shell at apex (highest point)
 dx = vx * 2 * t // distance shell travels horizontally
 Using substitution, you should be able determine the distance the shell will rise and travel.

    Requirements

    Your solution must do the following:
    1.   WARNING: Convert theta from degrees to radians! If you don’t, the cosine and sine methods you use later won’t work properly.
    2.  Calculate vx using the <math.h> --> cosf function. For example:
    float vx = inputValues.speed * cosf(inputValues.theta);
    3.  Calculate vy using the <math.h> --> sinf function.
    4.  Calculate t
    5.  Calculate h
    6.  Calculate dx
    7.  Print the value of {h}h to 2 decimal places, a single space, and the value of dx
        to 2 decimal places on a single line

   You can assume that theta ranges from 5 to 175 degrees and speed will be no less than 5.

    For example, if theta is 45.0 and speed is 10.0, your output should be the following on a single line (be sure to include a newline at the end):
    2.55    10.19
    45.0    10.0
    5.0     5.0
    0.01    0.44
    q  (Program exits with q)
    
    ********************************** TEST CASE WRITE IN THE SAME LINE e.g. " 2.55 SPACE 10.19 " **************************************************
    it should give " 0.01 0.94 "
    
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define G 9.81
#define MAX_LENGTH 100

typedef struct Input Input;
struct Input
{
    float theta;
    float speed;
};

void getInputValuesFromString(char string[], Input *inputValues);

/*
 * Programming Assignment 3
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

        inputValues.theta *= ( M_PI / 180);

        float VelocityX, VelocityY;
        float time, height, HorizontalDist;

        VelocityX =inputValues.speed * cosf(inputValues.theta);
        VelocityY =inputValues.speed * sinf(inputValues.theta);

        time = VelocityY / G ;
        height = powf(VelocityY,2) / ( 2 * G );
        HorizontalDist = VelocityX * 2 * time;
        printf("%0.2f %0.2f\n", height, HorizontalDist);



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

    // extract theta from string
    char* thetaString = malloc((spaceIndex + 1) * sizeof(char));
    strncpy(thetaString, string, spaceIndex);
    thetaString[spaceIndex] = '\0';
    inputValues->theta = atof(thetaString);

    // extract speed from string
    string = &string[spaceIndex + 1];
    inputValues->speed = atof(string);

    // free memory
    free(thetaString);
    thetaString = NULL;
}
