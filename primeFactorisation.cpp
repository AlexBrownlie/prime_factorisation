// Prime Factorisation .cpp : Defines the entry point for the console application.
//

#include <list>
#include <math.h>

#include "../headers/primeFactorisation.h"

/*Initialise the function for prime factorisation, taking an unsigned long long int as a parameter and returning a list of unsigned long long ints*/
std::list<unsigned long long int> primeFactorisation(unsigned long long int value)
{
	/*Initialising list to store the found prime factors*/
	std::list<unsigned long long int> factors;

	/*Whilst 'value' has a factor of 2, complete the following statements. This is done separately to any other factor as 2 is the only even prime number and once it has been checked, no other even number needs to be checked as it cannot be a factor. This is an optimisation from before and essentially halved my run time, despite actually being an extra few lines of code.*/
	while ( (value % 2) == 0 )
	{

		/*if the value is equal to 0, break from the while loop as 0 does not have any prime factors and would cause an infinite loop */
		if (value==0)
		{
			break;
		}

		/*Add the number 2 to the list of prime factors and divide the value by 2*/
		factors.push_back(2);
		value = value/2;
	}

	/*Initialise the variable 'i' to have a value of 3*/
	int i = 3;

	/*While 'value' is greater than integer 'i' squared*/
	while ( value >= pow(i,2) )
	{
		/*If the value MOD i is equal to 0 (meaning value/i gives a whole number) */
		if ( (value%i) == 0 )
		{
			/*Add the integer value 'i' to the list of prime factors and divide the current value by the integer 'i' */
			factors.push_back(i);
			value = value  / i;
		}
		
		/*If 'i' is not a prime factor, then increase it by 2 to the next odd number. (No more even numbers need to be checked)*/
		else
		{
			i+=2;
		}

	}

	/*If the remaining value is greater than 2, add 'value' to the list of prime factors*/
	if (value > 2)
	{
		factors.push_back(value);
	}

	/*Return the list of prime factors*/
	return factors;
}

