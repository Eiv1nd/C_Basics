#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Linked list er bedre en arrays fordi den er dynamisk.
// Structen må inneholde en peker til neste struct. 
// (Recursive Structure)

struct product
{
	char name[30];
	int price;
	struct product *next;
};

	
struct product *pFirst = NULL;
struct product *pLast = NULL;

void inputData()
{	
	struct product* aProduct = (struct product *) malloc(sizeof(struct product));
	
	printf("Enter the name of the product:");
	scanf("%s",&(aProduct)->name);
	
	printf("Enter the price of the product:");
	scanf("%d",&(aProduct)->price);
	
	aProduct->next = NULL;
	
	if (pFirst == NULL){
		pFirst = aProduct;
		pLast = aProduct;
		
	}else{
		pLast->next = aProduct;
		pLast = aProduct;
	}
}


void outputData(struct product* pForste)
{
	struct product *curProd = pForste;
	while (curProd != NULL)
	{
		// (*). and -> is equal syntax
		printf("The name is %s and the price is %d\n", (*curProd).name, curProd->price);
		// hopper til neste struct i lista
		curProd = curProd->next;
	}
}


// returnerer minneadressen til produktet
struct product* searchForProduct(char *productName)
{
	struct product *pIterator = pFirst;
	while (pIterator != NULL) {
		// Sammenligner første 30 chars og returnere 0 hvis de er like
		int areEqual = strncmp(pIterator->name, productName, 30);
		if (!areEqual) {
			return pIterator;
		}
		pIterator = pIterator->next;
	}
	printf("%s wasn't found\n", productName);
	return NULL;
}


// Returns last item in the linked list
struct product* finnSiste(struct product* pForste)
{
	struct product *pTemp = pForste;
	while(pTemp->next != NULL) {
		pTemp = pTemp->next;
	}
	return pTemp;
}


int main()
{
	// ------------ Linked list by assigning everything
	printf("First linked list\n");
	printf("------------------------\n");
	struct product tomato = {"Tomato", .51, NULL};
	struct product potato = {"Potato", 1.21, NULL};
	struct product lemon = {"Lemon", 1.69, NULL};
	struct product milk = {"Milk", 3.09, NULL};
	struct product turkey = {"Turkey", 1.86, NULL};
	// Now assign a pointer to the value of next
	tomato.next = &potato;
	potato.next = &lemon;
	lemon.next = &milk;
	milk.next = &turkey;
	// Put in a new struct
	struct product apple = {"Apple", 1.58, NULL};
	// and update the pointer/next values
	lemon.next = &apple;
	apple.next = &milk;
	outputData(&tomato);
	printf("------------------------\n\n");		
	// ------------------------ ------------------------


	// ------------ Linked list made with inputData() function
	printf("Second linked list\n");
	printf("------------------------\n");
	inputData();
	inputData();
	inputData();
	outputData(pFirst);
	printf("------------------------\n\n");
	// ------------------------ ------------------------	


	// ------------ Find last element in both structs
	printf("Name of last element is: %s\n", finnSiste(&tomato)->name);
	printf("Name of last element is: %s\n", finnSiste(pFirst));

	return 0;
}