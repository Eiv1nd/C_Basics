#include <stdio.h>
#include <stdlib.h> 	// exit()

// ------------ ###### ------------
// compile with gcc ProgramName.c -o ProgramName
// execute with ./ProgramName

// ------------ ------------ Functions ------------ ------------
// Hver funksjon har en return type (void hvis intenting returneres).
// Du kan ikke sette en funksjon lik en variabel.
// Du kan sette en variabel lik funksjonens return verdi eller adresse.
// Variabler som initialiseres i en funksjon må det allokeres minne til hvis
// den/de skal returneres
int addTwoInts(int num1, int num2)
{
	return num1 + num2;
}


// ------------ ------------ Relational operators ------------ ------------
// >, <, ==, >=, <=, != only compare values with the same data type
// To compare 2 unlike types perform a cast
// A relational operator always evaluates to 1 for true, or 0 for false
void Relational_Operators()
{
	int num1 = 1, num2 = 2;
	printf("Is 1 > 2 : %d\n",num1 > num2);
}


// ------------ ------------ Logical operators ------------ ------------
// Logical operators are used to combine the above relational
// && - And
// || - Or
// ! - Not - Not turns a 1 to 0 and vice versa. 
// (Surround relations with parentheses when using not)
// Computers are Logical they only understand 1s and 0s
void Logical_Operators()
{	
	printf("! turns a true into false : %d\n", !1);
}


/**
------------ ------------ bitwise / binary operators ------------ ------------
    | 	bit OR
    & 	bit AND
    ~ 	bit NOT
    ^ 	bit EXLUSIVE OR (XOR)
    <<	bit LEFT SHIFT
    >>	bit RIGHT SHIFT

------------ The OR operation truth table ------------
    0 | 0 = 0
    0 | 1 = 1
    1 | 0 = 1
    1 | 1 = 1
	0000 | 1111 = 1111

------------ The AND operation truth table ------------ 
    0 & 0 = 0
    0 & 1 = 0
    1 & 0 = 0
    1 & 1 = 1
	0x12 & 0x22 = 0x02

------------ XOR operation truth table: ------------
    0 ^ 0 = 0
    0 ^ 1 = 1
    1 ^ 0 = 1
    1 ^ 1 = 0
	1001 ^ 1101 = 0100

The NOT operator inverts the bit 1 becomes a 0 and a 0 becomes a 1.

------------ ~ Binary complement ------------
Flips every bit to the opposite bit:
	~1001 = 0110

------------ << Left shift ------------
Moves every bit left. (equals multiplying by 2)
	
	0101 << 1 = 1010
	0011 << 2 = 1100

------------ >> Right shift ------------
Moves every bit right. (divide by 2)
	
	0101 >> 1 = 0010
	1100 >> 2 = 0011

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define SETBITMASK(x,y) (x |= (y))
#define CLEARBITMASK(x,y) (x &= (~y))
#define FLIPBITMASK(x,y) (x ^= (y))
#define CHECKBITMASK(x,y) (x & (y))

#define VARFROMCOMB(x, y) x
#define BITFROMCOMB(x, y) y

#define C_SETBIT(comb) SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CLEARBIT(comb) CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_FLIPBIT(comb) FLIPBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CHECKBIT(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
*/


// ------------ ------------ Conditional operator ------------ ------------
// A great replacment for simple if statements
// (comparison) ? happensIfTrue : happensIfFalse;
void Conditional_Operator()
{	
	int custAge = 24;
	char* legalAge = (custAge > 21) ? "true" : "false";
	printf("Is the customer of legal age? %s\n", legalAge);

	int numOfProducts = 10;
	printf("I bought %s products\n",(numOfProducts > 1) ? "many" : "one"); // inside printf()
}

// ------------ ------------ if, else if, else statement ------------ ------------
void if_elseif_else()
{
	int num1 = 1, num2 = 2;
	if(num1 > num2) printf("%d is greater then %d\n", num1, num2);
	else if(num1 < num2) printf("%d is less then %d\n", num1, num2);
	else printf("%d is equal to %d\n", num1, num2);

	int custAge = 24;
	if(custAge > 21 && custAge < 35) printf("Access granted\n");
	else printf("Access denied\n");
}


// ------------ ------------ dowhile loop ------------ ------------
// Når noe må gjøres minst en gang, men du vet ikke hvor mange ganger.
void dowhile()
{	
	int whatToDo = 0;
	do{
	    printf("\n");
	    printf("1. What Time is It?\n");
	    printf("2. What is Todays Date?\n");
	    printf("3. What Day is It?\n");
	    printf("4. Quit\n");
	    scanf(" %d", &whatToDo);

	} while(whatToDo < 1 || whatToDo > 4);

	if(whatToDo == 1) printf("Print the time\n");
	else if(whatToDo == 2) printf("Print the date\n"); 
	else if(whatToDo == 3) printf("Print the day\n");
	else exit(0);
	// Exit the program with a non error state
	// Almost always better to use return
}

// ------------ ------------ for loop ------------ ------------
// Når du vet hvor mange ganger du må loope
// for(define incrementor; define condition; increment incrementor)
// Før c99 måtte int counter = 0 initialiseres utenfor for()
void for_loop()
{	
	for(int counter = 0; counter <= 20; counter++) printf("%d ", counter);
}


// ------------ ------------ break statement ------------ ------------
void Break()
{
	int secretNumber = 10, numberGuessed = 0;
	while(1){
		printf("Guess my secret number");
		scanf(" %d", &numberGuessed);
		if(numberGuessed == 10){
        	printf("You Got It");
			break;
		} 
	}
	// hopper hit etter break
}


// ------------ ------------ continue statement ------------ ------------
// continue brukes for å hoppe over over koden og
// fortsette på neste loop syklus og hopper over kode imellom.
void Continue()
{
	for(int counter = 0; counter <= 40; counter++)
	{
		if((counter % 2) == 0) continue;
		printf("%d ", counter);
	}
}

// ------------ ------------ switch statement ------------ ------------
// (Value must be char or int)
void Switch()
{
	int whatToDo = 2;
	switch(whatToDo)
	{ 
	    case(1) : printf("Print the time\n");
	    	break;
	    case(2) : printf("Print the date\n");
	        break;       
	    case(3) : printf("Print the day\n");
            break;            
	    default : printf("Bye Bye\n");
            exit(0);
	        break;
	}
}

void main()
{
	dowhile();
}
