#include <stdio.h> 				// printf(), scanf
#include <stdlib.h>
#include <string.h> 			// strcpy()
#include <stdbool.h>			// Include inkluderer koden fra header fil
#include <inttypes.h>
#define MYNAME "Ei71nD" 		// replace MYNAME with "Ei71nD"


// ------------ ------------ Datatypes ------------ ------------
void Datatypes()
{
	char firstletter = 'E';								// 1 byte, 256 possible chars
	int age = 22;										// 4 byte, -32,768 to 32,767
	long int bigNum = -32767000;						
	float piValue = 3.14159265359;						// The computer representation of a float is imprecise.
	double bigPiValue = 3.141592653589793238462643;		// store decimals as ints if u need precition.
	char myName[12] = "Ola Nordmann";					// String, array of chars
	size_t lenght = strlen(myName);
	size_t dataInFile;									// Unsigned int of able to hold large values
	
	// When you’re working with registers you need to know the size accurately
	// The C99 header inttypes.h adds numeric types with guaranteed sizes for ints.
	// For working with registers you usually want the unsigned versions

	uint8_t	un8;										// Unsigned 8bit integer
	uint16_t un16;										// Unsigned 16bit integer
	uint32_t un32;										// Unsigned 32bit integer
	int8_t n8;											// Signed 8bit integer
	int16_t n16;										// Signed 16bit integer
	int32_t n32;										// Signed 32bit integer
	
	// <stdbool.h> defines true as a constant for 1 and 0 a constant for false
	// _Bool is the C boolean type.
	_Bool isANumber;
	int number;
	int sumOfNumbers;


	// %d 	signed decimal int
	// %i 	signed int 	(ser på det som står foran 0x for hex, 0 for octal)
	// %ld 	long ints
	// %f 	floats and doubles
	// %c 	chars
	// %s 	strings
	// %zu 	size_t
	printf("Big Pi = %.20f\n", bigPiValue); // define the number of decimal places (-3.4*10^38 - 3.4*10^38)
	printf("Pi = %.5f\n", piValue);
	printf("My name is %s\n", myName);

	printf("Enter a number: ");
	isANumber = (scanf("%d", &number) == 1);
	
	while(isANumber)
	{
		sumOfNumbers = sumOfNumbers + number;	
		printf("Enter another number: ");
		isANumber = (scanf("%d", &number) == 1);
	}
	printf("The Sum is %d\n", sumOfNumbers);
}


void Datasize()
{	
	// How much space are data types taking up in bytes?
	printf("A char takes up %d bytes\n", sizeof(char));
	printf("An int takes up %i bytes\n", sizeof(int));
	printf("A long int takes up %d bytes\n", sizeof(long int));
	printf("A float takes up %d bytes\n", sizeof(float));
	printf("A double takes up %d bytes\n", sizeof(double));
	int bigInt = 2147483647;
	printf("The largest int is %d\n", bigInt);
}

// ------------ ------------ Casting ------------ ------------
// If you ever need to cast one data type to another just put (dataType) before it to cast
void Type_casting()
{
	int numberEx = 12;
	float numberEx2 = 1.234;
	int numberEx3 = numberEx / numberEx2;
	printf("%d\n", numberEx3);
	printf("numberEx / numberEx2 : %f\n", (float) numberEx3);
}

// ------------ ------------ Mathematics ------------ ------------
// Order of Operations
// 1.	Parentheses
// 2.	- Negative Sign, ! Not, ++ Increment, -- Decrement
// 3.	* Multiplication, / Division, % Modulus
// 4-	+ Addition, - Subtraction
// 		+, -, *, /, and % only with ints
void Mathematics()
{
	float decimal1 = 1.2, decimal2 = 1.5, decimalAns;
	printf("Float Calculation %f\n", decimal2 / decimal1);
	
	// Shortcut ways to perform calculations
	// +=, -=, *=, /=, %=, ++, --
	int tall = 1;
	printf("1 += 2 => %d\n", tall, tall += 2);  


	// ++ and -- work differently depending on where they are placed
	int exNum = 1;
	printf("++%d => %d\n", exNum, ++exNum);
	exNum = 1;
	printf("%d++ => %d\n", exNum, exNum++);
}


// returns largest possible number based on number of bits
int largestNumber(int numberOfBits)
{	
	if(numberOfBits == 1) return 1;
	int possible = 1; 
	for(int i = 1; i < numberOfBits; i++) possible *= 2; 
	return possible + largestNumber(numberOfBits - 1);
}

int main()
{
	int i = largestNumber(3);
	printf("%d\n", i);
	return 0;
}
