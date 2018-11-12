#include <stdio.h>
#include <stdlib.h>


// malloc() allocates memory during runtime on the heap.
// This is usefull if you want to declare a variable inside
// a funtion to return it.
// When malloc() is called you pass it the amount of memory required and
// it returns the address to that memory that you can refer to using 
// a pointer. If the space couldn't be found null is returned.


int main()
{
	int amtOfNumbersToStore;
	printf("How many numbers do you want to store: ");
	scanf("%d", &amtOfNumbersToStore);
	
	int * pRandomNumbers;
	pRandomNumbers = (int *) malloc(amtOfNumbersToStore * sizeof(int));
	
	// Check if memory was located by malloc
	if(pRandomNumbers != NULL)
	{
		int i = 0;
		printf("Enter a Number or Quit: ");
		while(i < amtOfNumbersToStore && scanf("%d", &pRandomNumbers[i]) == 1)
		{	
				printf("Enter a Number or Quit: ");
				i++;	
		}	

		printf("\nYou entered the following numbers\n");
		for(int j = 0; j < i; j++) printf("%d\n", pRandomNumbers[j]);
	
	}
	
	// "Give back" memory to the OS which is not needed
	free(pRandomNumbers);
	
	return 0;
}