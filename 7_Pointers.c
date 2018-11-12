#include <stdio.h>

/**
The Application's memory

Heap				Allocated at runtime
Stack				Decided when program starts
Global variables	Decided when program starts	
Code (text)			Decided when program starts

https://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_

**/


void Increment(int a)
{
	printf("Adress in Increment %d\n", &a);
	a = a + 1;
}

void pIncrement(int *a)
{	
	printf("Address in pIncrement %d\n", a);
	*a = (*a) + 1;
}

void Double(int A[], int size) // int* A
{
	int i, sum = 0;
	for(int i = 0; i < size; i++) A[i] = 2*A[i];
}


int main()
{

	// -------------------------------------------------------------------------------------------
	// Pointer types
	// -------------------------------------------------------------------------------------------

	// Pointer type define how pointer aritmethic and derefernceing is done
	// 1025 = 00000000 00000000 00000100 00000001

	int a = 1025;
	int *pi = &a;
	char* pc = (char*)pi;

	printf("Size %d\n", sizeof(int));
	printf("Address %d, Value %d\n", pi, *pi);
	printf("Address %d, Value %d\n", pi + 1, *(pi + 1));	// + 4 byte "random value"
	
	printf("Size %d\n", sizeof(char));
	printf("Address %d, Value %d\n", pc, *pc);
	printf("Address %d, Value %d\n", pc + 1, *(pc + 1));	// + 1 byte
	
	// void pointer (generic pointer type) (pointer aritmethic or derefernce cant be used)
	void* pv = pi;
	printf("Adress %d\n", pv);


	// -------------------------------------------------------------------------------------------
	// Pointers to pointers
	// -------------------------------------------------------------------------------------------
	int x = 5;
	int* p = &x;
	int** q = &p;
	int*** r = &q;
	*p = 6;

	printf("%d\n", *p);		// 6
	printf("%d\n", **q);	// 6
	printf("%d\n", ***r);	// 6
	printf("%d\n", *q);		// Address of x
	printf("%d\n", **r);	// Address of x
	
	***r = 10;
	printf("%d\n", x);		// 10
	**q = *p + 2;
	printf("%d\n", x);		// 12


	// -------------------------------------------------------------------------------------------
	// Pointers and arrays (Diffrent types used in similar manner)
	// -------------------------------------------------------------------------------------------

	int Primes[] = {2, 3, 5, 7, 13, 17, 19, 23};

	// Address		&A[i] or (A+i)
	// Value 		A[i] or *(A+i)

	int i;
	for(i = 0; i < 8; i++);
	{
		printf("At index %d\n", i);
		printf("Address %d\n", &Primes[i]);
		printf("Address %d\n", Primes + i);		// Skip 4 bytes to next integer for each i
		printf("Value %d\n", Primes[i]);
		printf("Value %d\n\n", *(Primes + i));
	}

	// Strings
	char A[12] = "Hello";							// array (automatisk 0)
	char B[12] = {'H', 'e', 'l', 'l', 'o', '\0'};	// array
	char C[] = "Hello";								// array (automatisk 0)
	char *D = "Hallo";								// array, stored in text/code segment (Cannot be modified)
	char* pA;										// pointer
	
	pA = A;			
	pA[1] = 'a';
	A[1] = 'e';

	// Read and write works the same way, here are the diffrences
	// A = pA; error
	// A++;	error
	// pA++;	ok

	char *students[4] = {"Sally", "Mark", "Paul", "Sue"};
	for(int i = 0; i < 4; i++)
	{
		printf("%s : %d\n", students[i], &students[i]);
	}

	// -------------------------------------------------------------------------------------------
	// Pointers as function arguments
	// -------------------------------------------------------------------------------------------
	a = 11;
	printf("Address %d\n", &a);
	Increment(a);		// By value (receives a copy, therefore modifies another variable)
	printf("Value after Increment %d\n", a);
	pIncrement(&a);		// By reference (receives the adress of variable to be modifed)
	printf("Value after pIncrement %d\n", a);


	// -------------------------------------------------------------------------------------------
	// Arrays as function arguments
	// -------------------------------------------------------------------------------------------
	int Array[] = {1, 2, 3, 4, 5, 6};
	Double(Array, 6);
	for(int i = 0; i < 6; i++) printf("%d\n", Array[i]);

	// -------------------------------------------------------------------------------------------
	// Multidimentional arrays
	// -------------------------------------------------------------------------------------------
	
	// Address	&A[i][j]	or	A[i]+j 		or 	*(twodim+i)+j
	// Value 	A[i][j]		or	*(A[i] + j)	or	*(*(A+i) + j)

	int j;
	int twodim[][3] = {{1, 2, 3}, {4, 5, 6}};
	// int* p = twodim // error
	int (*pp)[3] = twodim;
	
	for(i = 0; i<3; i++)
		for(j = 0; j<3; j++)
		{
			printf("Index %d %d\n", i, j);
			printf("Address %d %d %d\n", &twodim[i][j], twodim[i] + j, *(twodim+i)+j);
			printf("Value %d %d %d\n\n", twodim[i][j], *(twodim[i] + j), *(*(twodim+i) + j));
		}
}