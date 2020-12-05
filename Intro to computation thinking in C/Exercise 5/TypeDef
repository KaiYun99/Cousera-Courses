/* Content - my solution

Problem 1 – Define user-defined data type

Define a new data type that stores the GPS coordinates of a point. Specifically, include members for the latitude and longitude (in decimal degrees, not in degrees, minutes, and seconds).
Note: The "pieces" of the struct can be called fields or members. Field and member are interchangeable terms that mean the same thing.
Provide a typedef for your new type to make it easier to declare variables of that type.


Problem 2 – Declare and initialize variables

Declare a variable of your new data type to store the GPS coordinates of your current location and initialize it using curly brace initialization.
Declare another variable of your new data type to store the GPS coordinates of some location you'd like to visit and initialize it using direct assignment to each of the members.

Note:
I used float for my struct fields. For some compilers, when I assigned values to those fields I had to add f at the end of the floating point literals.
For example, the literal 1.23 is a }double, while the literal 1.23f is a float.


Problem 3 – Calculate and output latitude and longitude differences

Calculate and output the differences in both latitude and longitude between your current location and the location you'd like to visit.

*/
#include <stdio.h>


int main()
{
    typedef struct
    {
        float latitude;
        float longitude;
    } GPS;


    GPS GPS1 = {123.45f, 9875.43f}, GPS2;
    GPS2.latitude = 5789.21f;
    GPS2.longitude = 9999.99f;

    float lat, longg;
    lat = GPS1.latitude - GPS2.latitude;
    longg = GPS1.longitude - GPS2.longitude ;
    printf("Latitude diff: %.2f \nlongitude diff: %.2f \n",lat, longg);
    return 0;
}


/*
Dr. T solution
int main(int argc, char** argv)
{
	// Problem 1: Define type for GPS coordinates
	typedef struct GpsCoordinates GpsCoordinates;
	struct GpsCoordinates
	{
		float latitude;
		float longitude;
	};

	// Problem 2: Declare and initialize variables
	GpsCoordinates uccs = { 38.8936471f, -104.8003126f };
	GpsCoordinates london;
	london.latitude = 51.5073509f;
	london.longitude = -0.1277583f;

	// Problem 3: Print latitude and longitude differences
	// NOTE: Doing the subtraction in either order is fine.
	// My solution puts the place I want to visit first so I
	// can see how I'd have to change my latitude and longitude
	// to get from where I am to where I want to visit
	printf("Latitude needs to change by %f to get from UCCS to London\n",
		london.latitude - uccs.latitude);
	printf("Longitude needs to change by %f to get from UCCS to London\n",
		london.longitude - uccs.longitude);

	return (EXIT_SUCCESS);
}
*/
