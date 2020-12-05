/* Content

    Problem 1 – Declare constant and variables

    Declare a constant for the speed of light and declare variables for mass and energy.


    Problem 2 – Get mass from user and calculate energy

    Add a line comment saying you're getting m and calculating and printing e.

    Write code to get a mass from the user.
    Assuming you declared your mass variable as a float named m, here's the code you'd use to get the mass from the user:

    printf("Enter mass of an object in kg: ");

    scanf("%f", &m);

    Calculate energy as mass times the speed of light squared.
    Use the appropriate function in math.h to square the speed of light
    and use whatever type casting is required to get the assignment statement to compile. Print out the value of energy with an appropriate label.


    Problem 3 – Think about what it all means

    The units for energy is J (Joules), which is equivalent to Watt Seconds (1 watt for 1 second).
    Think about how you could release that energy from the given object into a (more!!) useful form.
*/

#include <stdio.h>
#include <math.h>
#define SpeedOfLight 3 * pow(10,8)

int main()
{

    float Mass;
    float Energy;   // energy = mass * speed^2

    printf("Enter mass of object in KG: \n");
    scanf("%f", &Mass);

    Energy = Mass * pow(SpeedOfLight,2);
    printf("Energy: %.2f Joules", Energy);
    return 0;
}

/* Below is provided by Cousera professor
/*
 * File:   main.c
 * Author: Dr. T
 *

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define C 299792458

*
 * Calculates Einstein's energy equation
 *
int main(int argc, char** argv)
{
	float m;
	float e;

	// get mass and calculate energy
	printf("Enter mass in kg: ");
	scanf("%f", &m);
	e = m * powf(C, 2);
	printf("Energy: %f Joules\n", e);

	return (EXIT_SUCCESS);
}
*/
