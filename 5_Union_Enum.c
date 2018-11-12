#include <stdio.h>

// ------------ ------------ Unions ------------ ------------
// Unions allow to store diffrent datatypes in the same memory location.
typedef union
{
	short individual; 
	float pound;
	float ounce;
} Amount;

typedef struct
{
	char *name;
	Amount amount;	
} Product;

void print_union(Amount* amount)
{	
	// Output
	printf("Individual Oranges: %d\n", amount->individual);
	printf("Pounds of Oranges: %.2f\n", amount->pound);
	printf("Ounces of Oranges: %.2f\n", amount->ounce);
	// Get the location in memory
	// This location is the same as individual and ounce
	printf("Indiv Location: %p\n", &(amount->individual));
	printf("Pound Location: %p\n", &(amount->pound));
	printf("Ounces Location: %p\n", &(amount->ounce));
}


// ------------ ------------ Enums ------------ ------------
// An enum is used when you only will ever need
// a limited number of possible values.
void Enums(){

	// union
	Amount orange = {.ounce = 16};
	orange.individual = 4;
	
	typedef enum{ INDIV, OUNCE, POUND } quantity;
	quantity type = INDIV;
		
	if(type == INDIV) printf("You bought %d oranges\n\n", orange.individual);
	else if(type == OUNCE) printf("You bought %.2f ounces of oranges\n\n", orange.ounce);
	else printf("You bought %.2f pounds of oranges\n\n", orange.pound);
}


int main()
{
	// Assign union
	Amount orange = {.ounce = 16};
	print_union(&orange);									
	orange.individual = 4;
	print_union(&orange);

	// You can use Unions in Structs
	Product apple = {"Apple", .amount.ounce = 16};

	Enums();
	return 0;
}