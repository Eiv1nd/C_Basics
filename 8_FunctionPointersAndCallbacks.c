#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// int* func(int, int);		// declaring a function that would return int*
// int (*func)(int, int);	// declaring a function pointer

int Add(int a, int b)
{
	return a+b;
}

int compare(const void* a, const void* b)	// const - cannot modify adress
{
	int A = *((int*)a);	// casting to int and getting value
	int B = *((int*)b);
	return abs(A) - abs(B);
}

int main()
{

	int c;
	int (*p)(int, int);
	p = &Add;			// Add or &Add will also return a function pointer
	c = (*p)(2, 3);		// Dereferenceing and executing (*p)p(2, 3) or p(2, 3)

	// -------------------------------------------------------------
	
	// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
	int i, A[] = {7, 3, 21, 2, 49, 17};
	qsort(A, 6, sizeof(int), compare);
	for(i = 0; i < 6; i++) printf("%d ", A[i]);
}