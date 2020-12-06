/* Content

Problem Convert between temperatures

Declare three float variables for this program:
one variable for the original temperature in Fahrenheit,
one variable for the calculated temperature in Celsius, and
one variable for the calculated temperature in Fahrenheit (when you convert from Celsius back to Fahrenheit). Be sure to name your variables appropriately.

Write code to get the original temperature in Fahrenheit from the user. Assuming you declared your first variable as a float named originalFahrenheit, here's the code you'd use to get the original temperature from the user:

printf("Enter temperature (Fahrenheit): ");
scanf("%f", &originalFahrenheit);
The scanf function is used to read keyboard input.
We provide a format specifier as the first argument to indicate the data type we're reading in.
For the second argument we provide the name of the variable we want to put the result into preceded by &.
The &, called the address of operator, provides the address of the variable in memory.
The scanf function needs the address of the variable, not just its name, because of the internal implementation of that function. Don't forget the &

Write code to calculate the temperature in Celsius, store the result in your calculated Celsius variable,
and display the calculated Celsius temperature to the user. The equation for converting Fahrenheit to Celsius is:

Celsius temperature = (Fahrenheit temperature - 32) / 9 * 5

Write code to calculate the temperature in Fahrenheit, store the result in your calculated Fahrenheit variable (NOT your original Fahrenheit variable),
and display the calculated Fahrenheit temperature to the user. The equation for converting Celsius to Fahrenheit  is:

Fahrenheit temperature = Celsius temperature * 9 / 5 + 32

Test your code with the following values for Fahrenheit: 0, 32, 212

*/

#include <stdio.h>

int main()
{
    float TempF; //fahrenheit
    float TempC ;
    float FinalF;

    printf("Enter temperature (Fahrenheit): ");
    scanf("%f", &TempF);

    TempC = (TempF -32) / 9*5;
    printf("Temp in Celsius: %.2f\n", TempC);


    FinalF = TempC *9 / 5 +32;
    printf("Temp in Fahrenheit: %.2f\n",FinalF);
}
